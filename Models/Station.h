#ifndef STATION_H
#define STATION_H
#include "BaseModel.h"
#include <string>

using namespace std;
struct Station : public BaseModel {
	
	string LineUniqueID;
	string extraLineID;
	int locationX;
	int locationY;
	int is_active;
#endif