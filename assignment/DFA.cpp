#import "DFA.h"

using namespace std;

DFA::DFA() {
  this->startStates = {};
  this->finalStates = {};
  this->inputs = {};
  this->totalStates = -1;
  this->states = {};
}

DFA::~DFA() {}

int DFA::checkDFA(unordered_set<int> set) {
  int id;
  for(auto itr = this->states.begin(); itr != this->states.end(); ++itr) {
    unordered_set<int> test = itr->second->nStates;
    unordered_set<int> diff;
    std::set_difference(set.begin(), set.end(), test.begin(), test.end(),std::inserter(diff, diff.begin()));
    cout << "set is in DFA: " << diff.empty() << endl;
    if(diff.empty()) {
      return itr->first;
    }
  }
  return -1;
}

DState* DFA::addState(unordered_set<int> nstates) {
  DState* ds = new DState();
  ds->nStates = nstates;
  ds->id = this->states.size() +1;
  return ds;
}

// int DFA::findState(unordered_set<int> nstates) {
//   for (auto state = this->states.begin(); state != this->states.end(); ++state) {
//     DState* test = *state;
//   }
// }

bool DFA::isFinal(DState* state, unordered_set<int> nfinals) {
  for (auto ns = state->nStates.begin(); ns != state->nStates.end(); ++state) {
    int sfind = *ns;
    if(nfinals.find(sfind) !=state->nStates.end()) {
      return true;
    }
  }
  return false;
}
