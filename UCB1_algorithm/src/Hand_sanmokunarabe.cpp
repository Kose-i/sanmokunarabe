#include "Hand_sanmokunarabe.hpp"

#include <limits>
#include <vector>

Hand_sanmokunarabe::Hand_sanmokunarabe():hand_nine(9){};

int Hand_sanmokunarabe::select_pos()const{
  int max_pos = 0;
  int max_param = std::numeric_limits<double>::min();
  for (auto i = 0;i < 9;++i) {
    double tmp_calc = hand_nine[i].calc(4);//TODO
    if (max_param < tmp_calc) {
      max_pos = i;
      max_param = tmp_calc;
    }
  }
  return max_pos;
};
