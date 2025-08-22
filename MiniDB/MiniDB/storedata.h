#ifndef STOREDATA_H
#define STOREDATA_H 

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>

//To store and record data in an array. 
class Record  
{
private: 

	std::string name;
	unsigned int age;
	static std::vector<Record>database;

public: 

	Record() //Constructor
	{
		name = "";
		age = 0;
	}

	Record(std::string s, unsigned int a)//Parametrized Constructor to use in 
	{
		name = s;
		age = a;
	}

	std::string GetName()const; //Getting individual elements
	int GetAge()const;

	void SetName(std::string inputName);//Setting indvidual elements
	void SetAge(int inputAge);
	
	//To store things in the database as well as the record vector.
	static void DatabaseSetter(std::string inputName , int inputAge);
	static const std::vector<Record>& DatabaseGetter();

	//Create,Read,Append the database file in local system 
	void Create_Open_Database();
	void AppendDatabase();
	void ReadDatabase();

};	
std::ostream& operator<<(std::ostream& os, const Record& rec);//overloading COUT operator hell yeah! 

#endif STOREDATA_H
