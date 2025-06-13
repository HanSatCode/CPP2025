#include<iostream>
using namespace std;

class Rational {
	int numer, denom;
public:
	Rational(int numer, int denom) {
		if (denom == 0) throw string("분모는 0이 될수 없음");
		if (denom < 0) { // 만약에 분모가 음수라면 (분자와 분모의 부호를 바꿔준다)
			numer *= -1;
			denom *= -1;
		}
		int gcd = getGCD(abs(numer), denom);
		this->numer = numer / gcd;
		this->denom = denom / gcd;
	}
	int getGCD(int a, int b) { // 최대공약수 구하기 (유클리드 호제법)
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
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd); 
	}
	Rational operator+(int n) {
		int numer = this->numer + n * this->denom;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator-(int n) {
		int numer = n * this->denom - this->numer;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator*(int n) {
		int numer = this->numer * n;
		int denom = this->denom;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator/(int n) {
		if (n == 0) throw string("분모는 0이 될수 없음");
		int numer = this->numer;
		int denom = this->denom * n;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}

	friend Rational operator+(int n, Rational r);
	friend Rational operator-(int n, Rational r);
	friend Rational operator*(int n, Rational r);
	friend Rational operator/(int n, Rational r);

	Rational operator-(Rational r) {
		int numer = this->numer * r.denom - r.numer * this->denom;
		int denom = this->denom * r.denom;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator*(Rational r) {
		int numer = this->numer * r.numer;
		int denom = this->denom * r.denom;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational operator/(Rational r) {
		if (r.numer == 0) throw string("분모는 0이 될수 없음");
		int numer = this->numer * r.denom;
		int denom = this->denom * r.numer;
		int gcd = getGCD(abs(numer), denom); // 기약분수로 만들기
		return Rational(numer / gcd, denom / gcd);
	}
	Rational& operator+=(Rational r){ // 연산자 재활용
		*this = *this + r;
		return *this;
	}
	Rational& operator+=(int n){ // 연산자 재활용
		*this = *this + n;
		return *this;
	}
	Rational& operator++(){ // 전위
		*this = *this + 1;
		return *this;
	}
	Rational operator++(int n){ // 후위
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

// 앞에 int가 오는 것을 방지하기 위해 friend 함수로 선언

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
	if (n == 0) throw string("분모는 0이 될수 없음");
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