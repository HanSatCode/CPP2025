#pragma once

class Circles{
	static int numOfCircles;
	int radius;
public:
	Circles(int r = 1);
	~Circles();
	double getArea();
	static int getNumOfCircles();
};
