#include "Circle.h"


Circle::Circle(const Point& topLeft, const Point& topRight): m_TopLeft{topLeft},
                                                             m_BottomRight{topRight} {
	m_pRender = new Renderer{} ;
	m_Radius = (m_BottomRight.x - m_TopLeft.x)/2 ;

}

float Circle::GetRadius() const {
	return m_Radius ;
}

float Circle::GetDiameter() const {
	return m_Radius * 2 ;
}

float Circle::GetArea() const {
    return 3.14 * m_Radius * m_Radius ;
}

Point Circle::GetTopLeft() const {
	return m_TopLeft ;
}

Point Circle::GetBottomRight() const {
	return m_BottomRight ;
}



void Circle::SetColor(int color) {
	m_Color = color ;
}

void Circle::Draw() {
	m_pRender->Draw(new Point[]{m_TopLeft, m_BottomRight}, m_Color) ;
}

void Circle::Fill() {
	m_pRender->Draw(new Point[]{m_TopLeft, m_BottomRight}, m_Color) ;
}

void Circle::Remove() {
	m_pRender->Erase(new Point[]{m_TopLeft, m_BottomRight}) ;
}
