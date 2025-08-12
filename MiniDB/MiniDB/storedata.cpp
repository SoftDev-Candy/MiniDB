#include "storedata.h"

 std::vector<Record>Record::database;

std::string Record::GetName()
{
	return name;
}

int Record::GetAge()
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
	Record obj;
	obj.SetName(inputName);
	obj.SetAge(inputAge);
	database.push_back(obj);

}

const std::vector<Record>& Record::DatabaseGetter()
{
	return database;
}
