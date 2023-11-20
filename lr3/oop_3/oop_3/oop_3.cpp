/*************************************************************
*                    КАФЕДРА № 304 2 КУРС                    *
*------------------------------------------------------------*
* Project Type   : Win32 Console Application                 *
* Project Name   : LR OOP3                                   *
* File Name      : LR OOP3.cpp                               *
* Language       : C++                                       *
* Programmers(s) : Вельковский З.И.                          *
* Created        : 12/10/23                                  *
* Last Revision  : 12/10/23                                  *
* Comments(s)    : Динамический полиморфизм                  *
*************************************************************/

#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>

#include "Figures.hpp"


static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("LR3");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), szTitle, NULL);
		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		1024, 512, NULL, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), szTitle, NULL);
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//Инициализаци объектов
Rocket rocket(800, 50);
Aster_2 aster_2(0, 50);

int startX = 300, startY = 0;
Aster Aster1(startX, startY);
aster_dmg_1 Aster2(startX, startY);
aster_dmg_2 Aster3(startX, startY);
aster_dmg_3 Aster4(startX, startY);


//Массив переходов
int AsterNow = 0;
Aster* AsterArr[4] = { &Aster1, &Aster2, &Aster3, &Aster4 };
Aster* AsterPtr = AsterArr[AsterNow];

//Матрица переходов
int transitionMatrix[2][4] = {
	{ 3, 1, 1, 2},
	{ 2, 0, 3, 0}
};


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	switch (message) {
	case WM_KEYDOWN:
	{
		AsterPtr->onKeyDown(wParam);

		if (AsterPtr->hit(rocket.getX(), rocket.getY(), rocket.getX() + rocket.right, rocket.getY() + rocket.bottom) == 1) {
			AsterNow = transitionMatrix[0][AsterNow];
			AsterPtr = AsterArr[AsterNow];
			AsterPtr->setXY(startX, startY);
		}

		if (AsterPtr->hit(aster_2.getX(), aster_2.getY(), aster_2.getX() + aster_2.right, aster_2.getY() + aster_2.bottom) == 1) {
			AsterNow = transitionMatrix[1][AsterNow];
			AsterPtr = AsterArr[AsterNow];
			AsterPtr->setXY(startX, startY);
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		AsterPtr->show(hdc);
		rocket.show(hdc);
		aster_2.show(hdc);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
