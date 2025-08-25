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

void Record::DeleteElement(int id)
{
	Record::DeleteTextFile();
	database.erase(database.begin() + id-1);
}

void const Record::DeleteTextFile() 
{
	const char* filename = "Record.txt";
		if (remove(filename) == 0)
		{
			std::cout << "File " << filename << " Deleted Successfully." << std::endl;
		}
		else
		{
			std::cerr << "Couldn't find file ' " << filename << " ' . " << std::endl;
		}
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
	
	databasefile <<this->GetId() <<" "<< this->GetName() << " " << this->GetAge() << std::endl;
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
		
		database.emplace_back(id, name, age);
		if (id > maxId) maxId = id;
	}
	nextId = maxId + 1;
}

std::ostream& operator<<(std::ostream& os, const Record& rec)
{
	os << std::setw(2) << rec.GetId()
	   << std::setw(5)<< rec.GetName() 
	   << std::setw(5) << rec.GetAge();
	return os; 
}