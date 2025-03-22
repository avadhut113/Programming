#pragma once
#include "Observer.h"
class Clock :
    public Observer
{
public:
	void OnUpdate(void* p) override;
};

