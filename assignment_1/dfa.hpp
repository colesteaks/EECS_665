#include "dfa.h"

#include <stack>

using namespace std;

struct dState {
  bool marked;
  unordered_set<int> nStates;
  unordered_map<T, T> moves;
};

DFA::DFA() {

}

void DFA::subset() {
  while (this.unmarked) {
    for (auto state = this.states.begin(); state != this.states.end(); ++state) {
      if (!state->second->marked) {
        state->second->marked = true;
        printf("Mark %s", state->first);
        for (auto input = this.inputs.begin(); input != this.inputs.end(); ++input) {
          printf("%s ")
        }
      }
    }
  }
}
