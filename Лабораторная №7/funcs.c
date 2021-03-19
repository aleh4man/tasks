#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

long enter_num() {
	long b;
	printf("Enter the number of the type 'long': ");
	if (scanf("%d", &b) != 1) {
		printf("It isn't a number!\n");
		printf("Restart the program!");
		exit(-1);
	}
	if (b == 0) {
		printf("0");
		exit(0);
	}
	return b;
}

void ltoab(long num, char* s) {
	unsigned long a;
	size_t b = 31;
	a = (unsigned long) num;
	while (a > 0) {
		s[b] = '0' + (a % 2);
		a = a / 2;
		b--;
	}
	printf("%s\n", s);
}