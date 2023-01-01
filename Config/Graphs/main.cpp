#include <graphics.h>
#include "LineLocations.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unistd.h>
#pragma 
using json = nlohmann::json;
std::vector<colors> colors;
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

void WriteLocations(std::string ID, std::string lineName,int color,RootObject<Station> stationData, int xZero, int yZero)
{
	int oldX;
	int oldY;
	int currentXval = 0;
	int currentYval = 0;
	std::string value = "[ " + lineName + " ]";
	
	for(int i = 0; i < stationData.lists.size(); i++)
	{
		if(stationData.lists[i].LineUniqueID == ID)
		{
			if(i == 0)
			{
				oldX = xZero;
				oldY = yZero;
				currentXval = xZero + (stationData.lists[i].locationX * multiplier);
				currentYval	= yZero - (stationData.lists[i].locationY * multiplier);
			}
			else if(i > 0)
			{
				oldX = stationData.lists[i-1].locationX * multiplier;
				oldY = yZero - (stationData.lists[i-1].locationY * multiplier);
				currentXval = stationData.lists[i].locationX * multiplier;
				currentYval = yZero - stationData.lists[i].locationY * multiplier;
			}
			DrawLine(oldX, oldY, currentXval, currentYval, color, currentXval + 10, currentYval + 10,const_cast<char*>(stationData.lists[i].ModelName.c_str()));
			sleep(1);
		}
		
	}	
	outtextxy(currentXval, currentYval - 60, const_cast<char*>(lineName.c_str()));
}
void VectorManipulation(RootObject<Line> lineData, RootObject<Station> stationData, int xZero, int yZero)
{
	
	int counter = 0;
	for(auto &element: lineData.lists)
	{
		std::cout << counter;
		WriteLocations(element.ModelUniqueID, element.ModelName,colors[counter],stationData, xZero, yZero);
		counter++;
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
	
	colors.push_back(WHITE);
	colors.push_back(GREEN);
	colors.push_back(MAGENTA);
	colors.push_back(BROWN);
	colors.push_back(YELLOW);
	colors.push_back(BLUE);
	int xZero = 0;
	int yZero = HEIGHT -10;
	
	initwindow(WIDTH, HEIGHT);
	// coordinates
	DrawCoordinates(xZero, yZero);
	VectorManipulation(ReadDataLine("../Lines.json"), ReadDataStation("../Stations.json"), xZero, yZero);	
	
	getch();
	system("PAUSE");
	closegraph();
	
	int array[15000];
	return 0;
}