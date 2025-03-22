#pragma once
#include <cstddef>
class IFile
{
public:
	virtual void Open() = 0 ;
	virtual void Close() = 0 ;
	virtual void Write() = 0 ;
	virtual void Read() = 0 ;
	virtual void Seek(int position) = 0 ;
	virtual size_t GetPosition()const = 0 ;
	virtual size_t Size()const = 0 ;
	virtual ~IFile()=default ;
};

