#ifndef Hand_hpp
#define Hand_hpp

#include "Greedy_epsillon.hpp"

#include <vector>

class Hand_sanmokunarabe_epsillon{
  private:
    std::vector<Greedy_epsillon> hand_nine;
    const double thread_epsillon = 0.3;//TODO 逐次的に変更する
  public:
    Hand_sanmokunarabe_epsillon();
    int select_pos()const;
    void set_win(const int&);
    void set_lose(const int&);

};

#endif
