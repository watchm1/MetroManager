#include "DataMiddleware.h"


RootObject<Line> DataMiddleWare::GetAllDataFromLines()
{
	return this->lineService.ReadData(this->configs.GetPathOfLines());
}

bool DataMiddleWare::WriteAll(RootObject<Line> lineRoot){
	this->lineService.WriteData(this->configs.GetPathOfLines(), lineRoot);
	return true;
	
}

RootObject<Subway> DataMiddleWare::GetAllDataFromSubways()
{
	return this->subwayService.ReadData(this->configs.GetPathOfSubways());
}

bool DataMiddleWare::WriteAllToSubway(RootObject<Subway> subwayRoot)
{
	this->subwayService.WriteData(this->configs.GetPathOfSubways(), subwayRoot);
	return true;
}

RootObject<Station> DataMiddleWare::GetAllDataFromStations()
{
	return this->stationService.ReadData(this->configs.GetPathOfStations());
}
bool DataMiddleWare::WriteAllToStations(RootObject<Station> stationRoot)
{
	this->stationService.WriteData(this->configs.GetPathOfStations(), stationRoot);
	return true;
}




