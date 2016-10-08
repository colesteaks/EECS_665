#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <unordered_set>

#include "NFA.h"
#include "State.h"
#include "DFA.h"

using namespace std;

/************************
*HELPER FUNCTIONS
************************/
string chopString(string str, char start, char stop) {
  int start_pos = int(str.find(start));
  string temp = str.substr(start_pos+1);
  int stop_pos = int(temp.find(stop));
  string result = temp.substr(0, stop_pos);
  return result;
}

template <typename T>
void printSet(unordered_set<T> set) {
  cout << "{ ";
  for (auto itr = set.begin(); itr != set.end(); ++itr) {
    if(next(itr) == set.end()) {
      cout << *itr;
    } else {
      cout << *itr << ",";
    }
  }
  cout << "}";
}

void printState(State* s) {
  for (auto itr = s->moves.begin(); itr != s->moves.end(); ++itr) {
    cout << itr->first << ": ";
    printSet(itr->second);
  }
  cout << endl;
}

void printIntMap(unordered_map<int, State*> map) {
  for (auto itr = map.begin(); itr != map.end(); ++itr) {
    cout << itr->first << ": ";
    printState(itr->second);
  }
}

template <typename T>
unordered_set<T> intToState(unordered_set<int> ints, unordered_map<int, T> states) {
  unordered_set<T> set;
  for(auto itr = ints.begin(); itr != ints.end(); ++itr) {
    int index = *itr;
    set.insert(states[index]);
  }
  return set;
}

template <typename T>
unordered_set<int> stateToInt(unordered_set<T> states) {
  unordered_set<int> set;
  for(auto itr = states.begin(); itr != states.end(); ++itr) {
    T index = *itr;
    set.insert(index->id);
  }
  return set;
}


//TODO need to split strings on commas, not by character.
unordered_set<int> makeIntSet(string str) {
  unordered_set<int> set;
  istringstream iss(str);
  char word;
  while (iss >> word) {
    if(word!=',') {
      cout << word << ", ";
      int item = word - '0';
      cout << item << endl;
      set.insert(item);
    }
  }
  return set;
}

set<char> makeInputSet(string str) {
  set<char> set;
  istringstream iss(str);
  string word;
  iss >> word;
  char input;
  while (iss >> input) {
    set.insert(input);
  }
  return set;
}

template <typename T>
void printStates(unordered_map<int, T> states, set<char> inputs) {
  cout << "State\t";
  for (auto inp = inputs.begin(); inp != inputs.end(); ++inp) {
    char input = *inp;
    cout << input << "\t";
  }
  cout << endl;
  for (auto sta = states.begin(); sta != states.end(); ++sta) {
    int id = sta->first;
    cout << id << "\t";
    T sec = sta->second;
    for (auto inp = inputs.begin(); inp != inputs.end(); ++inp) {
      char input = *inp;
      unordered_set<int> prin = sec->moves[input];

      cout << "\t";
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[]) {
  NFA* nfa = new NFA();
  ifstream infile;
  infile.open(argv[1]);

  string line;

  //initial state
  getline(infile, line);
  string initial = chopString(line, '{', '}');
  unordered_set<int> is = makeIntSet(initial);

  //final states
  getline(infile, line);
  string finals = chopString(line, '{', '}');
  unordered_set<int> fs = makeIntSet(finals);

  //total states
  getline(infile, line);
  string total = chopString(line, ':', '\n');
  istringstream (total) >> nfa->totalStates;

  //inputs
  getline(infile, line);
  nfa->inputs = makeInputSet(line);

  //populate NFA states
  while (infile.good()) {
    unordered_map<char, unordered_set<int> > m;
    int key;

    getline(infile, line);
    istringstream iss(line);
    iss >> key;

    for (auto itr = nfa->inputs.rbegin(); itr != nfa->inputs.rend(); ++itr) {
      string s, chopped;
      iss >> s;
      chopped = chopString(s, '{', '}');
      //cout << chopped << endl;
      unordered_set<int> set = makeIntSet(chopped);
      m[*itr]=set;
    }
    State* st = new State();
    st->id = key;
    st->moves = m;
    nfa->states[key] = st;
  }
  printIntMap(nfa->states);
  nfa->startStates = intToState(is, nfa->states);
  nfa->finalStates = intToState(fs, nfa->states);

  DFA* dfa = new DFA();
  set<char> in = nfa->inputs;
  set<char>::iterator er = in.find('E');
  in.erase(er);
  dfa->inputs = in;

  //use a stack to store unmarked DStates and pop as they are marked.
  stack<DState*> dstates;
  DState* first = new DState();
  first->nStates = nfa->eClosure(nfa->startStates);
  first->id = dfa->states.size() +1;
  dfa->states[first->id] = first;
  dstates.push(first);
  while (!dstates.empty()) {
    DState* ds = dstates.top();
    dstates.pop();

    //check if this state contains a final state from the NFA.
    unordered_set<int> nfinals = stateToInt(nfa->finalStates);
    if (dfa->isFinal(ds, nfinals)) {
      dfa->finalStates.insert(ds);
    }

    cout << "Mark " << ds->id << endl;

    //this is where the DFA is created, according to figure 3.32 in the text.
    for(auto itr = dfa->inputs.begin(); itr != dfa->inputs.end(); ++itr) {
      char input = *itr;
      unordered_set<int> mset = nfa->move(ds->nStates, input);
      unordered_set<int> u = nfa->eClosure(intToState(mset, nfa->states));
      printSet(ds->nStates);
      cout << "--" << input << "-->";
      printSet(mset);
      cout << endl;
      DState* us = dfa->addState(u);
      int check = dfa->checkDFA(u);
      if(check==-1) {
        dfa->states[us->id] = us;
        dstates.push(us);
        ds->moves[input] = unordered_set<int> {us->id};
      }
      ds->moves[input] = unordered_set<int> {check};
      cout << "E-closure";
      printSet(mset);
      cout << " = ";
      printSet(u);
      cout << " = ";
      printSet(ds->moves[input]);
      cout << endl;
    }
    cout << endl;
  }
  cout << "Initial State: ";
  printSet(stateToInt(dfa->startStates));
  cout << endl;
  cout << "Final States: ";
  printSet(stateToInt(dfa->finalStates));
  cout << endl;
  printStates(dfa->states, dfa->inputs);

  //TODO: make a general function to print out state list for NFA and DFA.
  return 0;
}
