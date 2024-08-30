#include <windows.h>
#include <gdiplus.h>
#include <objidl.h>

#include "ExampleScreen.h"

#pragma comment (lib,"Gdiplus.lib")

// ћинимальна€ обв€зка дл€ демонстрации

HWND createWindow()
{
	return CreateWindowEx(
		0,
		WC_DIALOG,
		L"Simple",
		WS_VISIBLE | WS_SYSMENU,
		0, 0,
		1920,
		1080,
		0, 0, 0, 0);
}


void initGdiPlus()
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}


int main()
{
	HWND window = createWindow();
	initGdiPlus();

	ExampleScreen screen;
	
	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(window, &ps);
	
	auto graphics = std::unique_ptr<Gdiplus::Graphics>(new Gdiplus::Graphics(hdc));
	screen.draw(graphics);
	
	EndPaint(window, &ps);
	
	Sleep(2000); // ƒа, мне было лень делать нормальное windows-приложение с обрабочиком сообщений
	//for (;;); 

	return 0;
}
