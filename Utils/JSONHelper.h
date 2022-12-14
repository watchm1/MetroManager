#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../Models/BaseModel.h"
#include "Utils.h"
template<typename T>
class NOSqlService {
	private:
	public:		
		void WriteData(std::string fileName, T objectInstance);
		void ReadData(std::string fileName);
};
template<typename T>
void NOSqlService<T>::WriteData(std::string fileName, T objectInstance)
{
	auto value = Utils::ConvertToJson<T>(objectInstance);
	std::cout << value << std::endl;
}
template<typename T>
void NOSqlService<T>::ReadData(std::string fileName)
{
	
}
