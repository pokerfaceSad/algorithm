# include <stdio.h>
int kthGrammar(int N, int K){
    if (N == 1 || K == 1) return 0;

    if (K % 2 == 0) {
        return !kthGrammar(N-1, K/2);
    } else {
        return kthGrammar(N-1, (K+1)/2);
    }

}

int main() {
    int ret = kthGrammar(2, 2);
    printf("%d", ret);
    return 0;
}