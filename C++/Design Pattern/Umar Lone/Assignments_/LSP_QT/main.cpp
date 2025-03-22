#include <QCoreApplication>
#include <cassert>
#include <iostream>

#include "Rectangle.h"

void Operate(Rectangle *pRect) {
    auto area = pRect->GetHeight() * pRect->GetLength() ;
    std::cout << "Area is: " << area << '\n' ;
}

int main()
{
    Rectangle obj{4,5} ;
    Operate(&obj) ;

    //QCoreApplication a(argc, argv);

    //return a.exec();
    return 0;
}
