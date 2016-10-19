#include <stack>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

struct state {
  int id;
  unordered_map<int, unordered_set<int> > moves;
} ;

NFA::NFA() {
  startStates = {};
  finalStates = {};
  inputs = {};
  totalStates = -1;
  states = {};
}

NFA::NFA(unordered_set<T> startStates, unordered_set<T> finalStates,
       set<T> inputs, int totalStates, unordered_map<int, State> states) {
  this.startStates = startStates;
  this.finalStates = finalStates;
  this.inputs = inputs;
  this.totalStates = totalStates;
  this.states = states;
}

template <typename T>
unordered_set<T> NFA<T>::eClosure(unordered_set<State> states) {
  stack<State> s;
  unordered_set<int> estates;
  for (State itr = states.begin(); itr != states.end(); ++itr) {
    s.push(itr);
    estates.insert(itr.id);
  }

  while (!s.empty()) {
    State* top = s.top();
    unordered_set<int>* emoves = top->moves['E'];
    for (auto itr = emoves.begin(); itr != emoves.end(); ++itr) {
      if (estates.count(itr) == 0) {
        estates.insert(itr);
        s.push(this.states[itr]);
      }
    }
    s.pop();
  }
}

template <typename T>
unordered_set<T> NFA<T>::move(unordered_set<State> states, T input) {
  unordered_set<State> result = {};
  for (auto itr = states.begin(); itr != states.end(); ++itr) {
    unordered_set<T> *temp = itr.moves[input];
    for (auto itr1 = temp.begin(); itr1 != temp.end(); ++itr) {
      result.insert(this.states[itr1]);
    }
  }
  printf(result);
  return result;
}
