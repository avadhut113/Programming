#ifndef CFILECOMPRESS_H
#define CFILECOMPRESS_H

#include "Stream.h"


class CStreamCompress : CStream
{
    CStream* m_stream_ptr;
public:
    CStreamCompress(CStream* stream_ptr);

    void read() override;
    void write() override;
};

#endif // CFILECOMPRESS_H
