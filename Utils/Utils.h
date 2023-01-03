#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <windows.h>
using json = nlohmann::json;

class Utils {
	private:
		 // for id generator
	public:
		
		static std::string GenerateUniqueID();
		static std::string ConvertIntToString(int value);
		static bool ContainsInArray(int value, int arr[]);
		static bool ContainsInVector(int value, std::vector<int> data);
		template<typename T> static std::string ConvertToJson(T data);
		template<typename T> static T ConvertFromJson(std::string data);
		static void MoveCursorPoint(short x, short y);
		static void ChangeColor(HANDLE h,int color);
		static std::string CurrentDateTime();
};
template<typename T>
std::string Utils::ConvertToJson(T data)
{
	json jsonData = data;
	std::string json_as_string = jsonData.dump(); //
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