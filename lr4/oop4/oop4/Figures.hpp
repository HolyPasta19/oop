#ifndef LR_OOP2_FIGURES
#define LR_OOP2_FIGURES

#include <windows.h>


class Location;
class Point;
class Barrier;

class HitBox;

class Aster;

class Rocket;
class Aster_2;

class aster_dmg_1;
class aster_dmg_2;
class aster_dmg_3;



class Location
{
 protected:
	int x;
	int y;
 public:
	Location(int x, int y);
	void setXY(int x, int y);
	int getX();
	int getY();
	virtual void show(HDC hdc) = 0;
};

class Point : public Location
{
 public:
	Point(int x, int y);
	void move(int offsetX, int offsetY);
	virtual void show(HDC hdc);
};

class HitBox {
	virtual int getRight() = 0;
	virtual int getBottom() = 0;
};

class Barrier : public Point, public HitBox
{
 public:

	 int width = 0;
	 Barrier(int x, int y);
	 int right = 100;
	 int bottom = 100;
	 int getRight();
	 int getBottom();
};

class Aster : public Point, public HitBox
{
 protected:
	int width = 3;
 public:
	Aster(int x, int y);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
	int getRight();
	int getBottom();
	bool hit(int left, int top, int right, int bottom);
};

class Rocket : public Barrier
{
 public:
	 Rocket(int x, int y);
	 void show(HDC hdc);
};

class Aster_2 : public Barrier
{
 public:
	Aster_2(int x, int y);
	void show(HDC hdc);
};

class aster_dmg_1 : public Aster
{
 public:
	 aster_dmg_1(int x, int y);
	 void show(HDC hdc);
};

class aster_dmg_2 : public Aster
{
 public:
	aster_dmg_2(int x, int y);
	void show(HDC hdc);
};

class aster_dmg_3 : public Aster
{
 public:
	aster_dmg_3(int x, int y);
	void show(HDC hdc);
};

#endif
