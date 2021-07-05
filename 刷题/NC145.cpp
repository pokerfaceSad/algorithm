# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        // dp[i][j]表示 体积为i时 从前j个物品里能拿出的最大价值
        // dp[i][j] = i >= v[i] ? max(dp[i][j-1], dp[i-v[i]][j-1] + w[i]) : dp[i][j-1]
        // dp[0][x] = 0 dp[x][0] = 0
        vector<vector<int>> dp(V+1, vector<int>(n+1));
        for (int i = 0 ; i <= V ; i++) dp[i][0] = 0;
        for (int i = 0 ; i <= n ; i++) dp[0][i] = 0;
        for (int i = 1 ; i <= V ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (i >= vw[j-1][0]) dp[i][j] = max(dp[i][j-1], dp[i-vw[j-1][0]][j-1] + vw[j-1][1]);
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[V][n];

    }
};