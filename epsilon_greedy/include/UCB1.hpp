#ifndef UCB1_HPP
#define UCB1_HPP

struct UCB1{
  int win_count;
  int call_count;
  double calc(const int&)const;
  void update_count(bool);
};

#endif
