#pragma once
class Command
{
public:
	virtual void Execute(int id) = 0 ;
	virtual void Undo() = 0 ;
	//Addcommand() ;
	//Removecommand() ;
	//Insert() ;
	virtual ~Command()=default ;
};

