#ifndef STOREDATA_H
#define STOREDATA_H 

#include<string>
#include<vector>
//To store and record data in an array. 

class Record  
{
private: 

	std::string name;
	unsigned int age;
	std::vector<Record>database;

public: 

	Record()
	{
		name = "";
		age = 0;
	}

	std::string GetName();
	int GetAge();
	


};	








#endif STOREDATA_H
