#ifndef SUBWAY_H
#define SUBWAY_H
#include "BaseModel.h"
#include <string>

struct Subway : public BaseModel {
	
	string CurrentLineUniqueID;
	string currentExpeditionID;
	int isActive; // is fixing 
	int CarriageCount;
	int MaxMass;	
};

#endif