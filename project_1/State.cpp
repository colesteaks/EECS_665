#include "State.h"
using namespace std;

State::State() {
  this->moves = {};
}

State::~State() {}

State::State(unordered_map<char, unordered_set<int> > moves) {
  this->moves = moves;
}
