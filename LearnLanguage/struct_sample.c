#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct {
	char a[2 + 1];
	char b[2 + 1];
} ST_DATA;


typedef struct {
	size_t offset;
	size_t size;
} FiledInfo;

FiledInfo fields[] = {
		{ offsetof(ST_DATA, a), sizeof(((ST_DATA*)0)->a) },
		{ offsetof(ST_DATA, b), sizeof(((ST_DATA*)0)->b) }
};

// void convert_struct1(ST_DATA* st_data, char* str);
void parse_null();
void meta_data();
void check_struct_field_size(char* str);

int main() {

	ST_DATA st_data = {""};
	//char* str = "1234";

	// convert_struct1(&st_data, str);
	// parse_null();
	// meta_data();
	//check_struct_field_size(st_data.a);

	//printf("a: %s\n", st_data.a);
	//printf("b: %s\n", st_data.b);

	return 0;
}

void check_struct_field_size(char* str) {

	printf(
		"str: %s \n"
		"str size: %d  \n", 
		str, 
		sizeof(str));

	printf(
		"str: %s \n"
		"str size: %d  \n",
		*str,
		sizeof(*str));
}

void meta_data() {
	for (int i = 0; i < 2; i++) {
		printf("field :%d, offset: %zu, size: %zu\n", i, fields[i].offset, fields[i].size);
	}
}

void parse_null() {
	char str2[] = "12345678";
	printf("str: %s\n", str2);
	str2[4] = '\0';
	printf("str with NULL: %s\n", str2);
}

/*
void convert_struct1(ST_DATA* st_data, char* str) {
	strncpy((*st_data).a, str, 2);
	st_data->a[2] = '\0';

	strncpy(st_data->b, str + 2, 2);
	st_data->b[2] = '\0';
}
*/
