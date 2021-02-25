# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先对角交换
        // 再上下交换
        int size = matrix.size();
        for (int i = 0 ; i < size-1 ; i++) {
            for (int j = 0 ; j < size-i-1 ; j++) {
                swap(matrix[i][j], matrix[size-j-1][size-i-1]);
            }
        }
        for (int i = 0 ; i < size/2 ; i++) {
            swap(matrix[i], matrix[size-i-1]);
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
    print2DMatrix(matrix);
    Solution s;
    s.rotate(matrix);
    print2DMatrix(matrix);
    return 0;
}