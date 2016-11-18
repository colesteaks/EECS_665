#ifndef DFA_H
#define DFA_H

#include "DState.h"
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>

class DFA {
public:
    DFA();
    ~DFA();
    std::unordered_set<DState*> startStates;
    std::unordered_set<DState*> finalStates;
    std::vector<char> inputs;
    int totalStates;
    std::unordered_map<int,DState*> states;
    int checkDFA(std::unordered_set<int> set);
    bool isFinal(std::unordered_set<int> dstates, std::unordered_set<int> nfinals);
};

#endif
