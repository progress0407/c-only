
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


typedef struct 
{
	char a[4 + 1];
	char b[3 + 1];
	char c[2 + 1];
} ST_DATA;

void copy_to_struct_field(int* offset, char* src_str, char* dest_str, const int dest_str_size);

int main() {

	const char* str = "123456789";

	ST_DATA st_data = { "X" };

	int offset = 0;
	int len = 0;

	copy_to_struct_field(&offset, str, st_data.a, sizeof(st_data.a));
	copy_to_struct_field(&offset, str, st_data.b, sizeof(st_data.b));
	copy_to_struct_field(&offset, str, st_data.c, sizeof(st_data.c));

	printf("----------------------------\n");

	printf("a: %s\n", st_data.a);
	printf("b: %s\n", st_data.b);
	printf("c: %s\n", st_data.c);

	/*
	
	printf("----------------------------\n");
	printf("is final letter null ? %d\n ", (st_data.a[4] == '\0'));
	printf("is final letter null ? %d\n ", (st_data.b[3] == '\0'));
	printf("is final letter null ? %d\n ", (st_data.c[2] == '\0'));

	*/

	return 0;
}

void copy_to_struct_field(int* offset, char* src_str, char* dest_str, const int dest_str_size) {

	char* pivot_str = src_str + (*offset);

	//strncpy_s(dest_str, dest_str_size, src_str + (*offset), dest_str_size - 1);

	strncpy(dest_str, pivot_str, dest_str_size - 1);
	dest_str[dest_str_size - 1] = '\0';

	*offset += (dest_str_size - 1);
}
