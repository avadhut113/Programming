#include "Stream.h"
#include <iostream>

CStream::CStream()
{

}

void CStream::read()
{
    std::cout << __FUNCTION__ << " : Reading stream" << std::endl;
}

void CStream::write()
{
    std::cout << __FUNCTION__ << " : writing stream" << std::endl;
}
