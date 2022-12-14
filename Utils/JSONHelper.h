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
		T WriteData(std::string fileName, T objectInstance);
		void ReadData(std::string fileName);
};
template<typename T>
T NOSqlService<T>::WriteData(std::string fileName, T objectInstance)
{
	auto value = Utils::ConvertToJson<T>(objectInstance);	
	return Utils::ConvertFromJson<T>(value);
}
template<typename T>
void NOSqlService<T>::ReadData(std::string fileName)
{
	
}
