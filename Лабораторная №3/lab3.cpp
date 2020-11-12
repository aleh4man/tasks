#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max_abs_num(int* arr) {
	int a, maxn = arr[0], maxon = 0;
	for (a = 1; a <= 9; a++) {
		if (arr[a] < 0) {
			if (arr[a] * -1 > maxn) {
				maxn = arr[a] * -1;
				maxon = a;
			}
		}
		else if (arr[a] > maxn) {
			maxn = arr[a];
			maxon = a;
		}
	}
	if (arr[maxon] < 0) {
		maxn = arr[maxon];
	}
	return maxn;
}

int main() {
	int i, m[10] = { '0' }, c;
	for (i = 0; i <= 9; i++) {
		printf("Input number %d: ", i + 1);
		c = scanf("%d", &m[i]);
		if (c != 1) {
			printf("You should enter only numbers without letters!");
			return printf("\nRestart the program!");
		}
	}
	printf("Max number by its module - %d", max_abs_num(m));
	return 0;
}