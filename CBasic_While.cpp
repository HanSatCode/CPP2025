#include <stdio.h>

int main(void) {
	int cur = 2;
	int is = 0;

	while (cur <= 9) {
		is = 1;
		while (is <= 9) {
			printf("%d¡¿%d£½%d\t", cur, is, cur * is);
			is++;
		}
		printf("\n");
		cur++;
	}
	return 0;
}