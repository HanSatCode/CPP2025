#pragma once

class Circles{
	// �� static ������ ����� ���ÿ� �ʱ�ȭ�� �� ������?
	// å �������� ���� ���ʼ�

	static int numOfCircles;
	int radius;
public:
	Circles(int r = 1);
	~Circles();
	double getArea();
	static int getNumOfCircles();
};

int Circles::numOfCircles = 10;
