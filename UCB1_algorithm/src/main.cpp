#include "sanmokunarabe.hpp"
#include "Computer_sanmokunarabe.hpp"

#include <thread>
#include <chrono>
constexpr auto wait_time = std::chrono::seconds(2);

int player_select(const char& stone_color) {
  std::cout << "your_stone : " << stone_color << '\n';
  std::cout << "pos[0~9]:";
  std::cout << "\t012\n\t345\n\t678\n";
  const int pos {[](){int a;std::cin >> a;return a;}()};
  return pos;
}

int main(int argc, char** argv) {
  std::cout << "main-start\n";
  Computer_sanmokunarabe test;
  for (auto i = 0;i < 5;++i) {//player による実証

    for (auto j = 0;j < 10000;++j) {//コンピュータ強化学習
      test.study();
    }

    sanmokunarabe tmp;//強化学習をテストする
    for (auto j = 0;j < 9;++j) {//プレイアーVSコンピュータ
      int pos = 0;
      char stone = '.';
      if (j % 2 == 0) {
        stone = 'w';
        pos = player_select(stone);
      } else {
        stone = 'b';
        std::cout << "enemy turn:";
        std::cout << "pos:" << pos;
        pos = test.select_pos(Computer_sanmokunarabe::make_hash_from_board(tmp.board_env()));
      }
      char c = tmp.set_stone_is_finish(stone, pos);
      if (c != '.') {
        std::cout << "finish\n";
        std::cout << "winner is" << c << '\n';
        break;
      }
      tmp.print_board();
    }
    std::this_thread::sleep_for(wait_time);

  }
  std::cout << "main-finish\n";
}
