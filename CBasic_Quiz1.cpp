#include <stdio.h>

int main(void) {
	// 1. �� ���� ������ �Է¹޾� ū ������ ���� ���� �� ���� ����ϱ�.
	/*int n1, n2;
	printf("�Է� : ");
	scanf("%d %d", &n1, &n2);

	if (n1 > n2) printf("%d - %d = %d", n1, n2, n1 - n2);
	else printf("%d - %d = %d", n2, n1, n2 - n1);*/

	// 2. ������ �Է¹޾� A, B, C, D, F�� ����ϱ�.
	/*int score = -1;
	char grade;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &score);
	
	if (score >= 90 && score <= 100) grade = 'A';
	else if (score >= 80 && score < 90) grade = 'B';
	else if (score >= 70 && score < 80) grade = 'C';
	else if (score >= 60 && score < 70) grade = 'D';
	else grade = 'F';
	printf("%d���� ���� ����� \'%c\' �Դϴ�. ", score, grade);
	if (grade == 'F') printf("�ǰ��Դϴ�. ���� �б⿡ �� ������~");
	*/

	// 2-1. Switch Case ������ ����ϱ�.
	/*
	int score;
	char grade;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &score);
	switch (score / 10) {
	case 10: case 9: grade = 'A'; break;
	case 8: grade = 'B'; break;
	case 7: grade = 'C'; break;
	case 6: grade = 'D'; break;
	default: grade = 'F'; break;
	}
	printf("%d���� ���� ����� \'%c\' �Դϴ�. ", score, grade);
	if (grade == 'F') printf("�ǰ��Դϴ�. ���� �б⿡ �� ������~");
	*/

	// 3. 1���� 9999������ ������ ���ԵǴ� ���� N�� �Ųٷ� ����ϱ�.
	/*int n;
	scanf("%d", &n);

	int a = n / 1000;
	int b = n % 1000 / 100;
	int c = n % 100 / 10;
	int d = n % 10;

	printf("%d%d%d%d", d, c, b, a);*/

	return 0;
}