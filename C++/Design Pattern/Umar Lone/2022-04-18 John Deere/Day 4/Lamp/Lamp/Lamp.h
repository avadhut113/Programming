#pragma once
class Lamp
{
	enum State{Off, White, Yellow};
	State m_State{Off} ;
public:
	void SwitchOn() ;
	void SwitchOff() ;
};

