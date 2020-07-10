# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define maxn 32
int* mem;

int getFibItem(N) {
    if (*(mem+N) != -1) {
        return *(mem+N);
    }
    if (N == 0 || N == 1) {
        return N;
    }
    int result = getFibItem(N-1) + getFibItem(N-2);
    *(mem+N) = result;
    return result;
}

int fib(int N){
    mem = (int*)malloc(sizeof(int)*maxn);
    memset(mem, -1, sizeof(int)*maxn);
    int result = getFibItem(N);
    return result;
}


int main() {

    int result = fib(30);
    printf("%d\n", result);

    return 0;
}