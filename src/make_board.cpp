#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class sanmokunarabe_match{
  public:
    std::string board;
    static bool is_same(const char& ch0, const char& ch1, const char& ch2) {
      if (ch0 == ch1 && ch1 == ch2)return true;
      return false;
    }
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
    sanmokunarabe_match(const std::string& s):board(s){}
    void print_board() {
      for (auto i = 0;i < 3;++i) {
        for (auto j = 0;j < 3;++j) {
          std::cout << board[3*i + j];
        }
        std::cout << '\n';
      }
    }
    void put_stone(const char& ch, const int& pos) {
      if (0 <= pos && pos < 9) {
        board[pos] = ch;
      } else {
        std::cerr << "Invalid pos\n";
        return;
      }
    }
    char isfinish() {
      if (is_line_finish() != '.') return is_line_finish();
      else if (is_row_finish() != '.') return is_row_finish();
      else if (is_naname_finish() != '.') return is_naname_finish();
      else return '.';
    }
    std::vector<int> putable_spot() {
      std::vector<int> vec;
      for (auto i = 0;i < 9;++i) {
        if (board[i] == '.')vec.push_back(i);
      }
      return vec;
    }
};

struct board_data{
  std::string board_tmp=".........";
  char now_finish='.';
};

int main(int argc, char** argv) {
  std::vector<board_data> board_box(1);
  sanmokunarabe_match test(board_box[0].board_tmp);
  auto now_cycle = 0;
  for (auto i = 0;i < 9;++i) { // i < 9 <- finish all
    auto next_cycle = board_box.size();
    for (auto j = now_cycle;j < next_cycle;++j) {
      sanmokunarabe_match tmp(board_box[j].board_tmp);
      if (tmp.isfinish() != '.') continue;
      std::vector<int> putable_spot = tmp.putable_spot();
      for (const auto& e : putable_spot) {
        sanmokunarabe_match tmp_test(board_box[j].board_tmp);
        tmp_test.put_stone(((i%2==0)?'b':'w'), e);
        board_data tmp_board_data;
        tmp_board_data.now_finish = tmp_test.isfinish();
        tmp_board_data.board_tmp = tmp_test.board;
        board_box.push_back(tmp_board_data);
      }
    }
    now_cycle = next_cycle;
    std::cout << "now_cycle:" << now_cycle << '\n';
  }
  std::ofstream ofs("data.txt");
  if (!ofs) {
    std::cerr << "data.txt" << " cant open\n";
  }
  for (const auto& e : board_box) {
    if (e.now_finish == '.') continue;
    ofs << e.board_tmp << e.now_finish << '\n';
  }
  std::cout << "Succeed:write data.txt\n";
}
