#include <stdio.h>

// int ������ ���� ������Ű�� �Լ�
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
