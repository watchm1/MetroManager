#include "graphics.h"
#include "LineLocations.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unistd.h>
#pragma 
using json = nlohmann::json;
const int WIDTH = 800, HEIGHT = 600;
const int multiplier = 50;
void DrawLine(int moveToX, int moveToY, int drawX, int drawY, int color, int textX, int textY, char* name)
{
	moveto(moveToX, moveToY);
	setcolor(color);
	lineto(drawX, drawY);
	outtextxy(textX, textY, name);
	
}
bool ExistsFile(std::string fileName)
{
	std::ifstream inFile(fileName.c_str());
	if(!inFile.good())
	{
		return false;
	}
	else {
		return true;
	}
}
RootObject<Station> ConvertFromJsonStation(std::string data)
{
	RootObject<Station> newData;
	json from_string = json::parse(data);
	auto TData = from_string.is_null() ? newData : from_string.get<RootObject<Station>>();
	return TData;
}
RootObject<Station> ReadDataStation(std::string fileName)
{
	if(ExistsFile(fileName))
	{
		std::ifstream reader;
		reader.open(fileName.c_str());
		if(reader.fail())
		{
			std::cout << "Couldn't read";
		}
		auto convertedVal = std::string((std::istreambuf_iterator<char>(reader)), std::istreambuf_iterator<char>());
		reader.close();
		return ConvertFromJsonStation(convertedVal);
	}
}
RootObject<Line> ConvertFromJsonLine(std::string data)
{
	RootObject<Line> newData;
	json from_string = json::parse(data);
	auto TData = from_string.is_null() ? newData : from_string.get<RootObject<Line>>();
	return TData;
}
RootObject<Line> ReadDataLine(std::string fileName)
{
	if(ExistsFile(fileName))
	{
		std::ifstream reader;
		reader.open(fileName.c_str());
		if(reader.fail())
		{
			std::cout << "Couldn't read";
		}
		auto convertedVal = std::string((std::istreambuf_iterator<char>(reader)), std::istreambuf_iterator<char>());
		reader.close();
		return ConvertFromJsonLine(convertedVal);
	}
}

void WriteLocations(std::string ID, RootObject<Station> stationData, int xZero, int yZero)
{
	std::vector<int> locationsX;
	std::vector<int> locationsY;
	for(auto &element : stationData.lists)
	{
		locationsX.push_back(element.locationX);
		locationsY.push_back(element.locationY);
	}
	for(int i = 0; i < locationsX.size(); i++)
	{
		std::cout << "Current X value => " << locationsX[i] << std::endl;
		std::cout << "Current Y value => " << locationsY[i] << std::endl;
		
		int oldX;
		int oldY;
		oldX = 0;
		oldY = 0;
		int currentXval = 0;
		int currentYval = 0;
		if(i == 0)
		{
			oldX = xZero;
			oldY = yZero;
			currentXval = xZero + (locationsX[i] * multiplier);
			currentYval	= yZero - (locationsY[i] * multiplier);
		}
		else if(i > 0)
		{
			oldX = locationsX[i-1] * multiplier;
			oldY = yZero - (locationsY[i-1] * multiplier);
			currentXval = locationsX[i] * multiplier;
			currentYval = yZero - locationsY[i] * multiplier;
		}
		DrawLine(oldX, oldY, currentXval, currentYval, WHITE, currentXval + 10, currentYval + 10,const_cast<char*>(stationData.lists[i].ModelName.c_str()));
		sleep(1);
	}
	
	
}

void VectorManipulation(RootObject<Line> lineData, RootObject<Station> stationData, int xZero, int yZero)
{
	for(auto &element: lineData.lists)
	{
		WriteLocations(element.ModelUniqueID, stationData, xZero, yZero);
	}
}
void DrawCoordinates(int xZero, int yZero)
{
	DrawLine(0, yZero , WIDTH, yZero, WHITE, WIDTH - 20, yZero - 20, "X");
	sleep(1);
	DrawLine(xZero, 0, xZero , yZero, WHITE, xZero + 10, 0, "Y");
	sleep(1);
}
int main(int argc, char** argv)
{
	int xZero = 0;
	int yZero = HEIGHT -10;
	
	initwindow(WIDTH, HEIGHT);
	// coordinates
	DrawCoordinates(xZero, yZero);
	VectorManipulation(ReadDataLine("../Lines.json"), ReadDataStation("../Stations.json"), xZero, yZero);	
	
	getch();
	system("PAUSE");
	closegraph();
	
	return 0;
}