#include <stdio.h>

// int 변수의 값을 증가시키는 함수
void increment(int* val) {
    *val += 1;
}

int main() {

    int val = 0;
    printf("before: %d \n", val);
    increment(&val);
    printf("after: %d \n", val);


    return 0;
}
