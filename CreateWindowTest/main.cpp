#include <iostream>
#include <windows.h>


LRESULT WINAPI MyWndProc(HWND hwnd, UINT msg, WPARAM wparma, LPARAM lparam)
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparma, lparam);
}

int main()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpfnWndProc = (WNDPROC)MyWndProc;
	wc.lpszClassName = L"D3D";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wc);

	HWND hwnd = NULL;
	hwnd = CreateWindow(L"D3D", L"Simplest Video Play Direct3D (Surface)", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 720, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL)
	{
		return -1;
	}
	ShowWindow(hwnd, SW_RESTORE);

	MSG messages;
	while (GetMessage(&messages, NULL, 0, 0) > 0)
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	DeleteObject(hwnd); //doing it just in case
	return messages.wParam;
}