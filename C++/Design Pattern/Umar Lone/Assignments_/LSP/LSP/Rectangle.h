#pragma once
class Rectangle
{
	int m_Length{}, m_Height{} ;
public:
	Rectangle(int length, int height);

	int GetLength() const;

	void SetLength(int length);

	int GetHeight() const;

	void SetHeight(int height);
};

