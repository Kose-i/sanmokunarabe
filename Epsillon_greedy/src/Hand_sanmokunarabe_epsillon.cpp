#include "Hand_sanmokunarabe_epsillon.hpp"

#include "Greedy_epsillon.hpp"

#include <limits>
#include <vector>

#include <iostream>//test

Hand_sanmokunarabe_epsillon::Hand_sanmokunarabe_epsillon():hand_nine(9){};

int Hand_sanmokunarabe_epsillon::select_pos()const{
  if (random.rand() < thread_epsillon) {
    int random_select {};//0~9 random
    return random_select;
  }
  int max_pos = 0;
  double max_param = std::numeric_limits<double>::min();

  for (auto i = 0;i < 9;++i) {
    double tmp_calc = hand_nine[i].calc();
    if (max_param < tmp_calc) {
      max_pos = i;
      max_param = tmp_calc;
    }
  }
  std::cout << "max_pos:" << max_pos << " max_param:" << max_param << '\n';
  return max_pos;
};

void Hand_sanmokunarabe_epsillon::set_win(const int& num) {
  hand_nine[num].update_count(10);
}

void Hand_sanmokunarabe_epsillon::set_lose(const int& num) {
  hand_nine[num].update_count(0);
}
