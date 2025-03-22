#include <QCoreApplication>
#include "FileStream.h"
#include "BufferStream.h"


//Decorator design pattern

void operate(CStream* stream)
{
    stream->read();
    stream->write();
}

int main()
{
    CFileStream fs;
    CBufferStream bs(&fs);

    operate(&bs);

    return 0;
}
