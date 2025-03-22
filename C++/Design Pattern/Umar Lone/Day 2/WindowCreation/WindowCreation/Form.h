#pragma once
#include <iostream>
#include <Windows.h>

class Form
{
	HWND m_hwnd{};
public:
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
};

