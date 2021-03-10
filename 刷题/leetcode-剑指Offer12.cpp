# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index) {
        if (row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && board[row][col] == word[index]) {
            if (index == word.size()-1) return true;
            // 将已经走过的位置标记
            board[row][col] = '\0';
            if (dfs(board, row-1, col, word, index+1) || \
                dfs(board, row+1, col, word, index+1) || \
                dfs(board, row, col-1, word, index+1) || \
                dfs(board, row, col+1, word, index+1)) 
                return true;
            else {
                // 如果这条路径探索不成功 将标记过的位置复原
                board[row][col] = word[index];
            }
        } 
        return false; // 越界
    }
};

int main() {
    char chs[] = {'a', 'b'};
    vector<char> chars(chs, chs + 2);
    vector<vector<char>> board;
    board.push_back(chars);
    Solution s;
    s.exist(board, "ba");
    return 0;
}