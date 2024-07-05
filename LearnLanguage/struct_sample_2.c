#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char a[2 + 1];
    char b[2 + 1];
    char* c;
} ST_DATA;

void call_by_structure_str2(char** str) {
    strcpy(*str, "qw");
}

int main() {
    ST_DATA st_data;

    // a와 b 배열을 초기화합니다.
    memset(st_data.a, 0, sizeof(st_data.a));
    memset(st_data.b, 0, sizeof(st_data.b));

    // c 포인터에 메모리를 할당합니다.
    st_data.c = (char*)malloc((2 + 1) * sizeof(char));
    if (st_data.c == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // c 포인터에 문자열을 복사합니다.
    strcpy(st_data.c, "xy");
    printf("before st.c: %s\n", st_data.c); // 이곳 출력이 안찍힘

    // call_by_structure_str2 함수 호출
    char* str2 = st_data.c;
    call_by_structure_str2(&str2);
    printf("after st.c: %s\n", st_data.c);

    // 할당된 메모리를 해제합니다.
    free(st_data.c);

    return 0;
}
