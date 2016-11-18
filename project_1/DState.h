#ifndef DSTATE_H
#define DSTATE_H

#include <unordered_map>
#include <unordered_set>
#include <string>

class DState {
public:
  DState();
  ~DState();
  int id;
  bool marked;
  std::unordered_map<char,std::unordered_set<int> > moves;
  std::unordered_set<int> nStates;
};

#endif
