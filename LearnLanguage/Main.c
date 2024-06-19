#include <stdio.h>
#include "Main.h"

typedef struct {
	char field_1[4];
	char field_2[4];
} A_STRUCT;

typedef struct {
	char some_str[50];
} B_STRUCT;

int main() {

	do_struct();
	//do_string();
	//do_struct_2();
	// do_struct_3();
	// file_read();

	return 0;
}

void do_struct()
{
	const char* some_data = "Hello, World!";
	B_STRUCT b_struct;
	strncpy(b_struct.some_str, some_data, sizeof(b_struct.some_str) - 1);

	// struct MyStruct *a = (struct MyStruct *)some_data;
	A_STRUCT* a_struct = (B_STRUCT*)b_struct.some_str;
	printf("a1: %s\n", a_struct->field_1);
	printf("a2: %s", a_struct->field_2);
}

void do_string() {
	// printf("helloooow\rworld");
	
	//char str[4] = "abcd";  // 문자열에 null 이 없는 경우
	//char str[5] = "abcd";
	//char str[5] = "abcd\0";
	char str[10] = "abc\0def";
	printf("%s", str);
}

void do_struct_2() {
	char some_data[50] = "123456789";
	//char some_data[50] = "1234\056789";

	A_STRUCT* a_struct = (A_STRUCT *) some_data;

	printf(	"a1: %s\n"
			"a2: %s", 
			a_struct->field_1, 
			a_struct->field_2);
}

void do_struct_3() {

	char a[50] = "";

	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	//printf("%d\n", (a[0] == NULL));
	//printf("%d\n", (a[1]==NULL));
	//printf("%d\n", (a[3]==NULL));

}
