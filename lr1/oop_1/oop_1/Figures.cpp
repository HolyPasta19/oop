#include "Figures.hpp"


Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

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

Aster::Aster(int x, int y) : Point(x, y) {};

void Aster::onKeyDown(WPARAM wParam) {
	int step = 5;
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
	HPEN pen1= CreatePen(PS_SOLID, width, RGB(0, 0, 0));
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
