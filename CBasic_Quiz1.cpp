#include <stdio.h>

int main(void) {
	// 1. 두 개의 정수를 입력받아 큰 수에서 작은 수를 뺀 차를 출력하기.
	/*int n1, n2;
	printf("입력 : ");
	scanf("%d %d", &n1, &n2);

	if (n1 > n2) printf("%d - %d = %d", n1, n2, n1 - n2);
	else printf("%d - %d = %d", n2, n1, n2 - n1);*/

	// 2. 성적을 입력받아 A, B, C, D, F를 출력하기.
	/*int score = -1;
	char grade;
	printf("성적을 입력하세요 : ");
	scanf("%d", &score);
	
	if (score >= 90 && score <= 100) grade = 'A';
	else if (score >= 80 && score < 90) grade = 'B';
	else if (score >= 70 && score < 80) grade = 'C';
	else if (score >= 60 && score < 70) grade = 'D';
	else grade = 'F';
	printf("%d점에 대한 등급은 \'%c\' 입니다. ", score, grade);
	if (grade == 'F') printf("실격입니다. 다음 학기에 또 만나요~");
	*/

	// 2-1. Switch Case 문으로 출력하기.
	/*
	int score;
	char grade;

	printf("성적을 입력하세요 : ");
	scanf("%d", &score);
	switch (score / 10) {
	case 10: case 9: grade = 'A'; break;
	case 8: grade = 'B'; break;
	case 7: grade = 'C'; break;
	case 6: grade = 'D'; break;
	default: grade = 'F'; break;
	}
	printf("%d점에 대한 등급은 \'%c\' 입니다. ", score, grade);
	if (grade == 'F') printf("실격입니다. 다음 학기에 또 만나요~");
	*/

	// 3. 1부터 9999까지의 범위에 포함되는 정수 N을 거꾸로 출력하기.
	/*int n;
	scanf("%d", &n);

	int a = n / 1000;
	int b = n % 1000 / 100;
	int c = n % 100 / 10;
	int d = n % 10;

	printf("%d%d%d%d", d, c, b, a);*/

	return 0;
}