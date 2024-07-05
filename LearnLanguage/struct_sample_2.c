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

    // a�� b �迭�� �ʱ�ȭ�մϴ�.
    memset(st_data.a, 0, sizeof(st_data.a));
    memset(st_data.b, 0, sizeof(st_data.b));

    // c �����Ϳ� �޸𸮸� �Ҵ��մϴ�.
    st_data.c = (char*)malloc((2 + 1) * sizeof(char));
    if (st_data.c == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // c �����Ϳ� ���ڿ��� �����մϴ�.
    strcpy(st_data.c, "xy");
    printf("before st.c: %s\n", st_data.c); // �̰� ����� ������

    // call_by_structure_str2 �Լ� ȣ��
    char* str2 = st_data.c;
    call_by_structure_str2(&str2);
    printf("after st.c: %s\n", st_data.c);

    // �Ҵ�� �޸𸮸� �����մϴ�.
    free(st_data.c);

    return 0;
}
