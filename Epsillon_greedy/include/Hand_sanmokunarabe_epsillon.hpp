#ifndef Hand_hpp
#define Hand_hpp

#include "UCB1_epsillon.hpp"

#include <vector>

class Hand_sanmokunarabe_epsillon{
  private:
    std::vector<UCB1_epsillon> hand_nine;
  public:
    Hand_sanmokunarabe_epsillon();
    int select_pos()const;
    void set_win(const int&);
    void set_lose(const int&);

};

#endif
