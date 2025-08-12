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
	static std::vector<Record>database;

public: 

	Record()
	{
		name = "";
		age = 0;
	}
	std::string GetName();
	int GetAge();

	void SetName(std::string inputName);
	void SetAge(int inputAge);
	
	void DatabaseArraySetter(std::string inputName , int inputAge);


};	


#endif STOREDATA_H
