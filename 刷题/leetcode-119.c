# include <stdio.h>
# include <stdlib.h>
# include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 // numRows是三角的行数
 // returnColumnSizes是每一行的元素数 
int generate_item(int** triangle, int row, int column) {
    if (row == 1 || row == 0 || column <= 0 || column >= row) {
        // triangle[row][column] = 1;
        // *(*(triangle+row)+column) = 1;
        return 1;
    }

    if (triangle[row][column] != -1) {
        return triangle[row][column];
    }

    int item1 = generate_item(triangle, row-1, column);
    int item2 = generate_item(triangle, row-1, column-1);
    triangle[row][column] = item1 + item2;

    return item1 + item2;
}


int* getRow(int rowIndex, int* returnSize){

    int** triangle = (int**)malloc(sizeof(int*)*(rowIndex+1));

    for(int i = 0 ; i < rowIndex+1 ; i++) {
        *(triangle+i) = (int*)malloc(sizeof(int)*(i+1));
        memset(*(triangle+i), -1, sizeof(int)*(i+1));
    }

    *returnSize = rowIndex+1;
    int* ret = (int*)malloc(sizeof(int)*(rowIndex+1));
    if ((rowIndex+1)%2 == 0) {
        for (int i = 0 ; i < (rowIndex+1)/2 ; i++) {
            *(ret+i) = generate_item(triangle, rowIndex, i);
            *(ret+rowIndex-i) = *(ret+i);
        }
    }
    else {
        for (int i = 0 ; i < (rowIndex+1)/2 ; i++) {
            *(ret+i) = generate_item(triangle, rowIndex, i);
            *(ret+rowIndex-i) = *(ret+i);
        }
        *(ret + (rowIndex+1)/2) = generate_item(triangle, rowIndex, (rowIndex+1)/2);
    }
    return ret;
}


int main() {

    int rowIndex = 3;
    int* returnSize = (int*)malloc(sizeof(int));

    int* ret = getRow(rowIndex, returnSize);
    for (int i = 0 ; i < rowIndex+1; i++) {
        printf("%d", ret[i]);
    }
    return 0;
}