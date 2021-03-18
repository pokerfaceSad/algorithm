# include <iostream>
# include <queue>
using namespace std;

class Solution {
public:
    int getSum(int x, int y) {
        int sum = 0;
        while (x != 0) {
            sum += (x % 10);
            x /= 10;
        }
        while (y != 0) {
            sum += (y % 10);
            y /= 10;
        }
        return sum;
    }
    // 层序遍历 广度优先搜索
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 1;
        q.push(make_pair(0, 0));
        vis[0][0] = true;
        int x, y, x_, y_;
        int dx[] = {1, 0}, dy[] = {0, 1}; // 方向数组
        while (!q.empty()) {
            // 从队首元素向下向右搜索
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0 ; i < 2; i++) {
                x_ = x + dx[i];
                y_ = y + dy[i];
                if (x_ == m || y_ == n || vis[x_][y_] == 1) continue; // 越界或已经访问过
                else if (getSum(x_, y_) <= k) {
                    q.push(make_pair(x_, y_));
                    vis[x_][y_] = 1;
                    res++;
                }
            }
        }
        return res;
    }

    // 递推 动态规划
    int movingCount(int m, int n, int k) {
        // dp[i][j] 表示第i行，第j个格子的可达性
        // dp[i][j] = (dp[i-1][j] || dp[i][j-1]) && getSum(i, j) <= k
        // dp[0][0] = 1
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        int res = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (getSum(i, j) > k ) continue;
                if (i - 1 >= 0) dp[i][j] = dp[i-1][j] | dp[i][j];
                if (j - 1 >= 0) dp[i][j] = dp[i][j-1] | dp[i][j];
                res = dp[i][j] ? res + 1 : res;
            }
        }
        return res;
    }

};

int main() {
    Solution s;
    cout << s.getSum(100, 101) << endl;
    return 0;
}