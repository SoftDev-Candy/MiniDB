#include"command.h"

std::string DBCommands::Input()
{
	 std::getline(std::cin, enterLine);
	 return enterLine;
}

void DBCommands::startLoop()
{
	while (true)
	{
		std::cout << "db>";
		Input();

		if (enterLine == "exit")
		{
			
			std::cout << "Exiting Mini-Database" << std::endl;
			break;

		}
		std::vector<std::string>wordsArray;
		std::string word;

		for (int i = 0;i < enterLine.length();i++)
		{
			if (enterLine[i] != ' ')
			{
				word += enterLine[i];
			}
			else if (!word.empty())
			{
				wordsArray.push_back(word);
				word.clear();
			}
		}

		if (!word.empty())
		{
			wordsArray.push_back(word);
		}
		
		if (wordsArray.size() >= 1)
		{
			std::cout << "The input here is invalid"<<std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max,"\n");
		}

		if(wordsArray[0] == "insert") //if we would like to add to the array 
		{
			if (wordsArray.size() > 2)
			{
				InsertInRecord(wordsArray);
			}
		}

		else if(wordsArray[0] == "select") //if we'd like to select data depends if we want the complete array or a singular element
		{
			if (wordsArray.size() >= 2)
			{
				if (wordsArray[1] == "all")
				{
					SelectInRecord(wordsArray);
				}
				else
				{
				
				}
			}
		}

		if (wordsArray.size() > 0) std::cout << "Command: " << wordsArray[0] << "\n"; //the if checks are there to prevent any unknown behaviour
		if (wordsArray.size() > 1) std::cout << "Arg1: " << wordsArray[1] << "\n"; //i.e if the wordarray only has one element print wordsarray[0]
		if (wordsArray.size() > 2) std::cout << "Arg2: " << wordsArray[2] << "\n";//if its has 2 print the next one and so on

	}

}

void DBCommands::InsertInRecord(std::vector<std::string>& wordsArray)
{

	int num = std::stoi(wordsArray[2]);
	Record::DatabaseSetter(wordsArray[1], num);

}

void DBCommands::SelectInRecord(std::vector<std::string>& wordsArray)
{

	int databaseSize = Record::DatabaseGetter().size();
	int start = 0;

	if (wordsArray.size() == 2)
	{
		for (const auto& rec : Record::DatabaseGetter())
		{
			std::cout << rec << std::endl;
		}
	}

}
