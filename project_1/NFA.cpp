#include "NFA.h"
using namespace std;

NFA::NFA() {
  this->startStates = {};
  this->finalStates = {};
  this->inputs = {};
  this->totalStates = -1;
  this->states = {};
}

NFA::~NFA() {}

NFA::NFA(unordered_set<State*> startStates, unordered_set<State*> finalStates,
       vector<char> inputs, int totalStates, unordered_map<int, State*> states) {
  this->startStates = startStates;
  this->finalStates = finalStates;
  this->inputs = inputs;
  this->totalStates = totalStates;
  this->states = states;
}


//eclosure function as described in the book.
unordered_set<int> NFA::eClosure(unordered_set<State*> states) {
  stack<State*> s;
  unordered_set<int> estates;
  for (auto itr = states.begin(); itr != states.end(); ++itr) {
    State* st = *itr;
    s.push(st);
    estates.insert(st->id);
  }

  while (!s.empty()) {
    State* top = s.top();
    s.pop();
    unordered_set<int> emoves = top->moves['E'];
    for (auto itr = emoves.begin(); itr != emoves.end(); ++itr) {
      int check = *itr;
      if (estates.count(check) == 0) {
        estates.insert(check);
        s.push(this->states[check]);
      }
    }
  }
  return estates;
}

//determines a set of possible moves from a given set of states to a given input. 
unordered_set<int> NFA::move(unordered_set<int> states, char input) {
  unordered_set<int> result;
  for (auto itr = states.begin(); itr != states.end(); ++itr) {
    State* st = this->states[*itr];
    unordered_set<int> temp = st->moves[input];
    for (auto mov = temp.begin(); mov != temp.end(); ++mov) {
      int m = *mov;
      result.insert(m);
    }
  }
  return result;
}
