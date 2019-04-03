class hand{
  private:
    std::vector<UCB1_data> next_hand_UCB1param;//報酬
  public:
    hand(const int& hash):next_hand_UCB1param(9) {}
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
    void update(int number, int win_check) {
      next_hand_UCB1param[number].update_count(win_check);
    }
    int call(){
      if (next_hand.empty() ) {
        std::cerr << "next_hand.empty\n";
        return -1;
      }
      int goukei {};
      for (const auto& e : next_hand_UCB1param ) {
        goukei += e.this_call_count;
      }
      double max_param = std::numeric_limits<double>::min();
      int max_pos = 0;
      for (auto i = 0;i < 9;++i) {
        if (max_param < next_hand_UCB1param[i].call(goukei)) {
          max_param = next_hand_UCB1param[i].call(goukei);
          max_pos = i;
        }
      }
      return max_pos;
    }
};

class computer_sanmokunarabe{
  private:
    std::map<int, hand> tmp;//環境要素hashを入力,アクションをcallにより返却(仲介としてhand classを実装)
    int trial_count_;
  public:
    computer_sanmokunarabe(): trial_count_(0){};
    int choice_pos(const std::string& board) {
      int hash_board = hand::hash_from_board(board);
      return tmp[hash_board].call();
    }
    void study() {
      sanmokunarabe tmp;
      std::vector<int> put_pos_data_box;//おいた場所を記録
      std::vector<int> hash_data_box;
      char winner = '.';
      char stone = 'w';
      int pos = 0;
      for (auto i = 0;i < 9;++i) {
        if (i %2 == 0) {
          pos = choice_pos(tmp);
          stone = 'w';
        } else {
          pos = choice_pos(tmp);
          stone = 'b';
        }
        put_pos_data_box.push_back(pos);
        winner = tmp.set_stone_is_finish(stone, pos);
        if (winner != '.') break;
      }

      for (auto i = 0;i < put_pos_data_box.size();++i) {
        if (winner != 'w') {
          if (i % 2 == 0) {
            tmp[hash_data_box[i]].update_count(1);
          } else {
            tmp[hash_data_box[i]].update_count(0);
          }
        } else {
          if (winner == 'b') {
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
};

int main(int argc, char** argv) {
//  computer_sanmokunarabe now_data;
  char stone = 'w';
  for (auto i = 0;i < 3;++i) {
    sanmokunarabe test;
    for (auto j = 0;j < 10;++j) {
      test.print_board();
      if (j %2 == 0) stone = 'w';
      else stone = 'b';
      std::cout << "pos:";
      //pos = now_data.choice_pos();
      int pos;
      std::cin >> pos;
      if (test.set_stone_is_finish(stone, pos) != '.') {
        std::cout << "finish\n";
        break;
      }
    }
  }
}
