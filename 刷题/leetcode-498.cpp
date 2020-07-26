# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;
        int row = matrix.size();
        int col =  matrix[0].size();
        bool directUp = true;
        int currentCol = 0;
        int currentRow = 0;
        for (int line = 0 ; line < row + col-1 ; line++) {
            if (directUp) {
                while (true) {
                    ret.push_back(matrix[currentRow][currentCol]);
                    if (currentCol == col -1 ) {
                        currentRow++;
                        break;
                    } else if (currentRow == 0) {
                        currentCol++;
                        break;
                    }
                    currentRow--;
                    currentCol++;
                }
                directUp = false;
            } else {
                while(true) {
                    ret.push_back(matrix[currentRow][currentCol]);
                    if (currentRow == row - 1) {
                        currentCol++;
                        break;
                    } else if (currentCol == 0) {
                        currentRow++;
                        break;
                    }
                    currentRow++;
                    currentCol--;
                }
                directUp = true;
            }
        }
        return ret;
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
    // int m4[] = {11,12,13,14};
    // vector<int> matrix4(m4, m4 + sizeof(m4)/sizeof(int));
    // vector<vector<int>> matrix(4);
    vector<vector<int>> matrix(3);
    matrix[0] = matrix1;
    matrix[1] = matrix2;
    matrix[2] = matrix3;
    // matrix[3] = matrix4;
    print2DMatrix(matrix);
    Solution s;
    vector<int> ret = s.findDiagonalOrder(matrix);
    for (auto elem : ret) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}