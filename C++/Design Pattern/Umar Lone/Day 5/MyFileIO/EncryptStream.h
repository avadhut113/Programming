#ifndef CENCRYPTSTREAM_H
#define CENCRYPTSTREAM_H

#include "Stream.h"

class CEncryptStream : public CStream
{
        CStream* m_stream_ptr;
public:
    CEncryptStream();

    void read() override;
    void write() override;
};

#endif // CENCRYPTSTREAM_H
