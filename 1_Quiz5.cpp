#include <stdio.h>

int main(void) {
	int n;
	printf("ÀÔ·Â(Á¤¼ö 1°³) = ");
	scanf("%d", &n);
	if (n % 2 == 0) printf("%s\n", "Â¦¼ö");
	else printf("%s\n", "È¦¼ö");
}