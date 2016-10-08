#ifndef DFA_H
#define DFA_H

#include "DState.h"
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class DFA {
public:
    DFA();
    ~DFA();
    std::unordered_set<DState*> startStates;
    std::unordered_set<DState*> finalStates;
    std::set<char> inputs;
    int totalStates;
    std::unordered_map<int,DState*> states;
    int checkDFA(std::unordered_set<int> set);
    DState* addState(std::unordered_set<int> nstates);
    bool isFinal(DState* state, std::unordered_set<int> nfinals);
};

#endif
