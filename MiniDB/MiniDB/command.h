#ifndef COMMAND_H
#define COMMAND_H
#include<iostream>
#include<limits>
#include"storedata.h"

class DBCommands
{
	
private: 
	std::string enterLine;

public: 
	std::string Input();
	void startLoop();
	void InsertInRecord(std::vector<std::string>& wordsArray);
	void SelectAllRecords();
	void SelectOneRecord(std::vector<std::string>& wordsArray);

};

#endif COMMAND_H