#include <vector>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

struct BaseModel {
	
	std::string ModelUniqueID;
	std::string ModelName;
};
template<typename T>
struct RootObject {
	std::vector<T> lists;
};
template<typename T>
inline void to_json(nlohmann::json& j, const RootObject<T>& obj)
{
	j = nlohmann::json
	{
		{
			"Root", obj.lists		
		}
	};
}
template<typename T>
inline void from_json(const nlohmann::json& j, RootObject<T>& obj)
{
	const nlohmann::json& sj = j.at("Root");
	obj.lists.resize(sj.size());
	std::copy(sj.begin(), sj.end(), obj.lists.begin());
}
struct Station : public BaseModel {
	
	std::string LineUniqueID;
	std::string extraLineID;
	int locationX;
	int locationY;
	int is_active;
};

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
