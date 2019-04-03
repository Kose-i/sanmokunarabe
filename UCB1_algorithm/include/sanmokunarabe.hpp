#ifndef sanmokunarabe_hpp
#define sanmokunarabe_hpp

#include <iostream>
#include <string>

class sanmokunarabe{
  private:
    std::string board;
    static bool is_same(const char&, const char&, const char&);
    char is_finish_row()const;
    char is_finish_line()const;
    char is_finish_naname()const;
  public:
    sanmokunarabe();
    void print_board() const;
    char set_stone_is_finish(const char& stone, const int& pos);
    char is_finish();
    std::string board_env();
};
#endif
