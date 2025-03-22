#ifndef CFILESTREAM_H
#define CFILESTREAM_H

#include "Stream.h"

class CFileStream : public CStream
{
public:
    CFileStream();

    void read() override;
    void write() override;
};

#endif // CFILESTREAM_H
