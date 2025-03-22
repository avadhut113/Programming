#pragma once
class Rectangle
{
	int m_Length{}, m_Height{} ;
public:
	Rectangle(int length, int height);

	int GetLength() const;

    virtual void SetLength(int length);

	int GetHeight() const;

    virtual void SetHeight(int height);
};

