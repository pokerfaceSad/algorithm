# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool firstRowFlag = false;
        bool firstColFlag = false;
        for (int row = 0 ; row < rowSize; row++) {
            for (int col = 0 ; col < colSize; col++) {
                if (matrix[row][col] == 0) {
                    if (row == 0) firstRowFlag = true;
                    if (col == 0) firstColFlag = true;
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for (int col = 1 ; col < colSize; col++) {
            if(matrix[0][col] == 0) {
                for (int row = 0 ; row < rowSize; row++) {
                    matrix[row][col] = 0;
                }
            }
        }
        for (int row = 1 ; row < rowSize ; row++) {
            if (matrix[row][0] == 0) {
                for (int col = 0 ; col < colSize ; col++) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (firstColFlag == true) {
            for (int row = 0 ; row < rowSize; row++) {
                matrix[row][0] = 0;
            }
        }
        if (firstRowFlag == true) {
            for (int col = 0 ; col < colSize; col++) {
                matrix[0][col] = 0;
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
    int m1[] = {0,2,3,4};
    vector<int> matrix1(m1, m1 + sizeof(m1)/sizeof(int));
    int m2[] = {4,0,6,7};
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
    print2DMatrix(matrix);
    cout << "-------------------" << endl;
    s.setZeroes(matrix);
    print2DMatrix(matrix);
    return 0;
}
