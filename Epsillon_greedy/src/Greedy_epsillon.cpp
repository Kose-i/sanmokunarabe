#include "Greedy_epsillon.hpp"

#include <cmath>
#include <limits>
#include <iostream>//test


double Greedy_epsillon::calc()const {
  if (call_count == 0) return std::numeric_limits<double>::max();
  return (sum_reward/ call_count);
}

void Greedy_epsillon::update_count(const double& reward) {
  ++call_count;
  sum_reward += reward;
}
