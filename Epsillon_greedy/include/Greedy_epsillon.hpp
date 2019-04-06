#ifndef Greedy_epsillon_HPP
#define Greedy_epsillon_HPP

struct Greedy_epsillon{
  double sum_reward;
  int call_count;
  double calc()const;
  void update_count(const double&);
};

#endif
