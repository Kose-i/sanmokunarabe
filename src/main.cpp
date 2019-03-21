#include <iostream>
#include <fstream>
#include <vector>

struct board_env{
  std::string board_str;
  char winner;
};
int main(int argc ,char ** argv) {
  std::vector<board_env> board_box;
  std::ifstream ifs("data.txt");
  for (auto i = 0;i < 10;++i) {
    board_env tmp;
    std::getline(ifs, tmp.board_str);
    tmp.winner = tmp.board_str.back();
    tmp.board_str.pop_back();
    board_box.push_back(tmp);
    std::cout << "board_str:" << tmp.board_str << " winner:" << tmp.winner << '\n';
  }
}
