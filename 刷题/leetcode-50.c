# include <stdio.h>

double myPow(double x, int n){
    long 
    if (n == 0) return 1;
    if (n == -2147483648) return 1/myPow(x, -(n+1)) * x;
    if (n < 0) return 1/myPow(x, -n);
    if (n == 1) return x;
    if (n % 2 != 0) return x * myPow(x, n-1);
    else {
        double tmp = myPow(x, n/2);
        return tmp * tmp;
    }
}

int main(){
    double ret = myPow(-2, 2);
    printf("%f", ret);
    return 0;
}