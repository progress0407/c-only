#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "simple_syntax.h"
#include <string.h>
#include <stdarg.h>

int var_args_sum(int count, ...);
void printfln(const char* message_format, ...);

void copy_strf(const char* dest_str, const char* src_str, ...) {

	va_list args;
	va_start(args, src_str);

	// vsnprintf(dest_str, 10, src_str, args);
	vsprintf(dest_str, src_str, args);

	va_end(args);
}

int main() {

	// switch_case();

	/*
	char* src_str = "1234";
	char dest_str[4 + 1] = "";

	sprintf(dest_str, "%.3s", &src_str[1]);
	printf("%s\n", dest_str);
	*/

	/*
	char* str = "abcde";
	char ret = strstr(str, "bcq");
	printf("return: %d \n", (ret == NULL));
	*/

	// printf("is 0X00 NULL? :  %d", (0x00 == NULL));

	/*
	printf("sum = %d", var_args_sum(3, 1, 2, 3));
	printfln("%s, %s!", "Hello", "World!");
	printfln("%d + %d = %d", 3, 5, 8);
	*/

	// char dest_str[30] = "";
	// char* str = (char*)malloc(6 * sizeof(char));
	char* dest_str = (char*)malloc(30 * sizeof(char));
	copy_strf(dest_str, "%d + %d = %d", 3, 5, 8);
	printf("dest_str = %s", dest_str);

	return 0;
}

void printfln(const char* message_format, ...) {

	va_list args;
	va_start(args, message_format);

	// vprintf("%s\n", message_format, args);
	vprintf(message_format, args);
	printf("\n");

	va_end(args);
}

int var_args_sum(int count, ...) {

	int tot = 0;

	va_list args;

	va_start(args, count);

	for (int i = 0; i < count; i++) {
		int arg = va_arg(args, int);
		printf("arg = %d \n", arg);
		tot += arg;
	}

	va_end(args);

	return tot;
}

void switch_case()
{
	int a = 2;

	switch (a) {

	case 1:
		printf("case 1 \n");
		break;

	default:
		printf("default 1 \n");
		break;
	}
}
