# include <iostream>
using namespace std;
class Solution {
public:
    // 约瑟夫环
    // 动态规划
    // 定义：
    //  dp[n, m] 表示 数组长度为n 删除第m个数字时 最终剩下数字的下标
    // 递推：
    //  n, m状态下，第一个删除的元素为 索引为 (m-1)%n个元素
    //  考虑删除之后的情况
    //  首先删除之后问题变为n-1, m问题，假设dp[n-1, m] = x
    //  则可求得x元素在原数组中的索引则完成dp[n-1, m]到dp[n, m]的递推
    //  x为最后剩下的元素在新的n-1数组中的索引
    //  但新的n-1数组实际上是从（(m-1)%n + 1%n = m%n开始重新计数的
    //  因此x元素在原n-1数组中的索引实际上为 (m%n + x) % n = (m + x) % n
    //  可得状态转移方程为：dp[n, m] = (dp[n-1, m] + m) % n
    // 初值：
    //  dp[1, m] = 0  只有一个元素时最后一个元素的索引是0
    int lastRemaining(int n, int m) {
        int dp = 0;
        for (int i = 2 ; i <= n ; i++) {
            dp = ( dp + m ) % i;
        }
        return dp;
    }
};