#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
class Utils {
	private:
		 // for id generator
	public:
		
		static string GenerateUniqueID();
		static string ConvertIntToString(int value);
		template<typename T> static string ConvertToJson(T data);
		template<typename T> static T ConvertFromJson(string data);
};
template<typename T>
string Utils::ConvertToJson(T data)
{
	json jsonData = data;
	string json_as_string = jsonData.dump();
	return json_as_string;
}
template<typename T>	
T Utils::ConvertFromJson(string data){
	json from_string = json::parse(data);
	auto TData = from_string.get<T>();
	return TData;
}
#endif
