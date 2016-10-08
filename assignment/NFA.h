#ifndef NFA_H
#define NFA_H

#include "State.h"
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <fstream>

class NFA {
public:
    NFA();
    NFA(std::unordered_set<State*> startStates, std::unordered_set<State*> finalStates,
           std::set<char> inputs, int totalStates, std::unordered_map<int, State*> states);
    ~NFA();
    std::unordered_set<State*> startStates;
    std::unordered_set<State*> finalStates;
    std::set<char> inputs;
    int totalStates;
    std::unordered_map<int,State*> states;
    std::unordered_set<int> eClosure(std::unordered_set<State*> set);
    std::unordered_set<int> move(std::unordered_set<int> states, char input);
};

#endif
