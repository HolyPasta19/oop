#include "Figures.hpp"


Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Location::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
	
}

int Location::getX() { return x; }
int Location::getY() { return y; }


Point::Point(int x, int y) : Location(x, y) {};

void Point::show(HDC hdc)
{
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}



void Point::move(int offsetX, int offsetY)
{ 

	this->x += offsetX;
	this->y += offsetY;
	 
}

Barrier::Barrier(int x, int y) : Point(x, y) {};

Plane::Plane(int x, int y) : Point(x, y){};

void Plane::onKeyDown(WPARAM wParam) {
	int step = 50;
	switch (wParam) {
	case 'W':
		move(0, -step);
		break;
	case 'S':
		move(0, step);
		break;
	case 'A':
		move(-step, 0);
		break;
	case 'D':
		move(step, 0);
		break;
	}
}



void  Plane::showContour(HDC hdc)
{
	//HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	//SelectObject(hdc, pen1);


	//Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	//DeleteObject(pen1);
}


/*
void Plane::show(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, width , RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width *2, RGB(255, 255, 255));
	SelectObject(hdc, pen);

	Rectangle(hdc, 100 + x, 100 + y, 300 + x, 140 + y);


	POINT nose[3];
	nose[0] = { 100 + x, 100 + y };
	nose[1] = { 40 + x, 138 + y };
	nose[2] = { 100 + x, 138 + y };

	Polygon(hdc, nose, 3);


	POINT wing1[3];
	
	wing1[0] = { 150 + x, 120 + y };
	wing1[1] = { 260 + x, 220 + y };
	wing1[2] = { 250 + x, 120 + y };

	Polygon(hdc, wing1, 3);

	POINT wing2[3];

	wing2[0] = { 170 + x, 100 + y };
	wing2[1] = { 250 + x, 60 + y };
	wing2[2] = { 244 + x, 100 + y };

	Polygon(hdc, wing2, 3);
	
	
	
	
	POINT tail[3] ;

	tail[0] = { 270 + x, 120 + y };
	tail[1] = { 300 + x, 70 + y };
	tail[2] = { 300 + x, 120 + y };

	Polygon(hdc, tail, 3);

	SelectObject(hdc, pen2);

	MoveToEx(hdc, 270 + x, 120 + y, NULL);
	LineTo(hdc, 295 + x, 120 + y);
	
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
	DeleteObject(pen2);
}*/

void  Plane::showDmg(HDC hdc) {
	//HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	//SelectObject(hdc, pen1);
	//Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
//	DeleteObject(pen1);

	
}




void Plane::showTail(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width * 2, RGB(255, 255, 255));
	SelectObject(hdc, pen);
	POINT tail[3];

	tail[0] = { 270 + x, 120 + y };
	tail[1] = { 300 + x, 70 + y };
	tail[2] = { 300 + x, 120 + y };

	Polygon(hdc, tail, 3);

	SelectObject(hdc, pen2);

	MoveToEx(hdc, 270 + x, 120 + y, NULL);
	LineTo(hdc, 295 + x, 120 + y);
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
	DeleteObject(pen2);
}

void Plane::showWing2(HDC hdc)
{

	HPEN pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	POINT wing2[3];

	wing2[0] = { 170 + x, 100 + y };
	wing2[1] = { 250 + x, 60 + y };
	wing2[2] = { 244 + x, 100 + y };

	Polygon(hdc, wing2, 3);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);

}

void Plane::showWing1(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	POINT wing1[3];

	wing1[0] = { 150 + x, 120 + y };
	wing1[1] = { 260 + x, 220 + y };
	wing1[2] = { 250 + x, 120 + y };

	Polygon(hdc, wing1, 3);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}

void Plane::showNose(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	POINT nose[3];
	nose[0] = { 100 + x, 100 + y };
	nose[1] = { 40 + x, 138 + y };
	nose[2] = { 100 + x, 138 + y };

	Polygon(hdc, nose, 3);
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}

