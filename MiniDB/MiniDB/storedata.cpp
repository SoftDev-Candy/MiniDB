#include "storedata.h"

 std::vector<Record>Record::database;
 unsigned int Record::nextId = 1;

std::string Record::GetName()const
{
	return name;
}

unsigned int Record::GetAge()const
{
	return age;
}

void Record::SetName(std::string inputName)
{
	name = inputName;
}

void Record::SetAge(int inputAge)
{
	age = inputAge;
}

void Record::DatabaseSetter(std::string inputName, int inputAge)   // this will push object of the class in vector cant drop in individual elements as the vector is of type record and will only take obj of record as input.
{
	Record obj(inputName,inputAge);
	database.push_back(obj);
	obj.AppendDatabase();

}

const std::vector<Record>& Record::DatabaseGetter()
{
	return database;
}

void Record::Create_Open_Database() // call function to allow read and write in to the file
{
	std::ofstream databasefile("Record.txt", std::ios::app);

	if(!databasefile.is_open())
	{
		std::cerr << "Error: Unable to open the file. \n File does not exist or Check file location." << std::endl;
		return;
	}
}

void Record::AppendDatabase()
{
	std::fstream databasefile("Record.txt", std::ios::app);
	if (!databasefile.is_open())
	{
		std::cerr << "Error: Could not open Record.txt for appending!" << std::endl;
		return;
	}
	Record rec;
	databasefile <<rec.id <<" "<< rec.GetName() << " " << rec.GetAge() << std::endl;
}

void Record::ReadDatabase()
{
	std::fstream databasefile("Record.txt", std::ios::in);
	std::string name;
	unsigned int age;
	unsigned int id;
	unsigned int maxId = 0;

	while (databasefile >> id >> name >> age )
	{
		Record object(id,name,age);
		database.push_back(object);
		if (id > maxId) maxId = id;
	}
	nextId = maxId + 1;
}

std::ostream& operator<<(std::ostream& os, const Record& rec)
{
	os << std::setw(5) << rec.GetId()
	   << std::setw(5)<< rec.GetName() 
	   << std::setw(5) << rec.GetAge();
	return os; 
}