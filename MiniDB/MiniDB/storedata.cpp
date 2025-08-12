#include "storedata.h"

static std::vector<Record>database;

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

void Record::DatabaseArraySetter(std::string inputName, int inputAge)
{



}
