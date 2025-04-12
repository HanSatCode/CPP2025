#include <iostream>
using namespace std;

class Oval {
	int width;
	int height;
public:
	Oval(int w, int h);
	Oval();
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

Oval::Oval() : Oval(1, 1) { }
Oval::Oval(int w, int h) : width(w), height(h) { }
Oval::~Oval() {
	cout << "Oval ¼Ò¸ê : width = " << width << ", height = " << height << endl;
}
int Oval::getHeight() { return height; }
int Oval::getWidth() { return width; }
void Oval::set(int w, int h) { width = w; height = h; }
void Oval::show() {
	cout << "width = " << width << ", height = " << height << endl;
}

int main(void) {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ',' << b.getHeight() << endl;
}