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

Barrier::Barrier(int x, int y) : Point(x, y) {};

void Point::move(int offsetX, int offsetY)
{
	this->x += offsetX;
	this->y += offsetY;
}


Aster::Aster(int x, int y) : Point(x, y) {};

void Aster::onKeyDown(WPARAM wParam) {
	int step = 30;
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


void Aster::show(HDC hdc)
{
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	Ellipse(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Ellipse(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);

	SelectObject(hdc, GetStockObject(WHITE_PEN)); 

	
	Ellipse(hdc, 120 + x + width, 115 + y + width, 125 + x + width, 120 + y + width);
	Ellipse(hdc, 135 + x + width, 165 + y + width, 140 + x + width, 170 + y + width);

	SelectObject(hdc, pen1);
	DeleteObject(pen1);
}

bool Aster::hit(int left, int top, int right, int bottom)
{
	return (!( (x > right) || (y > bottom) || ((x + 200 + 2 * width) < left) || ((y + 200 + 2 * width) < top) ));
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

Aster_2::Aster_2(int x, int y) : Barrier(x, y) {};

void Aster_2::show(HDC hdc)
{
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 40 + x + width, 40 + y + width, 140 + x + width, 140 + y + width);
	Ellipse(hdc, 60 + x + width, 60 + y + width, 80 + x + width, 80 + y + width);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen1);
}


aster_dmg_1::aster_dmg_1(int x, int y) : Aster(x, y) {};

void aster_dmg_1::show(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width, RGB(255, 255, 255));
	SelectObject(hdc, pen1);

	// Рисуем астероид
	Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	Ellipse(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Ellipse(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);

	SelectObject(hdc, pen2);
	Pie(hdc, 90 + x + width, 170 + y + width, 158 + x + width, 190 + y + width, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	


	SelectObject(hdc, pen1);

	Ellipse(hdc, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);

	SelectObject(hdc, pen2);
	Pie(hdc, 80 + x + width, 155 + y + width, 125 + x + width, 195 + y + width, 90 + x + width, 170 + y + width, 130 + x + width, 190 + y + width);
	


	SelectObject(hdc, pen1);
	DeleteObject(pen1);
}


aster_dmg_2::aster_dmg_2(int x, int y) :aster_dmg_1(x,y) {};

void aster_dmg_2::show(HDC hdc) {
	HPEN pen1 = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	HPEN pen2 = CreatePen(PS_SOLID, width, RGB(255, 255, 255));




	SelectObject(hdc, pen1);
	Ellipse(hdc, 100 + x + width, 100 + y + width, 200 + x + width, 200 + y + width);
	Ellipse(hdc, 120 + x + width, 120 + y + width, 130 + x + width, 130 + y + width);
	Ellipse(hdc, 130 + x + width, 140 + y + width, 142 + x + width, 152 + y + width);
	Ellipse(hdc, 140 + x + width, 175 + y + width, 160 + x + width, 190 + y + width);



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




