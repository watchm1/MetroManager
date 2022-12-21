#include "InputMiddleware.h"

bool InputMiddleware::CheckIsActiveInput(int parameter)
{
	return (parameter == 0 || parameter == 1) ? true : false;
}
bool InputMiddleware::CheckAvaliableSubway(Subway subwayData)
{
	return subwayData.isActive == 1 ? true: false;
}
bool InputMiddleware::CheckAvaliableStation(Station stationData)
{
	return stationData.is_active == 1 ? true : false;
}
bool InputMiddleware::CheckStationHaveAnotherLine(Station stationData)
{
	return stationData.extraLineID == "" ? false:true;
}

bool InputMiddleware::CheckAvaliableLine(Line lineData)
{
	return lineData.isActive == 1 ? true : false;
}