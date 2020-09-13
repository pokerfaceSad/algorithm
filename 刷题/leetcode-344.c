# include <stdio.h>

// 双指针
void reverseString(char* s, int sSize){
    int p_front = 0;
    int p_end = sSize-1;
    char tmp;
    while(p_front < p_end) {
        tmp = *(s + p_front);
        *(s + p_front) = *(s + p_end);
        *(s + p_end) = tmp;
        p_front++;
        p_end--;
    }
}

// 递归
void reverseString_v2(char* s, int sSize){

    if (sSize <= 1) {
        return;
    }

    char tmp = *s;
    *s = *(s+sSize-1);
    *(s+sSize-1) = tmp;
    reverseString(s+1, sSize-2);
}

int main(){
    char s[] = "Hello";
    reverseString(s, 5);
    printf("%s\n", s);
    return 0;
}