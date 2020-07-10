# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int* mem;

int getMethodNum(int n){
    if (n == 1 || n == 2) {
        return n;
    }
    if (*(mem+n-1) != -1) {
        return *(mem+n-1);
    }
    int result = getMethodNum(n-1) + getMethodNum(n-2);
    *(mem+n-1) = result;
    return result;
}

int climbStairs(int n){
    mem = (int*)malloc(sizeof(int) * n);
    memset(mem, -1, sizeof(int) * n);
    return getMethodNum(n);
}


int main(){
    int ret = climbStairs(3);
    printf("%d", ret);
    return 0;
}