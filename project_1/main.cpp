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
#include <queue>

#include "NFA.h"
#include "State.h"
#include "DFA.h"
#include "DState.h"

using namespace std;

/************************
*HELPER FUNCTIONS
************************/

//divides a string based on start and stop characters
string chopString(string str, char start, char stop) {
  int start_pos = int(str.find(start));
  string temp = str.substr(start_pos+1);
  int stop_pos = int(temp.find(stop));
  string result = temp.substr(0, stop_pos);
  return result;
}

//prints a set
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

//converts a set of ints to a set of states.(either DState or State)
template <typename T>
unordered_set<T> intToState(unordered_set<int> ints, unordered_map<int, T> states) {
  unordered_set<T> set;
  for(auto itr = ints.begin(); itr != ints.end(); ++itr) {
    int index = *itr;
    set.insert(states[index]);
  }
  return set;
}

//converts a set of ints to a set of states (either DState or State).
template <typename T>
unordered_set<int> stateToInt(unordered_set<T> states) {
  unordered_set<int> set;
  for(auto itr = states.begin(); itr != states.end(); ++itr) {
    T index = *itr;
    set.insert(index->id);
  }
  return set;
}


//Makes a set of ints from a string of comma separated ints
unordered_set<int> makeIntSet(string str) {
  unordered_set<int> set;
  istringstream iss(str);
  int word;
  while (iss >> word) {
    set.insert(word);
    if(iss.peek() == ',') {
      iss.ignore();
    }
  }
  return set;
}

//makes input set from the 3rd line in the input file
vector<char> makeInputSet(string str) {
  vector<char> set;
  istringstream iss(str);
  string word;
  iss >> word;
  char input;
  int i = 0;
  while (iss >> input) {
    set.push_back(input);
  }
  return set;
}

//prints DFA formatted output detailing states.
template <typename T>
void printStates(unordered_map<int, T> states, vector<char> inputs) {
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
      printSet(prin);
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

    for (auto itr = nfa->inputs.begin(); itr != nfa->inputs.end(); ++itr) {

      string s, chopped;
      iss >> s;
      chopped = chopString(s, '{', '}');


      unordered_set<int> set = makeIntSet(chopped);
      m[*itr]=set;
    }
    State* st = new State();
    st->id = key;
    st->moves = m;
    nfa->states[key] = st;
  }

  nfa->startStates = intToState(is, nfa->states);
  nfa->finalStates = intToState(fs, nfa->states);

  DFA* dfa = new DFA();
  vector<char> in;
  in = nfa->inputs;
  in.erase(remove(in.begin(), in.end(), 'E'), in.end());
  dfa->inputs = in;

  //use a queue to store unmarked DStates and pop as they are marked.
  queue<DState*> dstates;
  DState* first = new DState();
  unordered_set<int> t1 = nfa->eClosure(nfa->startStates);
  first->nStates = t1;
  first->id = dfa->states.size() +1;
  dfa->states[first->id] = first;
  dfa->startStates.insert(first);
  dstates.push(first);
  while (!dstates.empty()) {
    DState* ds = dstates.front();
    dstates.pop();

    //check if this state contains a final state from the NFA.
    for (auto it = nfa->finalStates.begin(); it !=nfa->finalStates.end(); ++it) {
      State* s = *it;
    }
    unordered_set<int> nfinals = stateToInt(nfa->finalStates);
    if (dfa->isFinal(ds->nStates, nfinals)) {
      dfa->finalStates.insert(ds);
    }

    cout << "Mark " << ds->id << endl;

    //this is where the DFA is created, according to figure 3.32 in the text.
    for(auto itr = dfa->inputs.begin(); itr != dfa->inputs.end(); ++itr) {
      char input = *itr;
      unordered_set<int> mset = nfa->move(ds->nStates, input);
      if (!mset.empty()) {
        unordered_set<State*> t2 = intToState(mset, nfa->states);
        unordered_set<int> u = nfa->eClosure(t2);
        printSet(ds->nStates);
        cout << "--" << input << "-->";
        printSet(mset);
        cout << endl;

        int check = dfa->checkDFA(u);

        if(check==-1) {
          DState* us = new DState();
          us->nStates = u;
          us->id = dfa->states.size() +1;
          dfa->states[us->id] = us;
          dstates.push(us);
          unordered_set<int> tmp;
          tmp.insert(us->id);
          ds->moves[input] =  tmp;
        } else {
          unordered_set<int> tmp;
          tmp.insert(check);
          ds->moves[input] =  tmp;
        }

        cout << "E-closure";
        printSet(mset);
        cout << " = ";
        printSet(u);
        cout << " = ";
        printSet(ds->moves[input]);
        cout << endl;
      }
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

  return 0;
}
