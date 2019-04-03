#ifndef Computer_sanmokunarabe_hpp
#define Computer_sanmokunarabe_hpp

#include "Hand_sanmokunarabe.hpp"

#include <map>
#include <string>

class Computer_sanmokunarabe{
  private:
    std::map<int, Hand_sanmokunarabe> hand_box;
  public:
    static int make_hash_from_board(const std::string&);
    int select_pos(const int&);
    void study();
};
#endif
