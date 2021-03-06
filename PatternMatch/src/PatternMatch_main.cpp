#include <iostream>
#include <fstream>
#include <vector>

struct board_env{
  std::string board_str;
  char winner;
};
class computer{
  private:
    std::vector<board_env> board_box;
    std::ifstream ifs;
    char my_stone, enemy_stone;
  public:
    computer(const char& my_stone): ifs("data.txt"){
      set_board_box();
      set_stone(my_stone);
    }
    void set_board_box(){
      if (!ifs) {
        std::cerr << "data.txt cant open\n";
      }
      for (board_env tmp;std::getline(ifs, tmp.board_str);) {
        tmp.winner = tmp.board_str.back();
        tmp.board_str.pop_back();
        board_box.push_back(tmp);
      }
    }
    void set_stone(const char& my_stone_){
      my_stone = my_stone_;
      enemy_stone = ((my_stone == 'b')?'w':'b');
    }
  //play
  private:
    double parcent_win(const std::string& board_str) {
      double count_win {};
      int n {1};//avoid inf
      for (auto e : board_box) {
        int equal {};
        for (auto i = 0;i < 9;++i) {
          if (board_str[i] == '.' || board_str[i] == e.board_str[i]) {
            ++equal;
          }
          if (equal == 9) {
            ++n;
            if (e.winner == my_stone) {
              count_win += 1.0;
            } else {
              count_win -= 0.5;
            }
          }
        }
      }
      return (count_win)/ n;
    }
  public:
    int define_put_stone_pos(const std::string& board_str){
      std::vector<double> pos_param(9);
      for (auto i = 0;i < 9;++i) {
        if (board_str[i] != '.') {
          pos_param[i] = -10000;//limit double min
        } else {
          std::string board_str_tmp(board_str);
          board_str_tmp[i] = my_stone;
          pos_param[i] = parcent_win(board_str_tmp);
        }
      }
      int good_pos {};
      double max {-10000};//limit double min
      for (auto i = 0;i < 9;++i) {
        if (pos_param[i] > max) {
          max = pos_param[i];
          good_pos = i;
        }
        std::cout << "pos_param[" << i << "]:"<< pos_param[i] << '\n';
      }
      return good_pos;
    }
};

class sanmokunarabe{
  private:
    static bool is_same(const char& ch0, const char& ch1, const char& ch2) {
      if (ch0 == ch1 && ch1 == ch2)return true;
      return false;
    }
  public:
    std::string board;
  private:
    char is_line_finish() {
      if (is_same(board[0], board[1], board[2]))return board[0];
      else if (is_same(board[3],board[4], board[5]))return board[3];
      else if (is_same(board[6],board[7], board[8])) return board[6];
      else return '.';
    }
    char is_row_finish() {
      if (is_same(board[0], board[3], board[6])) return board[0];
      else if (is_same(board[1], board[4], board[7])) return board[1];
      else if (is_same(board[2], board[5], board[8])) return board[2];
      else return '.';
    }
    char is_naname_finish() {
      if (is_same(board[0], board[4], board[8])) return board[0];
      else if (is_same(board[2], board[4], board[6])) return board[2];
      else return '.';
    }
  public:
    sanmokunarabe():board(9, '.'){};
    void print_board()const{
      for (auto i = 0;i < 3;++i) {
        for (auto j = 0;j < 3;++j) {
          std::cout << board[i * 3 + j];
        }
        std::cout << '\n';
      }
    }
    void put_stone(const int& pos, const char& stone){
      board[pos] = stone;
    }
    char isfinish() {
      if (is_line_finish() != '.') return is_line_finish();
      else if (is_row_finish() != '.') return is_row_finish();
      else if (is_naname_finish() != '.') return is_naname_finish();
      else return '.';
    }
};

int main(int argc ,char ** argv) {
  computer computer1('w');
  sanmokunarabe test;
  char winner {'.'};
  for (auto i = 0;i < 9;++i) {
    test.print_board();
    int detect_pos {};
    if (i%2 == 0) {
      detect_pos = computer1.define_put_stone_pos(test.board);
    } else {
      std::cout << "0~8:";
      std::cin >> detect_pos;
    }
    std::cout << detect_pos << '\n';
    test.put_stone(detect_pos, ((i%2==0)?'b':'w'));
    if (test.isfinish() != '.') {
      winner = test.isfinish();
      test.print_board();
      break;
    }
  }
  std::cout << "\nwinner : " << winner << '\n';
}
