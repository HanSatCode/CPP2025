#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n / 100 == 12) printf("���� 12�� %d��", (n % 100));
	else if (n / 100 == 0) printf("���� 12�� %d��", (n % 100));
	else if (n / 100 < 12) printf("���� %d�� %d��", n / 100, n % 100);
	else printf("���� %d�� %d��", (n / 100) - 12, n % 100);
}