//20.Ввести строку, вывести только слова, заканчивающиеся на согласную букву.

#include <stdio.h>

int main() {
	char st[100] = { '0' }, word[100] = { '0' }, wov[] = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };
	int a = 0, b, c, count = 0;

	printf("Input the string (no more than 100 symbols!): ");
	while (a < 100) {
		st[a] = getchar();
		if (st[a] == '\n') {
			st[a] = '0';
			a = 0;
			break;
		}
		a++;
	}

	while (st[a] != 0) {
		if (!((st[a] >= 'a') && (st[a] <= 'z')) || ((st[a] >= 'A') && (st[a] <= 'Z'))) {
			c = 0;
			for (count; count <= a - 1; count++) {
				word[c] = st[count];
				c++;
			}
			count = 1;
			if (c > 0) {
				for (b = 0; b <= 11; b++) {
					if (word[c - 1] == wov[b]) {
						count = 0;
						break;
					}
				}
				if (count == 1) {
					printf("%s ", word);
				}
			}
			for (b = 0; b <= c; b++)
				word[b] = 0;
			count = a + 1;
		}
		a++;
		if (st[a] == 0) {
			c = 0;
			for (count; count <= a - 1; count++) {
				word[c] = st[count];
				c++;
			}
			if (c > 0) {
				count = 1;
				for (b = 0; b <= 11; b++) {
					if (word[c - 1] == wov[b]) {
						count = 0;
						break;
					}
				}
				if (count == 1) {
					printf("%s", word);
				}
			}
		}
	}
	return 0;
}