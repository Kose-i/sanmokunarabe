#include "Hand_sanmokunarabe.hpp"

#include <climits>
#include <vector>

Hand_sanmokunarabe::Hand_sanmokunarabe():hand_nine(9){};

int Hand_sanmokunarabe::select_pos()const{
  int max_pos = 0;
  int max_param = std::limits<double>.min();
  for (auto i = 0;i < 9;++i) {
    hand_nine[i].calc();
    if (max_param < hand_nine[i].calc()) {
      max_pos = i;
      max_param = hand_nine[i].calc();
    }
  }
  return max_pos;
};
