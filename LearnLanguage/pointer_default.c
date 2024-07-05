#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "simple_syntax.h"
#include <string.h>
#include <stdarg.h>
#include "ex_string_pointer.h"


int main() {

	int a = 102030;
	printf("%d\n", a);
	printf("%p\n", a);
	printf("%p\n", &a);
	printf("%s\n", &a);
	printf("%d\n", &a);

	return 0;
}