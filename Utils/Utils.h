#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Utils {
	private:
		 // for id generator
	public:
		
		static std::string GenerateUniqueID();
		static std::string ConvertIntToString(int value);
		template<typename T> static std::string ConvertToJson(T data);
		template<typename T> static T ConvertFromJson(std::string data);
};
template<typename T>
std::string Utils::ConvertToJson(T data)
{
	json jsonData = data;
	std::string json_as_string = jsonData.dump();
	return json_as_string;
}
template<typename T>	
T Utils::ConvertFromJson(std::string data)
{
	T newData;
	json from_string = json::parse(data);
	auto TData = from_string.is_null() ? newData : from_string.get<T>();
	return TData;
}
#endif