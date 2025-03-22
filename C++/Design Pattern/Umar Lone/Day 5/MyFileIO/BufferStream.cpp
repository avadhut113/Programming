#include "BufferStream.h"
#include <iostream>

CBufferStream::CBufferStream(CStream* stream_ptr) : m_stream_ptr(stream_ptr)
{

}

void CBufferStream::read()
{
    m_stream_ptr->read();
    std::cout << __FUNCTION__ << " : Reading from buffer " << std::endl;
}

void CBufferStream::write()
{
    m_stream_ptr->write();
    std::cout << __FUNCTION__ << " : Writing into buffer " << std::endl;
}
