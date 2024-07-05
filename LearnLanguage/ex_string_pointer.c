#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "simple_syntax.h"
#include <string.h>
#include <stdarg.h>
#include "ex_string_pointer.h"

typedef struct {
	char a[2 + 1];
} ST;

int main() {

	//ex_1();
	//ex_2();
	//ex_3();
	//ex_4();
	//ex_5();
	//ex_6();
	//ex_7();
	int num_arr[3] = { 1,2, 3 };

	
	return 0;
}

void ex_7()
{
	int num_arr[3] = { 1,2, 3 };
	for (int i = 0; i < 3; i++) {
		int* num_addr = &num_arr[i];
		printf("%d idx: %p\n", i, num_addr);
	}
}

void ex_6() // 문자열 기본값 초기화 후 나머지 잔여 공간은 무조건 NULL 인가?
{
	char str[6] = "abc";
	printf(
		"str[0] %c, is NULL? %d\n"
		"str[1] %c, is NULL? %d\n"
		"str[2] %c, is NULL? %d\n"
		"str[3] %c, is NULL? %d\n"
		"str[4] %c, is NULL? %d\n"
		"str[5] %c, is NULL? %d\n",

		str[0], str[0] == NULL,
		str[1], str[1] == NULL,
		str[2], str[2] == NULL,
		str[3], str[3] == NULL,
		str[4], str[4] == NULL,
		str[5], str[5] == NULL
	);
}

void ex_5() // strcpy를 하면 나머지 공간에 무엇으로 채워지는가?
{
	char str1[3 + 1] = "abc";
	char str2[5 + 1] = "ABCDE";
	//strcpy(str2, str1);
	//strcpy_s(str2, 6, str1);
	strncpy_s(str2, 6, str1, 3);

	printf("str1: %s\n" "str2: %s\n", str1, str2);

	printf(
		"str2[0] = %c, is NULL? %d\n"
		"str2[1] = %c, is NULL? %d\n"
		"str2[2] = %c, is NULL? %d\n"
		"str2[3] = %c, is NULL? %d\n"
		"str2[4] = %c, is NULL? %d\n"
		"str2[5] = %c, is NULL? %d\n"
		"str2[6] = %c, is NULL? %d\n",

		str2[0], str2[0] == NULL,
		str2[1], str2[1] == NULL,
		str2[2], str2[2] == NULL,
		str2[3], str2[3] == NULL,
		str2[4], str2[4] == NULL,
		str2[5], str2[5] == NULL,
		str2[6], str2[6] == NULL
	);
}

void ex_4() // 원본 문자열이 변해있는가? 얇은 복사
{
	char str1[3 + 1] = "abc";
	char* str2 = str1;

	str2[0] = 'X';

	printf("str1: %s\n" "str2: %s\n", str1, str2);
}

void ex_3() // 원본 문자열이 변해있는가? 깊은 복사
{
	char str1[3 + 1] = "abc";
	char str2[3 + 1] = "";

	strcpy(str2, str1);

	str2[0] = 'X';

	printf("str1: %s\n" "str2: %s\n", str1, str2);

}

void ex_2()
{
	ST* st = (ST*)malloc(sizeof(ST));
	strcpy(st->a, "AB");

	printf("FIRST: %s, size: %d\n", st->a, sizeof(st->a));

	// #1
	char str1[2 + 1];
	strcpy(str1, st->a);

	// #2
	char* str2 = st->a;
	str2[2] = '\0';

	// #3
	char str3[2 + 1] = "";
	strcpy(str3, st->a);
	str3[2] = '\0';

	printf("str1: %s, strlen: %zu, sizeof: %d\n", str1, strlen(str1), sizeof(str1));
	printf("str2: %s, strlen: %zu, sizeof: %d\n", str2, strlen(str2), sizeof(str2));
	printf("str3: %s, strlen: %zu, sizeof: %d\n", str3, strlen(str3), sizeof(str3));
}

void ex_1()
{
	char a[3 + 1] = "abc";
	char* b = a;

	b[0] = 'X';

	printf(
		"a = %s\n"
		"b = %s\n",
		a, b
	);
}
