#ifndef DATAMIDDLEWARE_H
#define DATAMIDDLEWARE_H
#include <iostream>
#include "../Utils/RootObjects.h";
#include "../Models/Line.h"
#include "../Models/Station.h"
#include "../Models/Subway.h"
#include "../Config/Config.h"
#include "../Utils/JSONHelper.h"

class DataMiddleWare{
	private:
		NOSqlService<RootObject<Line>> lineService;
		Configurations configs;
	public:
		RootObject<Line> GetAllDataFromLines(); // +
		bool WriteAll(RootObject<Line> lineRoot);
};

#endif