#ifndef DATAMIDDLEWARE_H
#define DATAMIDDLEWARE_H
#include <iostream>
#include "../Utils/RootObjects.h"
#include "../Models/Line.h"
#include "../Models/Station.h"
#include "../Models/Subway.h"
#include "../Config/Config.h"
#include "../Utils/JSONHelper.h"

class DataMiddleWare{
	private:
		NOSqlService<RootObject<Line>> lineService;
		NOSqlService<RootObject<Subway>> subwayService;
		NOSqlService<RootObject<Station>> stationService;
		Configurations configs;
	public:
		RootObject<Line> GetAllDataFromLines(); // +
		bool WriteAll(RootObject<Line> lineRoot);
		
		RootObject<Subway> GetAllDataFromSubways();
		bool WriteAllToSubway(RootObject<Subway> subwayRoot);
		
		RootObject<Station> GetAllDataFromStations();
		bool WriteAllToStations(RootObject<Station> stationRoot);
};

#endif