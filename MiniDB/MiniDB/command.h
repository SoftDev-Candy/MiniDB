#ifndef COMMAND_H
#define COMMAND_H
#include<iostream>
#include"storedata.h"

class DBCommands
{
private: 
	std::string enterLine;

public: 
	std::string Input();
	void startLoop();



};




#endif COMMAND_H