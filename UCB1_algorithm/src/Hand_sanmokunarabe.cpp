#include "Hand_sanmokunarabe.hpp"

#include <limits>
#include <vector>

Hand_sanmokunarabe::Hand_sanmokunarabe():hand_nine(9){};

int Hand_sanmokunarabe::select_pos()const{
  int max_pos = 0;
  int max_param = std::numeric_limits<double>::min();
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
  return max_pos;
};

void Hand_sanmokunarabe::set_win(const int& num) {
  ++hand_nine[num].win_count;
  ++hand_nine[num].call_count;
}

void Hand_sanmokunarabe::set_lose(const int& num) {
  ++hand_nine[num].call_count;
}
