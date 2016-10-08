#include "DFA.h"

using namespace std;

DFA::DFA() {
  this->startStates = {};
  this->finalStates = {};
  this->inputs = {};
  this->totalStates = -1;
  this->states = {};
}

DFA::~DFA() {}

//Checks to see if a set of NFA states is already in the DFA asa state
int DFA::checkDFA(unordered_set<int> set) {
  int id;
  for(auto itr = this->states.begin(); itr != this->states.end(); ++itr) {
    unordered_set<int> test = itr->second->nStates;
    unordered_set<int> diff;
    std::set_difference(set.begin(), set.end(), test.begin(), test.end(),std::inserter(diff, diff.begin()));
    if(diff.empty()) {
      return itr->first;
    }
  }
  return -1;
}

//checks to see if the DState should be included in final states.
bool DFA::isFinal(unordered_set<int> dstates, unordered_set<int> nfinals) {
  for (auto ns = dstates.begin(); ns != dstates.end(); ++ns) {
    int sfind = *ns;
    if(nfinals.find(sfind) != nfinals.end()) {
      return true;
    }
  }
  return false;
}
