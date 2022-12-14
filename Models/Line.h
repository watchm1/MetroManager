#ifndef LINE_H
#define LINE_H
#include <vector>
#include "BaseModel.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
struct Line : public BaseModel{
	
	int isActive;
		
};
void to_json(json& j, const Line& l)
	{
		j = json
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
	void from_json(const json& j, Line& l)
	{
		j.at("ModelUniqueID").get_to(l.ModelUniqueID);
		j.at("ModelName").get_to(l.ModelName);
		j.at("isActive").get_to(l.isActive);
	}

#endif