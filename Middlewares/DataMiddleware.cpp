#include "DataMiddleware.h"


RootObject<Line> DataMiddleWare::GetAllDataFromLines()//hatlardan tüm verileri alın
{
	return this->lineService.ReadData(this->configs.GetPathOfLines());
}

bool DataMiddleWare::WriteAll(RootObject<Line> lineRoot){
	this->lineService.WriteData(this->configs.GetPathOfLines(), lineRoot);
	return true;
	
}

RootObject<Subway> DataMiddleWare::GetAllDataFromSubways()//trenlerden tüm verileri alın
{
	return this->subwayService.ReadData(this->configs.GetPathOfSubways());
}

bool DataMiddleWare::WriteAllToSubway(RootObject<Subway> subwayRoot)
{
	this->subwayService.WriteData(this->configs.GetPathOfSubways(), subwayRoot);
	return true;
}

RootObject<Station> DataMiddleWare::GetAllDataFromStations()//istasyonlardan tüm verileri alın
{
	return this->stationService.ReadData(this->configs.GetPathOfStations());//istasyonların yolunu al,configs:yapılandırmalr
}
bool DataMiddleWare::WriteAllToStations(RootObject<Station> stationRoot)
{
	this->stationService.WriteData(this->configs.GetPathOfStations(), stationRoot);
	return true;
}




