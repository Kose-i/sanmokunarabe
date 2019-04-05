#include "Hand_sanmokunarabe_epsillon.hpp"

#include <limits>
#include <vector>

#include <iostream>//test

Hand_sanmokunarabe_epsillon::Hand_sanmokunarabe_epsillon():hand_nine(9){};

int Hand_sanmokunarabe_epsillon::select_pos()const{
  int max_pos = 0;
  double max_param = std::numeric_limits<double>::min();
  int sum_trial_count {};
  for (auto i = 0;i < 9;++i) {
    sum_trial_count += hand_nine[i].call_count;
  }

  for (auto i = 0;i < 9;++i) {
    double tmp_calc = hand_nine[i].calc(sum_trial_count);
    if (max_param < tmp_calc) {
      max_pos = i;
      max_param = tmp_calc;
    }
  }
  std::cout << "max_pos:" << max_pos << " max_param:" << max_param << '\n';
  return max_pos;
};

void Hand_sanmokunarabe_epsillon::set_win(const int& num) {
  ++hand_nine[num].win_count;
  ++hand_nine[num].call_count;
}

void Hand_sanmokunarabe_epsillon::set_lose(const int& num) {
  ++hand_nine[num].call_count;
}
