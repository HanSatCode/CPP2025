#pragma once

class Circles{
	// 왜 static 변수는 선언과 동시에 초기화할 수 없을까?
	// 책 연습문제 많이 보십쇼

	static int numOfCircles;
	int radius;
public:
	Circles(int r = 1);
	~Circles();
	double getArea();
	static int getNumOfCircles();
};

int Circles::numOfCircles = 10;
