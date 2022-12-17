#ifndef JSONHELPER_H
#define JSONHELPER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Utils.h"
template<typename T>
class NOSqlService {
	private:
		bool CheckExistence(std::string fileName);
	public:		
		void WriteData(std::string fileName, T objectInstance);
		T ReadData(std::string fileName);
		
};
template<typename T>
void NOSqlService<T>::WriteData(std::string fileName, T objectInstance)
{
	if(this->CheckExistence(fileName))
	{
		std::ofstream ofs;
		ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
		auto value = Utils::ConvertToJson<T>(objectInstance);
		ofs<< value;
		ofs.close();
	}
	else 
	{
		std::ofstream outFile(fileName);
		auto value = Utils::ConvertToJson<T>(objectInstance);
		outFile<< value;
		outFile.close();
	}
}
template<typename T>
T NOSqlService<T>::ReadData(std::string fileName)
{
	if(this->CheckExistence(fileName))
	{
		std::ifstream reader;
		reader.open(fileName.c_str());
		if(reader.fail())
		{
			std::cout << "fail when try to open file" << std::endl; 
		}
		auto convertedVal = std::string((std::istreambuf_iterator<char>(reader)), std::istreambuf_iterator<char>());
		reader.close();
		return Utils::ConvertFromJson<T>(convertedVal);
	}
}
template<typename T>
bool NOSqlService<T>::CheckExistence(std::string fileName)
{
	std::ifstream inFile(fileName.c_str());
	if(!inFile.good())
	{
		return false;
	}
	else {
		return true;
	}
}
#endif