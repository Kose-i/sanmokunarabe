#ifndef Hand_hpp
#define Hand_hpp

#include "UCB1.hpp"

#include <vector>

class Hand_sanmokunarabe{
  private:
    std::vector<UCB1> hand_nine;
  public:
    Hand_sanmokunarabe();
    int select_pos()const;
    void set_win(const int&);
    void set_lose(const int&);

};

#endif
