#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <unordered_set>

class State {
public:
  State();
  State(std::unordered_map<char, std::unordered_set<int> > moves);
  ~State();
  int id;
  std::unordered_map<char, std::unordered_set<int> > moves;
};

#endif
