#ifndef CBUFFERSTREAM_H
#define CBUFFERSTREAM_H
#include "Stream.h"

class CBufferStream : public CStream
{
    CStream* m_stream_ptr;
public:
    CBufferStream() = default;
    CBufferStream(CStream* stream_ptr);

    void read() override;
    void write() override;
};

#endif // CBUFFERSTREAM_H
