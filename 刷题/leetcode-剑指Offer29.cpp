class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};

        vector<int> res(m*n, 0);
        int index = 0;
        int level = 0;
        while (true) {
            // 右
            for (int i = level ; i < n - level ; i++) res[index++] = matrix[level][i];
            if (index == m*n) break;
            // 下
            for (int i = level+1 ; i < m - level ; i++) res[index++] = matrix[i][n-level-1];
            if (index == m*n) break;
            // 左
            for (int i = n - level - 2 ; i >= level ; i--) res[index++] = matrix[m-level-1][i];
            if (index == m*n) break;
            // 上
            for (int i = m - level - 2 ; i > level; i--) res[index++] = matrix[i][level];
            if (index == m*n) break;
            level++;
        }
        return res;
    }
};