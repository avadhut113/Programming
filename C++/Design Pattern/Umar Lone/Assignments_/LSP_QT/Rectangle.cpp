#include "Rectangle.h"

Rectangle::Rectangle(int length, int height): m_Length{length},
                                              m_Height{height} {
}

int Rectangle::GetLength() const {
	return m_Length;
}

void Rectangle::SetLength(int length) {
	m_Length = length;
}

int Rectangle::GetHeight() const {
	return m_Height;
}

void Rectangle::SetHeight(int height) {
	m_Height = height;
}
