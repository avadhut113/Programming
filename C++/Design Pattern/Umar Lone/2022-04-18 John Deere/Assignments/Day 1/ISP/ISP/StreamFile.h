#pragma once
#include "IFile.h"

class StreamFile  :public IFile
{
public:
	void Open() override;
	void Close() override;
	void Write() override;
	void Read() override;
	void Seek(int position) override;
	size_t GetPosition() const override;
	size_t Size() const override;
};

