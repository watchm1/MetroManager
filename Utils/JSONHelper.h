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
		bool CheckExistence(std::string fileName);//varlığını kontol et
	public:		
		void WriteData(std::string fileName, T objectInstance);//nesne örneği
		T ReadData(std::string fileName);//verileri oku
		
};
template<typename T>//fonksiyon tarafından kullanılan bir veri türü için bir yer tutucu adını gösterir. Bu isim, fonksiyon tanımında kullanılabilir.
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
	else 
	{
		T newVariable;
		return newVariable;
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