#ifndef STOREDATA_H
#define STOREDATA_H 
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
//To store and record data in an array. 

class Record  
{
private: 

	std::string name;
	unsigned int age;
	static std::vector<Record>database;

public: 

	Record()
	{
		name = "";
		age = 0;
	}
	std::string GetName()const;
	int GetAge()const;

	void SetName(std::string inputName);
	void SetAge(int inputAge);
	
	static void DatabaseSetter(std::string inputName , int inputAge);
	static const std::vector<Record>& DatabaseGetter();



};	

std::ostream& operator<<(std::ostream& os, const Record& rec);

#endif STOREDATA_H
