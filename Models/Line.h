#ifndef LINE_H
#define LINE_H
#include <vector>
#include "BaseModel.h"
#include <nlohmann/json.hpp>

struct Line : public BaseModel{
	
	int isActive;
		
};
inline void to_json(nlohmann::json& j, const Line& l)
	{
		j = nlohmann::json
		{
			{
				"ModelUniqueID", l.ModelUniqueID
			},
			{
				"ModelName", l.ModelName
			},
			{
				"isActive",l.isActive
			}
		};
	}
inline void from_json(const nlohmann::json& j, Line& l)
	{
		l.ModelUniqueID = j.at("ModelUniqueID");
		l.ModelName = j.at("ModelName");
		l.isActive = j.at("isActive");
	}
#endif