#include <vector>
#include <map>
#include <cmath>
#include <limits>

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

class computer_sanmokunarabe{
  private:
    std::map<int, UCB1_data> tmp;//環境要素を入力,アクションをcallにより返却
    std::vector<double> hand;//現在の状況から次の手をUCB1アルゴリズムから決定
    int trial_count_;
    void hand_update() {
      for (auto i = 0;i < 9;++i) {
        hand[i] = tmp[];
      }
    }
  public:
    computer_sanmokunarabe():hand(9,0.0), trial_count_(0){};
    int choice_pos(const std::vector<int>& board) {
      int max_pos {};
      hand_update();
      return max_pos;
    }
    void study() {
      sanmokunarabe tmp;
      std::vector<int> hash_data_box;
      for (;tmp.is_finish() != '.';) {
      }

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
