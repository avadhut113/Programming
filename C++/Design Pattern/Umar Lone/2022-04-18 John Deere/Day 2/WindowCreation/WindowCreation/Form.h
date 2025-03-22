#pragma once
#include <iostream>
#include <Windows.h>

class Form
{
	HWND m_hwnd{};
public:
	/*Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		DWORD dwExStyle = WS_EX_APPWINDOW,
		DWORD dwStyle = WS_BORDER,
		int X = CW_USEDEFAULT,
		int Y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT,
		int nHeight = CW_USEDEFAULT,
		HWND hWndParent = nullptr,
		HMENU hMenu= nullptr,
		HINSTANCE hInstance= nullptr,
		LPVOID lpParam= nullptr);*/


	Form(
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
		LPVOID lpParam);

	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		int X,
		int Y,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam);
	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam);
	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam);
	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		HINSTANCE hInstance,
		LPVOID lpParam);
	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName);


	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		int X,
		int Y
	);
	Form(
		LPCWSTR lpClassName,
		LPCSTR lpWindowName,
		int X,
		int Y,
		int nWidth,
		int nHeight
	);


};



class FormBuilder {
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_CLIENTEDGE;
	LPCWSTR lpClassName= L"myform";
	LPCSTR lpWindowName = "Window";
	DWORD dwStyle = WS_CAPTION;
	int X= CW_USEDEFAULT;
	int Y= CW_USEDEFAULT;
	int nWidth= CW_USEDEFAULT;
	int nHeight= CW_USEDEFAULT;
	HWND hWndParent = nullptr;
	HMENU hMenu= nullptr;
	HINSTANCE hInstance= nullptr;
	LPVOID lpParam= nullptr;
public:
	FormBuilder & SetDwExStyle(DWORD dwExStyle);
	FormBuilder & SetLpClassName(LPCWSTR lpClassName);
	FormBuilder & SetLpWindowName(LPCSTR lpWindowName);
	FormBuilder & SetStyle(DWORD dwStyle);
	FormBuilder & SetX(int x);
	FormBuilder & SetY(int y);
	FormBuilder & SetNWidth(int nWidth);
	FormBuilder & SetNHeight(int nHeight);
	FormBuilder & SetHWndParent(HWND hWndParent);
	FormBuilder & SetHMenu(HMENU hMenu);
	FormBuilder & SetHInstance(HINSTANCE hInstance);
	FormBuilder & SetLpParam(LPVOID lpParam);

	Form Build() ;
};