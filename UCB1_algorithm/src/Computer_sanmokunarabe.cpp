#ifndef Computer_sanmokunarabe_hpp
#define Computer_sanmokunarabe_hpp

#include "Hand_sanmokunarabe.hpp"

#include <map>
#include <string>

class Computer_sanmokunarabe{
  private:
    std::map<int, Hand_sanmokunarabe> tmp;
  public:
    int select_pos(const int&);
    void study();
    static int make_hash_from_board(const std::string&);
};
#endif

int Computer_sanmokunarabe::select_pos(const int&) {//hashを受け取る
  return tmp[hash].select_pos();
}
void Computer_sanmokunarabe::study() {}
static int make_hash_from_board(const std::string& board) {}
