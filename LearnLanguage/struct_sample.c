#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct {
	char a[2 + 1];
	char b[2 + 1];
	char* c;

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
void printf_structure_addr(ST_DATA* st_data) {

	char* addr_a_0 = st_data->a;
	printf("Address of a 0 :  %p\n", (void*)addr_a_0);

	char* addr_a_1 = &(st_data->a[1]);
	printf("Address of a 1 :  %p\n", (void*)addr_a_1);

	char* addr_a_2 = &(st_data->a[2]);
	printf("Address of a 2 :  %p\n", (void*)addr_a_2);

	char* addr_b_0 = &(st_data->b[0]);
	printf("Address of b 0 :  %p\n", (void*)addr_b_0);

	char* addr_b_1 = &(st_data->b[1]);
	printf("Address of b 1 :  %p\n", (void*)addr_b_1);

	char* addr_b_2 = &(st_data->b[2]);
	printf("Address of b 2 :  %p\n", (void*)addr_b_2);
};

void call_by_structure_str1(char* str) {
	printf("call_by_structure_str1 :: before str: %s\n", str);
	strcpy(str, "qw");
	printf("call_by_structure_str1 :: after str: %s\n", str);
}

void call_by_structure_str2(char** str) {
	printf("call_by_structure_str2 :: before str: %s\n", *str);
	strcpy(*str, "qw");
	printf("call_by_structure_str2 :: after str: %s\n", *str);
}

int main() {

	//ST_DATA st_data = {""};
	ST_DATA st_data;
	memset(st_data.a, 0, sizeof(st_data.a));
	memset(st_data.b, 0, sizeof(st_data.b));

	/*
	strcpy(st_data.a, "xy");
	printf("before st.a: %s\n", st_data.a);
	char* str = st_data.a;
	call_by_structure_str1(str);
	printf("after st.a: %s\n", st_data.a);
	*/

	printf("\n\n");

	st_data.c = (char*)malloc((2 + 1) * sizeof(char));
	if (st_data.c == NULL) {
		perror("Failed to allocate memory");
		return 1;
	}
	strcpy(st_data.c, "xy");
	printf("before st.c: %s\n", st_data.c);

	char* str2 = st_data.c;

	call_by_structure_str2(&str2);

	printf("after st.c: %s\n", st_data.c);

	free(st_data.c);

	// printf_structure_addr(&st_data);
	// convert_struct1(&st_data, str);
	// parse_null();
	// meta_data();
	// check_struct_field_size(st_data.a);

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
