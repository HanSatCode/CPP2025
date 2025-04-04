#include <stdio.h>

int getGCD(int a, int b) {
	int t = 0;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void solve(int a, int b, int c, int d) {
	int down = (b * d);
	int up = ((a * d) + (c * b));
	int div = getGCD(up, down);
	printf("정답은 %d / %d 입니다.", up/div, down/div);
}

int main(void) {
	int a = 0, b = 0;
	printf("1번 분자 분모를 입력하세요 : ");
	scanf("%d %d", &a, &b);

	int c = 0, d = 0;
	printf("2번 분자 분모 입력하세요 : ");
	scanf("%d %d", &c, &d);

	solve(a, b, c, d);

}