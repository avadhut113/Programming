#include "Form.h"
#include <Windows.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const char *msg= "Welcome to Win32 UI Programming" ;
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		TextOutA(hdc, 100, 100, msg , strlen(msg)) ;
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



Form::Form(
	DWORD dwExStyle,
	LPCWSTR lpClassName,
	LPCSTR lpWindowName,
	DWORD dwStyle,
	int X,
	int Y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam
) {
	WNDCLASSEXW wcex;

	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(nullptr, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = lpClassName;
	wcex.hIconSm = LoadIcon(nullptr, MAKEINTRESOURCE(IDI_APPLICATION));
	RegisterClassExW(&wcex);

	m_hwnd = CreateWindowExA(dwExStyle, "myclass", lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	ShowWindow(m_hwnd, SW_SHOW);
}

Form::Form(LPCWSTR lpClassName, LPCSTR lpWindowName, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
	HINSTANCE hInstance, LPVOID lpParam) :Form{ WS_EX_CLIENTEDGE | WS_EX_APPWINDOW,lpClassName,lpWindowName,WS_OVERLAPPEDWINDOW,
		X,Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam} {
}

Form::Form(LPCWSTR lpClassName, LPCSTR lpWindowName, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
	HINSTANCE hInstance, LPVOID lpParam) :Form{
		lpClassName, lpWindowName, CW_USEDEFAULT, CW_USEDEFAULT, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
} {
}

Form::Form(LPCWSTR lpClassName, LPCSTR lpWindowName,
	HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) : Form{
		lpClassName, lpWindowName, CW_USEDEFAULT, CW_USEDEFAULT, hWndParent, hMenu, hInstance, lpParam
} {
}

Form::Form(LPCWSTR lpClassName, LPCSTR lpWindowName, HINSTANCE hInstance, LPVOID lpParam) : Form{
		lpClassName, lpWindowName, nullptr, nullptr, hInstance, lpParam
} {
}

Form::Form(LPCWSTR lpClassName, LPCSTR lpWindowName) : Form{
		lpClassName, lpWindowName, nullptr, nullptr, GetModuleHandleA(nullptr), nullptr
} {
}
