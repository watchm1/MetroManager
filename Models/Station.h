#ifndef STATION_H
#define STATION_H
#include "BaseModel.h"
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
struct Station : public BaseModel {
	
	string LineUniqueID;
	string extraLineID;
	int locationX;
	int locationY;
	int is_active;
};
//struct:Yapı (Struct) : Birbirleriyle ilişkili değişkenlerin, bir isim altında toplanmasına yapı adı verilir. Yapılar, değişik veri tiplerinde elemanlar içerebilirler ve dosya içinde tutulacak kayıtları oluşturmakta kullanılırlar.

inline void to_json(nlohmann::json& j, const Station& s)
{
	j = nlohmann::json 
	{
		{
			"ModelUniqueID", s.ModelUniqueID		
		},
		{
			"ModelName", s.ModelName
		},
		{
			"is_active", s.is_active
		},
		{
			"LineUniqueID", s.LineUniqueID
		},
		{
			"extraLineID", s.extraLineID
		},
		{
			"locationX", s.locationX
		},
		{
			"locationY", s.locationY
		},
	};
}
inline void from_json(const nlohmann::json& j, Station& s)
{
	s.ModelUniqueID = j.at("ModelUniqueID");
	s.ModelName = j.at("ModelName");
	s.is_active = j.at("is_active");
	s.LineUniqueID = j.at("LineUniqueID");
	s.extraLineID = j.at("extraLineID");
	s.locationX = j.at("locationX");
	s.locationY = j.at("locationY");
}

#endif