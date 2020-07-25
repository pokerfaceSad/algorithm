# include <iostream>
# include <vector>
# include <utility>
using namespace std;

// 循环中需要频繁访问矩阵size，提前缓存好可以更快
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // 上下翻转
        for (int col = 0 ; col < size/2; col++) {
            swap(matrix[col], matrix[matrix.size()-col-1]);
        }
        // 主对角线翻转
        for (int col = 0 ; col < size-1; col++) {
            for (int row = col+1 ; row < matrix[col].size(); row++) {
                swap(matrix[col][row], matrix[row][col]);
            }
        }
    }
};

void print2DMatrix(vector<vector<int>>& matrix) {
    for (int col = 0 ; col < matrix.size(); col++) {

        for (auto elem : matrix[col]) {
            cout << elem << " ";
        }
        cout << endl;
    }
}
int main() {
    int m1[] = {1,2,3,4};
    vector<int> matrix1(m1, m1 + sizeof(m1)/sizeof(int));
    int m2[] = {4,5,6,7};
    vector<int> matrix2(m2, m2 + sizeof(m2)/sizeof(int));
    int m3[] = {7,8,9,10};
    vector<int> matrix3(m3, m3 + sizeof(m3)/sizeof(int));
    int m4[] = {7,8,9,10};
    vector<int> matrix4(m4, m4 + sizeof(m4)/sizeof(int));
    vector<vector<int>> matrix(4);
    matrix[0] = matrix1;
    matrix[1] = matrix2;
    matrix[2] = matrix3;
    matrix[3] = matrix4;
    Solution s;
    s.rotate(matrix);
    print2DMatrix(matrix);
    
    return 0;
}