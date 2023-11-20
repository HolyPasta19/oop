#ifndef LR_OOP2_FIGURES
#define LR_OOP2_FIGURES

#include <windows.h>


class Location;
class Point;
class Barrier;

class Aster;

class Rocket;
class Aster_2;

class aster_dmg_1;
class aster_dmg_2;


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
};

class Point : public Location
{
 public:
	Point(int x, int y);
	void move(int offsetX, int offsetY);
	virtual void show(HDC hdc);
};

class Barrier : public Point
{
 public:
	 Barrier(int x, int y);
	 int right = 100;
	 int bottom = 100;
};

class Aster : public Point
{
 protected:
	int width = 3;
 public:
	Aster(int x, int y);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
	bool hit(int left, int top, int right, int bottom);
};

class Rocket : public Barrier
{
 protected:
	int width = 2;
 public:
	 Rocket(int x, int y);
	 void show(HDC hdc);
};

class Aster_2 : public Barrier
{
 protected:
	int width = 5;
 public:
	Aster_2(int x, int y);
	void show(HDC hdc);
};

class aster_dmg_1 : public Aster
{
 public:
	 aster_dmg_1(int x, int y);
	 void show(HDC hdc) override;
	 
};

class aster_dmg_2 : public aster_dmg_1
{
 public:
	aster_dmg_2(int x, int y);
	void show(HDC hdc) override;
	
};

#endif
