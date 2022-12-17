#ifndef SUBWAY_H
#define SUBWAY_H
#include "BaseModel.h"
#include <string>
#include <nlohmann/json.hpp>
struct Subway : public BaseModel {
	
	string CurrentLineUniqueID;
	string currentExpeditionID;
	int isActive; // is fixing 
	int CarriageCount;
	int MaxMass;	
};

inline void to_json(nlohmann::json& j, const Subway& s)
{
	j= nlohmann::json 
	{
		{
			"ModelUniqueID", s.ModelUniqueID
		},
		{
			"ModelName", s.ModelName
		},
		{
			"CurrentLineUniqueID", s.CurrentLineUniqueID
		},
		{
			"CurrentLineExpeditionID", s.currentExpeditionID
		},
		{
			"isActive", s.isActive
		},
		{
			"CarriageCount", s.CarriageCount
		},
		{
			"MaxMass", s.MaxMass
		}
	};
}
inline void from_json(const nlohmann::json& j, Subway& s)
{
	s.ModelUniqueID = j.at("ModelUniqueID");
	s.ModelName = j.at("ModelName");
	s.CurrentLineUniqueID = j.at("CurrentLineUniqueID");
	s.currentExpeditionID = j.at("CurrentLineExpeditionID");
	s.isActive = j.at("isActive");
	s.CarriageCount = j.at("CarriageCount");
	s.MaxMass = j.at("MaxMass");
	
}

#endif