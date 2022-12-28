
#include "Config.h"

Configurations::Configurations(){
	this->Initializer();
}

void Configurations::Initializer()
{
	this->WIDTH = 800;
	this->HEIGHT = 600;
	this->SubwayDataPath = "Config/Subways.json";
	this->LineDataPath = "Config/Lines.json";
	this->StationDataPath = "Config/Stations.json";
}
std::string Configurations::GetPathOfLines()
{
	return this->LineDataPath;
}
std::string Configurations::GetPathOfStations()
{
	return this->StationDataPath;
}
std::string Configurations::GetPathOfSubways()
{
	return this->SubwayDataPath;
}