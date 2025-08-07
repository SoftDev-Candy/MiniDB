#include<iostream>
#include<string>
#include<vector>
int main()
{
	std::string enterLine;

	while (true)
	{

		std::cout << "db>";

		std::getline(std::cin, enterLine);
		if (enterLine == "exit")
		{
			std::cout << "Exiting Mini-Database" << std::endl;
			break;
		}
		std::vector<std::string>wordsArray;
		std::string word;
		for (int i = 0; i < enterLine.length() - 1; i++)
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
		if (wordsArray.size() > 0) std::cout << "Command: " << wordsArray[0] << "\n";
		if (wordsArray.size() > 1) std::cout << "Arg1: " << wordsArray[1] << "\n";
		if (wordsArray.size() > 2) std::cout << "Arg2: " << wordsArray[2] << "\n";

	}



	return 0;



}
