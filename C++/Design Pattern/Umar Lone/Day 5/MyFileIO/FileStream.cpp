#include "FileStream.h"
#include <iostream>

CFileStream::CFileStream()
{

}

void CFileStream::read()
{
    std::cout << __FUNCTION__ << " : Reading from file " << std::endl;
}

void CFileStream::write()
{
    std::cout << __FUNCTION__ << " : Wrinting into file " << std::endl;
}
