#include "UCB1_epsillon.hpp"

#include <cmath>
#include <limits>
#include <iostream>//test

double UCB1_epsillon::calc(const int& trial_count)const {
  double ans = (this->win_count + std::sqrt((2*std::log(trial_count))/this->call_count));
  if (call_count == 0) ans = std::numeric_limits<double>::max();
  std::cout << "UCB1_epsillon::calc(" << trial_count << ") = " << ans << '\n';
  if (this->call_count == 0) return std::numeric_limits<double>::max();
  return (this->win_count/this->call_count + std::sqrt((2*std::log(trial_count))/this->call_count));
}

void UCB1_epsillon::update_count(bool win_check) {
  ++call_count;
  if (win_check == true) {
    ++win_count;
  }
}
