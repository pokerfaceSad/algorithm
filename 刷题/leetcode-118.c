# include <stdio.h>
# include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 // numRows是三角的行数
 // returnColumnSizes是每一行的元素数 
int generate_item(int** ret, int row, int column) {
    if (row == 1 || row == 0 || column <= 0 || column >= row) {
        return 1;
    }
    // int item1 = generate_item(row-1, column);
    // int item2 = generate_item(row-1, column-1);
    int item1 = *(*(ret+row-1) + column);
    int item2 = *(*(ret+row-1) + column - 1);
    return item1 + item2;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(sizeof(int*)*numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    *returnSize = numRows;

    for (int i = 0 ; i < numRows ; i++) {
        *(ret+i) = (int*)malloc(sizeof(int) * (i+1));
        *(*returnColumnSizes+i) = (i+1);
        for (int j = 0 ; j < i+1 ; j++) {
            *(*(ret+i)+j) = generate_item(ret, i, j);
        }
    }

    return ret;
}



int main() {

    int numRows = 5;
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));
    int** ret = generate(numRows, returnSize, returnColumnSizes);
    for (int i = 0 ; i < *returnSize ; i++) {
        for (int j = 0 ; j < *(*returnColumnSizes+i); j++) {
            // printf("%d ", *(*(ret+i)+j));
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}