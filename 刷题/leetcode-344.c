# include <stdio.h>

void reverseString(char* s, int sSize){

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