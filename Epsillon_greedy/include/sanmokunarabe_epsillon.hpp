#ifndef sanmokunarabe_hpp
#define sanmokunarabe_hpp

#include <iostream>
#include <string>

class sanmokunarabe_epsillon{
  private:
    std::string board;
    static bool is_same(const char&, const char&, const char&);
    char is_finish_row()const;
    char is_finish_line()const;
    char is_finish_naname()const;
  public:
    sanmokunarabe_epsillon();
    void print_board() const;
    char set_stone_is_finish(const char& stone, const int& pos);
    char is_finish()const;
    std::string board_env()const;
};
#endif
