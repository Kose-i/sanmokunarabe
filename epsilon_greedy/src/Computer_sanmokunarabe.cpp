#include "Computer_sanmokunarabe.hpp"
#include "Hand_sanmokunarabe.hpp"
#include "sanmokunarabe.hpp"

#include <map>
#include <string>
#include <cassert>


int Computer_sanmokunarabe::select_pos(const int& hash) {//hashを受け取る
  return hand_box[hash].select_pos();
}

void Computer_sanmokunarabe::study() {
  std::vector<int> w_Hash_recorder;
  std::vector<int> w_Hand_recorder;
  std::vector<int> b_Hash_recorder;
  std::vector<int> b_Hand_recorder;
  sanmokunarabe test;
  char win_char {};
  for (auto i = 0;i < 9;++i) {
    std::string board_data = test.board_env();
    int hash_now = make_hash_from_board(board_data);
    int p = select_pos(hash_now);
    if (i % 2 == 0) {
      win_char =  test.set_stone_is_finish('w', p);
      w_Hash_recorder.push_back(hash_now);
      w_Hand_recorder.push_back(p);
    } else {
      win_char =  test.set_stone_is_finish('b', p);
      b_Hash_recorder.push_back(hash_now);
      b_Hand_recorder.push_back(p);
    }
    if (win_char != '.') {
      std::cout << "study circle " << i << '\n';
      break;
    }
  }
  //ここから更新手続き
  if (win_char == 'b') {
    for (auto i = 0;i < b_Hash_recorder.size();++i) {
      hand_box[b_Hash_recorder[i]].set_win(b_Hand_recorder[i]);
    }
    for (auto i = 0;i < w_Hash_recorder.size();++i) {
      hand_box[w_Hash_recorder[i]].set_lose(w_Hand_recorder[i]);
    }
  } else if (win_char == 'w') {
    for (auto i = 0;i < b_Hash_recorder.size();++i) {
      hand_box[b_Hash_recorder[i]].set_lose(b_Hand_recorder[i]);
    }
    for (auto i = 0;i < w_Hash_recorder.size();++i) {
      hand_box[w_Hash_recorder[i]].set_win(w_Hand_recorder[i]);
    }
  } else {
    for (auto i = 0;i < b_Hash_recorder.size();++i) {
      hand_box[b_Hash_recorder[i]].set_lose(b_Hand_recorder[i]);
    }
    for (auto i = 0;i < w_Hash_recorder.size();++i) {
      hand_box[w_Hash_recorder[i]].set_lose(w_Hand_recorder[i]);
    }
  }
}

int Computer_sanmokunarabe::make_hash_from_board(const std::string& board) {//board[9byte] -> output_hash[{18bit}]
  int output_hash {};
  assert(board.size() == 9);
  for (auto i = 0;i < 9;++i) {
    output_hash = output_hash << 2;//2bit 移動
    if (board[i] == 'b') {
      output_hash += 1;
    } else if (board[i] == 'w') {
      output_hash += 2;
    } else {//board[i] == '.'
      output_hash += 0;
    }
  }
  return output_hash;
}
