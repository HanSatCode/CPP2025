#include <stdio.h>

int main(void) {
	// 1. 두 자연수를 입력받은 후, 아래 모양을 출력
	/*
	int h,w = 0;
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// 2. 양의 정수 n을 입력받은 후, 아래 모양을 출력하기
	/*
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// 3. 피보나치 수열
	/*
	int n = 0;
	scanf("%d", &n);

	int n1 = 0;
	int n2 = 1;
	printf("%d ", n1);
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", n2);
		int temp = n2;
		n2 += n1;
		n1 = temp;
	}
	*/

	// 4. 다음 모양을 출력하기


	// 막간퀴즈. 정사각형에 띠두르기
	int m;
	scanf("%d", &m);
	char pat = '*';

	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) pat = '*';
		else pat = '-';
		for (int j = 0; j < m; j++) {
			printf("%c", pat);
		}
		printf("\n");
	}
}