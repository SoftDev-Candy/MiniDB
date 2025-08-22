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
		
		if (wordsArray.size() < 1)
		{
			std::cout << "The input here is invalid"<<std::endl;
			continue;
			//std::cin.clear(); // this is unecessary and is probably not going to work. 
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max,"\n");//because wordsarray is not input ...... soo what can we do here 
			////let the loop run or ..hmm or call the start function again 
		}

		Record object;
		object.Create_Open_Database();

		if(wordsArray[0] == "insert") //if we would like to add to the array 
		{
			if (wordsArray.size() > 2)
			{
				InsertInRecord(wordsArray);
			}
			else
			{
				std::cout << " Invalid Insert Command \n. Insert Commands usage: ";
				std::cout << "  insert 'name' 'age' \n";
				
			}
		}

		else if (wordsArray[0] == "select") //if we'd like to select data depends if we want the complete array or a singular element
		{
			if (wordsArray.size() >= 2)
			{
				if (wordsArray[1] == "all")
				{
					SelectAllRecords();
				}
				else
				{
					SelectOneRecord(wordsArray);
				}
			}
			else
			{
				std::cout << " Invalid Select Command \n. Select  Commands usuage: ";
				std::cout << "  select all\n";
				std::cout << "  select <name>\n";
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

void DBCommands::SelectAllRecords()
{

		for (const auto& rec : Record::DatabaseGetter())
		{
			std::cout << rec << std::endl;
		}

}

void DBCommands::SelectOneRecord(std::vector<std::string>& wordsArray)
{

	int databaseSize = Record::DatabaseGetter().size();

	bool found = false;
	for (const auto& rec : Record::DatabaseGetter())
	{
		if (wordsArray[1] == rec.GetName())
		{
			std::cout << rec << std::endl;
			found = true;
		}


	}
	if (!found)
	{
		std::cout << "No Records were found under this Name." << std::endl;
	}


}
