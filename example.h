#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <vector>

class Sack {
 public:
  int N,W;
  int * values;
  int * weight;
  int ** table;
  Sack(int n,int w, std::vector<int> val,std::vector<int> wei);
  ~Sack();
  void display_Sack() const;
  void construct_table();
  void pick_items();

};

#endif
