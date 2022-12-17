#include <iostream>

class Configurations{
	
	private:
		std::string SubwayDataPath;
		std::string LineDataPath;
		std::string StationDataPath;
		void Initializer();
	public:
		explicit Configurations();
		std::string GetPathOfLines();
		std::string GetPathOfSubways();
		std::string GetPathOfStations();
		
};