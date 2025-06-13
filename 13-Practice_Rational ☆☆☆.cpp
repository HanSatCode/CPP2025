#include<iostream>
using namespace std;

class Rational {
	int numer, denom;
public:
	Rational(int numer, int denom) {
		if (denom == 0) throw string("�и�� 0�� �ɼ� ����");
		if (denom < 0) { // ���࿡ �и� ������� (���ڿ� �и��� ��ȣ�� �ٲ��ش�)
			numer *= -1;
			denom *= -1;
		}
		int gcd = getGCD(abs(numer), denom);
		this->numer = numer / gcd;
		this->denom = denom / gcd;
	}
	int getGCD(int a, int b) { // �ִ����� ���ϱ� (��Ŭ���� ȣ����)
		while (b) {
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
	Rational operator+(Rational r) {
		int numer = this->numer * r.denom + r.numer * this->denom;
		int denom = this->denom * r.denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd); 
	}
	Rational operator+(int n) {
		int numer = this->numer + n * this->denom;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator-(int n) {
		int numer = n * this->denom - this->numer;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator*(int n) {
		int numer = this->numer * n;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator/(int n) {
		if (n == 0) throw string("�и�� 0�� �ɼ� ����");
		int numer = this->numer;
		int denom = this->denom * n;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}

	friend Rational operator+(int n, Rational r);
	friend Rational operator-(int n, Rational r);
	friend Rational operator*(int n, Rational r);
	friend Rational operator/(int n, Rational r);

	Rational operator-(Rational r) {
		int numer = this->numer * r.denom - r.numer * this->denom;
		int denom = this->denom * r.denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator*(Rational r) {
		int numer = this->numer * r.numer;
		int denom = this->denom * r.denom;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator/(Rational r) {
		if (r.numer == 0) throw string("�и�� 0�� �ɼ� ����");
		int numer = this->numer * r.denom;
		int denom = this->denom * r.numer;
		int gcd = getGCD(abs(numer), denom); // ���м��� �����
		return Rational(numer / gcd, denom / gcd);
	}
	Rational& operator+=(Rational r){ // ������ ��Ȱ��
		*this = *this + r;
		return *this;
	}
	Rational& operator+=(int n){ // ������ ��Ȱ��
		*this = *this + n;
		return *this;
	}
	Rational& operator++(){ // ����
		*this = *this + 1;
		return *this;
	}
	Rational operator++(int n){ // ����
		Rational temp = *this;
		*this = *this + 1;
		return temp;
	}

	void show(){
		if (numer == 0)
			cout << 0 << endl;
		else
			cout << numer << "/" << denom << endl;
	}
};

// �տ� int�� ���� ���� �����ϱ� ���� friend �Լ��� ����

Rational operator+(int n, Rational r){ 
	int numer = r.numer + n * r.denom;
	int denom = r.denom;
	return Rational(numer, denom);
}
Rational operator-(int n, Rational r){
	int numer = n * r.denom - r.numer;
	int denom = r.denom;
	return Rational(numer, denom);
}
Rational operator*(int n, Rational r){
	int numer = r.numer * n;
	int denom = r.denom;
	return Rational(numer, denom);
}
Rational operator/(int n, Rational r){
	if (n == 0) throw string("�и�� 0�� �ɼ� ����");
	int numer = n * r.denom;
	int denom = r.numer;
	return Rational(numer, denom);
}

int main(){
	try{
		//Rational a(2, -6);
		//Rational b(0, 2);
		//Rational c(2, 0);
		//(a / 0).show();
		Rational d(3, 9);
		d.show();
	}
	catch (string msg){
		cout << msg << endl;
	}
}