#ifndef LR_OOP2_FIGURES
#define LR_OOP2_FIGURES

#include <windows.h>


class Location;
class Point;
class Barrier;
class IPlane;
class Plane;

class Rocket;
class Plane_2;

class plane_dmg_1;
class plane_dmg_2;
class plane_dmg_3;
class plane_dmg_4;
class plane_dmg_5;


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
//interface
class IPlane 
{
public:
	//virtual void show(HDC hdc) = 0;
	virtual void showDmg(HDC hdc) = 0;
	virtual void showContour(HDC hdc) = 0;



	virtual void showBody(HDC hdc) = 0;
	virtual void showNose(HDC hdc) = 0;
	virtual void showWing1(HDC hdc) = 0; 
	virtual void showWing2(HDC hdc) = 0;
	virtual void showTail(HDC hdc) = 0;
};
//основной класс (астероид состояние 0)
class Plane : public IPlane,public Point
{
protected:
	int width = 3;

public:
	Plane(int x, int y);
	

	void onKeyDown(WPARAM wParam);
	//отрисовка
	//void show(HDC hdc);
	void showDmg(HDC hdc); 
	void showContour(HDC hdc);



	void showTail(HDC hdc);
	void showWing2(HDC hdc);
	void showWing1(HDC hdc);
	void showNose(HDC hdc);
	void showBody(HDC hdc);


	bool hit(int left, int top, int right, int bottom);
};
//ракета
class Rocket : public Barrier
{
 protected:
	int width = 2;
 public:
	 Rocket(int x, int y);
	 void show(HDC hdc);
};
//астероид(доп)
class Plane_2 : public Barrier
{
 protected:
	int width = 5;
 public:
	Plane_2(int x, int y);
	void show(HDC hdc);
};
//астероид состояние 1
class plane_dmg_1 : public Plane
{
 public:
	 plane_dmg_1(int x, int y);
	 void showDmg(HDC hdc);
	

};
//астероид состояние 2
class plane_dmg_2 : public Plane
{
public:
	plane_dmg_2(int x, int y);
	void showContour(HDC hdc);

	

};
//астероид состояние 3
class plane_dmg_3 : public Plane
{
public:
	plane_dmg_3(int x, int y);
	void showContour(HDC hdc);


};
//астероид состояние 4
class plane_dmg_4 : public plane_dmg_3
{
public:
	plane_dmg_4(int x, int y);
	void showDmg(HDC hdc);


};
//астероид состояние 5
class plane_dmg_5 : public plane_dmg_2
{
public:
	plane_dmg_5(int x, int y);
	void showDmg(HDC hdc);
};
#endif