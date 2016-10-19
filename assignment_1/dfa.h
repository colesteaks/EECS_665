#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

template <typename T>
class DFA {

  public:
    DFA();
    ~DFA();
    std::unordered_set<T> startStates;
    std::unordered_set<T> finalStates;
    std::set<T> inputs;
    std::unordered_map<T,T> states;

    void subset(std::unordered_set<T> set);
};
#include "dfa.hpp"
#endif
