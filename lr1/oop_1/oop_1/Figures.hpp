#ifndef LR_OOP1_FIGURES
#define LR_OOP1_FIGURES

#include <windows.h>


class Location;
class Point;
class Aster;


class Location
{
 protected:
	int x;
	int y;
 public:
	Location(int x, int y);
};

class Point : public Location
{
 public:
	Point(int x, int y);
	virtual	void show(HDC hdc);
	void move(int offsetX, int offsetY);
	virtual void onKeyDown(WPARAM wParam) {};
};

class Aster : public Point
{
 protected:
	int width = 4;
 public:
	Aster(int x, int y);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};

#endif
