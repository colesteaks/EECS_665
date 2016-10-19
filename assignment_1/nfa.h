#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

class NFA {
    public:
        NFA();
        ~NFA();
        std::unordered_set<State> startStates;
        std::unordered_set<State> finalStates;
        std::set<string> inputs;
        int totalStates;
        std::unordered_map<int,State> states;
        std::unordered_set<T> eClosure(std::unordered_set<T> set);
        std::unordered_set<T> move(std::unordered_set<T> states, T input);
};
#include "nfa.hpp"
#endif