void Plane::showBody(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	Rectangle(hdc, 100 + x, 100 + y, 300 + x, 140 + y);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}

bool Plane::hit(int left, int top, int right, int bottom)
{
	return (!( (x > right) || (y > bottom) || ((x + 200 + 2 *width) < left) || ((y + 200 + 2 *width) < top) ));
}


Rocket::Rocket(int x, int y) : Barrier(x, y) {};

void Rocket::show(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	// Рисуем нос ракеты
	POINT nose[3];
	nose[0] = { 30 + x, 0 + y };
	nose[1] = { 50 + x, -30 + y };
	nose[2] = { 70 + x, 0 + y };

	Polygon(hdc, nose, 3);

	// Рисуем корпус ракеты
	Rectangle(hdc, 30 + x, 0 + y, 70 + x, 100 + y);

	// Рисуем крылья
	POINT wing1[3];
	wing1[0] = { 30 + x, 50 + y };
	wing1[1] = { 10 + x, 70 + y };
	wing1[2] = { 30 + x, 90 + y };
	Polygon(hdc, wing1, 3);

	

	POINT wing2[3];
	wing2[0] = { 70 + x, 50 + y };
	wing2[1] = { 90 + x, 70 + y };
	wing2[2] = { 70 + x, 90 + y };
	Polygon(hdc, wing2, 3);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}

Plane_2::Plane_2(int x, int y) : Barrier(x, y) {};

void Plane_2::show(HDC hdc)
{
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 40 + x + width, 40 + y + width, 140 + x + width, 140 + y + width);
	Ellipse(hdc, 60 + x + width, 60 + y + width, 80 + x + width, 80 + y + width);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen1);
}



plane_dmg_1::plane_dmg_1(int x, int y) : Plane(x, y) {};

void  plane_dmg_1::showDmg(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);
	Ellipse(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Ellipse(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);
	DeleteObject(pen1);


}


plane_dmg_2::plane_dmg_2(int x, int y) : Plane(x, y) {};

void  plane_dmg_2::showContour(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width, RGB(255, 255, 255));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	SelectObject(hdc, pen2);
	Pie(hdc, 90 + x + width, 170 + y + width, 158 + x + width, 190 + y + width, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);



	SelectObject(hdc, pen1);

	Ellipse(hdc, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);

	SelectObject(hdc, pen2);
	Pie(hdc, 80 + x + width, 155 + y + width, 125 + x + width, 195 + y + width, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);
	SelectObject(hdc, pen1);
	DeleteObject(pen1);

}




plane_dmg_3::plane_dmg_3(int x, int y) : Plane(x, y) {}


void  plane_dmg_3::showContour(HDC hdc)
{
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width, RGB(255, 255, 255));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	SelectObject(hdc, pen2);
	Pie(hdc, 90 + x + width, 170 + y + width, 158 + x + width, 190 + y + width, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	Pie(hdc, 180 + x + width, 100 + y + width, 220 + x + width, 160 + y + width, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);


	SelectObject(hdc, pen1);

	Ellipse(hdc, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);
	Ellipse(hdc, 170 + x + width, 122 + y + width, 200 + x + width, 170 + y + width);

	SelectObject(hdc, pen2);
	Pie(hdc, 80 + x + width, 155 + y + width, 125 + x + width, 195 + y + width, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);


	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen1);
	DeleteObject(pen2);
}

plane_dmg_4::plane_dmg_4(int x, int y) : plane_dmg_3(x, y) {};
void  plane_dmg_4::showDmg(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);
	Ellipse(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Ellipse(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);
	DeleteObject(pen1);


}

plane_dmg_5::plane_dmg_5(int x, int y) : plane_dmg_2(x, y) {};
void  plane_dmg_5::showDmg(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);
	Rectangle(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Rectangle(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Rectangle(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);
	DeleteObject(pen1);


}



