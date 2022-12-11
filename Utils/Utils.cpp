#include "Utils.h"
#include <iostream>

string Utils::GenerateUniqueID()
{
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	std::string numbers = "1234567890";
	std::string UniqueID = "";

	UniqueID = "";
	int min = 0;
	int max = letters.length();
	int maxNumber = numbers.length();
	int num;
	std::srand((int) std::time(0));
	for(int i = 0; i < 5; i++)
	{
		num = (rand() % (max - min) + min);
		UniqueID += letters[num];
		num = (rand() % (maxNumber - min) + min);
		UniqueID += numbers[num];
	}
	return UniqueID;	
}

string Utils::ConvertIntToString(int value)
{
	stringstream ss;
	ss << value;
	return ss.str();
} 
