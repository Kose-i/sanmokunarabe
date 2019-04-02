#include "UCB1.hpp"
#include <cmath>

double UCB1::calc(const int& trial_count)const {
  return (this->win_count + std::sqrt((2*std::log(trial_count))/this->call_count));
}

void UCB1::update_count(bool win_check) {
  ++call_count;
  if (win_check == true) {
    ++win_count;
  }
}
