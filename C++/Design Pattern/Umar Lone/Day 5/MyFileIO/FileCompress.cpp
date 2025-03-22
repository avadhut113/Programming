#include "FileCompress.h"
#include <iostream>

CStreamCompress::CStreamCompress(CStream *stream_ptr)
{

}

void CStreamCompress::read()
{
    m_stream_ptr->read();
    std::cout << __FUNCTION__ << " : Reading as encrypted buffer " << std::endl;
}

void CStreamCompress::write()
{
    m_stream_ptr->write();
    std::cout << __FUNCTION__ << " : Writing as encrypted buffer " << std::endl;
}
