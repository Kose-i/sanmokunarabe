#ifndef sanmokunarabe_hpp
#define sanmokunarabe_hpp

#include <iostream>
#include <string>

class sanmokunarabe{
  private:
    std::string board;
    static bool is_same(const char& t1, const char& t2, const char& t3) {
      return ((t1 == t2)&&(t2 == t3));
    }
    char is_finish_row()const {
      if (is_same(board[0], board[1], board[2]) == true) return board[0];
      if (is_same(board[3], board[4], board[5]) == true) return board[3];
      if (is_same(board[6], board[7], board[8]) == true) return board[6];
      return '.';
    }
    char is_finish_line()const {
      if (is_same(board[0], board[3], board[6]) == true) return board[0];
      if (is_same(board[1], board[4], board[7]) == true) return board[1];
      if (is_same(board[2], board[5], board[8]) == true) return board[2];
      return '.';
    }
    char is_finish_naname()const {
      if (is_same(board[0], board[4], board[8]) == true) return board[0];
      if (is_same(board[2], board[4], board[6]) == true) return board[2];
      return '.';
    }
  public:
    sanmokunarabe():board("........."){}
    void print_board() const {
      for (auto i = 0;i < 3;++i) {
        for (auto j = 0;j < 3;++j) {
          std::cout << board[i*3 + j];
        }
        std::cout << '\n';
      }
    }
    char set_stone_is_finish(const char& stone, const int& pos) {
      if (board[pos] != '.') {
        if (stone == 'w') return 'b';
        else if (stone == 'b') return 'w';
      }
      board[pos] = stone;
      return is_finish();
    }
    char is_finish() {
      char tmp = is_finish_row();
      if (tmp != '.') return tmp;
      tmp = is_finish_line();
      if (tmp != '.') return tmp;
      tmp = is_finish_naname();
      return tmp;
    }
    std::string board_env() {
      return board;
    }
};
#endif
