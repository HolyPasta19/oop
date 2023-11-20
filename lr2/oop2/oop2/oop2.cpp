/*************************************************************
*                    КАФЕДРА № 304 2 КУРС                    *
*------------------------------------------------------------*
* Project Type   : Win32 Console Application                 *
* Project Name   : LR OOP2                                   *
* File Name      : LR OOP2.cpp                               *
* Language       : C++                                       *
* Programmers(s) : Вельковский З.И.                          *
* Modifyed by    :                                           *
* Lit sourse     :                                           *
* Created        : 12/09/23                                  *
* Last Revision  : 12/09/23                                  *
* Comments(s)    : Наследование                              *
*************************************************************/

#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>

#include "Figures.hpp"


static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Labwork 2");

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
Rocket rocket(900, 50);
Aster_2 aster_2(900, 250);

Aster aster1(0, 0);
aster_dmg_1 aster2(0, 0);
aster_dmg_2 aster3(0, 0);


//Массив переходов
int asterNow = 0;
Aster* asterArr[3] = { &aster1, &aster2, &aster3};
Aster* asterPtr = asterArr[asterNow];


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	switch (message) {
	case WM_KEYDOWN:
	{
		asterPtr->onKeyDown(wParam);

		if ((asterPtr->hit(rocket.getX(), rocket.getY(), rocket.getX() + rocket.right, rocket.getY() + rocket.bottom) == 1) ||
			(asterPtr->hit(aster_2.getX(), aster_2.getY(), aster_2.getX() + aster_2.right, aster_2.getY() + aster_2.bottom) == 1)) {
			asterNow = (asterNow + 1) % 3;
			asterPtr = asterArr[asterNow];
			asterPtr->setXY(0, 0);
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		asterPtr->show(hdc);
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
