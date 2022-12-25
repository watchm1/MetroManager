#include<string>
#include <iostream>
#include "..\Utils\Utils.h"
#include "..\Models\Line.h"
#include "..\Models\Station.h"
#include "..\Models\Subway.h"
#include "..\Utils\RootObjects.h"
#include "..\Utils\JSONHelper.h"
#include "..\Config\Config.h"
#include "..\Middlewares\InputMiddleware.h"
#include <windows.h>
using namespace std;
class LineManager{
	private:
		//CONFIGURATION
		Configurations config;
		// SERVICES
		NOSqlService<RootObject<Line>> lineService;
		NOSqlService<RootObject<Subway>> subwayService;
		NOSqlService<RootObject<Station>> stationService;
		
		HANDLE h;
		// ROOT OBJECTS
		RootObject<Line> rootLine;
		RootObject<Station> rootStation;
		RootObject<Subway> rootSubway;
	public:
		void SaveData();
		explicit LineManager();
		void GetAllData();
		bool HatOlustur();
		bool BakimaAl();
		void HatDurumu(); 
		void HatGorseli();
		void HandleSpecificLine(int index, Line lineData);
};

