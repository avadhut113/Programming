#include "EncryptStream.h"
#include <iostream>

CEncryptStream::CEncryptStream()
{

}

void CEncryptStream::read()
{
    m_stream_ptr->read();
    std::cout << __FUNCTION__ << " : Reading as encrypted buffer " << std::endl;
}

void CEncryptStream::write()
{
    m_stream_ptr->write();
    std::cout << __FUNCTION__ << " : Writing as encrypted buffer " << std::endl;
}
