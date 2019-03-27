#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <cassert>

struct UCB1_data{
  void update_count(const int& is_win) {
    if (is_win > 0) {
      ++this->win_count;
    }
    ++this->call_count;
  }

  double call(const int& trial_count) {
    if (call_count == 0) {
      return std::numeric_limits<double>::max();
    }
    return (this->win_count + std::sqrt((2*std::log(trial_count))/this->call_count));
  }

  private:
    int win_count;
    int call_count;
};

class hand{
  private:
    std::vector<UCB1_data> next_hand_UCB1param;
    std::vector<int> next_hand;
  public:
    hand(const int& hash){
      set_next_hand(hash);
    };
    static int hash_from_board(const std::string& board) {//board[9byte] -> hash[18bit(3or2byte)]
      int output_hash {};
      assert(board.size() != 9);
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
    void set_next_hand(const int& hash) {
      int c = 3;//00...011
      int hash_tmp = hash;
      for (auto i = 0;i < 9;++i) {
        if ((c & hash_tmp) == 0) {//'.'
          next_hand.push_back(i);
          next_hand_UCB1param.push_back();
        }
        hash_tmp = hash_tmp << 1;
      }
      next_hand.sort();
    }
    int call(){
      if (next_hand.empty() ) {
        std::cerr << "next_hand.empty\n";
        return -1;
      }
      return next_hand[0];
    }
};

class computer_sanmokunarabe{
  private:
    std::map<int, hand> tmp;//環境要素hashを入力,アクションをcallにより返却(仲介としてhand classを実装)
    int trial_count_;
  public:
    computer_sanmokunarabe(): trial_count_(0){};
    int choice_pos(const std::vector<int>& board) {
      int hash_board = hand::hash_from_board(board);
      return tmp[hash_board].call();
    }
    void study() {
      sanmokunarabe tmp;
      std::vector<int> hash_data_box;
//      for (;tmp.is_finish() != '.';) {
//      }

      for (auto i = 0;i < hash_data_box.size();++i) {
        if (hash_data_box.size() %2 == 0) {
          if (i % 2 == 0) {
            tmp[hash_data_box[i]].update_count(1);
          } else {
            tmp[hash_data_box[i]].update_count(0);
          }
        } else {
          if (i % 2 == 0) {
            tmp[hash_data_box[i]].update_count(0);
          } else {
            tmp[hash_data_box[i]].update_count(1);
          }
        }
      }

    }
};

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
    char is_finish_line(const std::string& board)const {
      if (is_same(board[0], board[3], board[6]) == true) return board[0];
      if (is_same(board[1], board[4], board[7]) == true) return board[1];
      if (is_same(board[2], board[5], board[8]) == true) return board[2];
      return '.';
    }
    char is_finish_naname(const std::string& board)const {
      if (is_same(board[0], board[4], board[8]) == true) return board[0];
      if (is_same(board[2], board[4], board[6]) == true) return board[2];
      return '.';
    }
  public:
    sanmokunarabe():board("........."){}
    void print_board() const {
      for (auto i = 0;i < 3;++i) {
        for (auto j = 0;j < 3;++j) {
          std::cout << board[i][j];
        }
        std::cout << '\n';
      }
    }
    char is_finish(const std::string& board) {
      tmp = is_finish_row(board);
      if (tmp != '.') return tmp;
      tmp = is_finish_line(board);
      if (tmp != '.') return tmp;
      tmp = is_finish_naname(board);
      return tmp;
    }
};

int main(int argc, char** argv) {
  computer_sanmokunarabe now_data;
  for (auto i = 0;i < 3;++i) {
    sanmokunarabe test;
    for (auto j = 0;j < 10;++j) {
      now_data.study();
    }
  }
}
