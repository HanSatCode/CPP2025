#include<iostream>
using namespace std;

class Character {
protected:
	double x, y, hp, mp, range, speed;
public:
	Character(double x, double y, double hp, double mp, double range, double speed) {
		this->x = x; this->y = y;
		this->hp = hp;
		this->mp = mp;
		this->range = range; this->speed = speed;
	}
	virtual void attack(Character& c) = 0;
	virtual bool hpFull() = 0;
	virtual bool mpFull() = 0;
	virtual void hpMax() = 0;
	virtual void mpMax() = 0;
	void move(double dstX, double dstY) {
		double mx, my;
		mx = my = speed;
		if (dstX < x)
			mx = -mx;
		for (; int(dstX * 10) != int(x * 10); x += mx);
		if (dstY < y)
			my = -my;
		for (; int(dstY * 10) != int(y * 10); y += my);
	}
	void punch(Character& c) {
		double dist = distance(*this, c);
		if (c.hp > 0 && dist <= 1)
			c.hp -= 1;
		else
			cout << "���� �� ����� �����ϴ�." << endl;
	}
	void info() {
		cout << "pos = (" << x << ", " << y << "), hp = " << hp << ", mp = " << mp << endl;
	}
	double distance(Character& c1, Character& c2) {
		double a = c1.x - c2.x;
		double b = c1.y - c2.y;
		double cSQ = a * a + b * b;
		return sqrt(cSQ);
	}
	friend class SwordsMan;
	friend class Priest;
	friend class Wizard;
	friend class Archer;
};

// ������ ��� -----------------------------------------------------

class SwordsMan : public Character {
public:
	SwordsMan(double x = 0, double y = 0) : Character(x, y, 80, 0, 2, 0.1) { }
	virtual bool hpFull() { return hp >= 80; }
	virtual bool mpFull() { return mp >= 0; }
	virtual void hpMax() { hp = 80; }
	virtual void mpMax() { mp = 0; }

	virtual void attack(Character& c) {
		double dist = distance(*this, c);
		if (c.hp > 0 && dist <= range)	// range�� �������� ����.
			c.hp -= 10; // ������ġ�� c�� ���忡�� �ܺ���. friend ���� ���Ұ�
		else cout << "���� �� ����� �����ϴ�." << endl;
	}
	void run(double dstX, double dstY)
	{
		if (hp > 20) {
			double temp = speed;
			speed = 0.5;
			move(dstX, dstY);
			speed = temp;
			hp -= 5;
		}
	}
};



class Priest : public Character {
public:
	Priest(double x = 0, double y = 0) : Character(x, y, 60, 80, 5, 0.1) { }

	virtual bool hpFull() { return hp >= 60; }
	virtual bool mpFull() { return mp >= 80; }
	virtual void hpMax() { hp = 60; }
	virtual void mpMax() { mp = 80; }

	virtual void attack(Character& c) { punch(c); }

	void heal(Character& c) {
		double dist = distance(*this, c);
		if (!c.hpFull() && dist <= range && mp >= 5) {	// range�� �������� ����.
			c.hp += 10; // ������ġ�� c�� ���忡�� �ܺ���. friend ���� ���Ұ�
			if (c.hpFull()) c.hpMax();
			mp -= 5;
		}
		else cout << "���� �� ����� ���ų�, mp�� �����մϴ�." << endl;
	}

	void charge(Character& c) {
		double dist = distance(*this, c);
		if (!c.mpFull() && dist <= range && mp >= 5) {	// range�� �������� ����.
			mp -= 5;
			c.mp += 10; // ������ġ�� c�� ���忡�� �ܺ���. friend ���� ���Ұ�
			if (c.mpFull()) c.mpMax();
		}
		else cout << "���� �� ����� ���ų�, mp�� �����մϴ�." << endl;
	}
	void pain() {
		if (hp > 5) {
			hp -= 5;
			mp += 20;
			if (mpFull()) mpMax();
		}
	}
};



class Wizard : public Character {
public:
	Wizard(int x, int y) : Character(x, y, 30, 80, 5, 0.1) {};

	virtual bool hpFull() { return hp >= 30; }
	virtual bool mpFull() { return mp >= 80; }
	virtual void hpMax() { hp = 30; }
	virtual void mpMax() { mp = 80; }

	virtual void attack(Character& c) {
		double dist = distance(*this, c);
		if (c.hp > 0 && dist <= range && this->mp >= 5) { // range�� �������� ����.
			c.hp -= 5; // ������ġ�� c�� ���忡�� �ܺ���. friend ���� ���Ұ�
			this->mp -= 5;
		}
		else cout << "���� �� ����� ���ų�, mp�� �����մϴ�." << endl;
	}
	void teleport(int x, int y) {
		if(this->mp >= 10) {
			this->x = x; this->y = y;
			mp -= 10;
		}
		else cout << "mp�� �����մϴ�." << endl;
	}
};



class Archer : public Character {
	int arrows;
public:
	Archer(int x, int y) : Character(x, y, 40, 5, 10, 0.2) { this->arrows = 5; }

	virtual bool hpFull() { return hp >= 80; }
	virtual bool mpFull() { return mp >= 0; }
	virtual void hpMax() { hp = 80; }
	virtual void mpMax() { mp = 0; }
	bool arrowsFull() { return this->arrows >= 5; }
	
	virtual void attack(Character& c) {
		double dist = distance(*this, c);
		if (c.hp > 0 && dist <= range && this->arrows >= 1) {// range�� �������� ����.
			c.hp -= 5; // ������ġ�� c�� ���忡�� �ܺ���. friend ���� ���Ұ�
			this->arrows--;
		}
		else {
			cout << "���� �� ����� ���ų�, ȭ���� ������ �����մϴ�." << endl;
		}
	}
	void reload() {
		arrows += 2;
		if (arrowsFull()) arrows = 5;
	}
	void info() { // �������̵� (ȭ�찹���� ������)
		cout << "pos = (" << x << ", " << y << "), hp = " << hp << ", mp = " << mp << ", arrows = " << arrows << endl;
	}
};



int main()
{
	Character* c[5];

	c[0] = new SwordsMan(2, 0);
	c[1] = new SwordsMan(5, 5);
	c[2] = new Priest(3, 2);
	c[3] = new Wizard(0, 0);
	c[4] = new Archer(0, 0);

	((SwordsMan*)c[1])->run(3, 1);
	c[1]->attack(*c[0]);
	c[2]->attack(*c[1]);
	((Priest*)c[2])->heal(*c[1]);
	((Priest*)c[2])->charge(*c[2]);
	((Archer*)c[4])->reload();
	((Wizard*)c[3])->teleport(1, 2);
	((Archer*)c[4])->reload();
	for (int i = 0; i < 4; i++)
	{
		c[i]->info(); // ���ʿ� c���� �� �������� ���ɽ��� �Ǿ� �ֱ� ������
					// �� ��쿡�� �θ��� info�� ��µ�. Archer�� �ٿ��ɽ��� �ʿ�
	}
	((Archer*)c[4])->info();
	//-----------------------------
	for (int i = 0; i < 6; i++) {
		((Archer*)c[4])->attack(*c[3]);
		((Archer*)c[4])->info();
		((Wizard*)c[3])->info();
	}
	
	return 0;
}