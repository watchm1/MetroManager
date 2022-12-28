#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string>
class Configurations{
	
	private:
		
		std::string SubwayDataPath;
		std::string LineDataPath;
		std::string StationDataPath;
		void Initializer();
	public:
		int WIDTH, HEIGHT;
		explicit Configurations();
		std::string GetPathOfLines();
		std::string GetPathOfSubways();
		std::string GetPathOfStations();
		
};
#endif