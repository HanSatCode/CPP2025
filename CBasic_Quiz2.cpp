#include <stdio.h>
#include <math.h>

double getDistance(int a1, int b1, int a2, int b2) {
	int a = a2 - a1;
	int b = b2 - b1;
	return sqrt(a * a + b * b);
}

double solve(int x1, int y1, int x2, int y2, int x3, int y3){
	double A = getDistance(x1, y1, x2, y2);
	double B = getDistance(x2, y2, x3, y3);
	double C = getDistance(x3, y3, x1, y1);
	return A + B + C;
}
int main(void) {
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0;
	
	printf("ù ��° ��ǥ�� �Է��ϼ��� : ");
	scanf("%d %d", &x1, &y1);
	printf("�� ��° ��ǥ�� �Է��ϼ��� : ");
	scanf("%d %d", &x2, &y2);
	printf("�� ��° ��ǥ�� �Է��ϼ��� : ");
	scanf("%d %d", &x3, &y3);

	printf("�ﰢ�� �ѷ��� ���̴� %lf �Դϴ�.", solve(x1, y1, x2, y2, x3, y3));
}