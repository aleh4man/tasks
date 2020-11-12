#include <stdio.h>
int main() {
	char st[101] = { '0' }, word[101] = { '0' }, wov[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
	int a = 0, b, c, count = 0;
	printf("Input the string (no more than 100 symbols!): ");
	fgets(st, 101, stdin);
	while (st[a] != 0) {
		if ((st[a] <= 64) or ((st[a] >= 91) and (st[a] <= 96)) or (st[a] >= 123)) {
			c = 0;
			for (count; count <= a - 1; count++) {
				word[c] = st[count];
				c++;
			}
			count = 1;
			if (c > 0) {
				for (b = 0; b <= 11; b++) {
					if (word[c - 1] == wov[b]) {
						b = 12;
						count = 0;
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
						b = 12;
						count = 0;
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