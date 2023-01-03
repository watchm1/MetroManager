#include <windows.h>
#include "..\Utils\Utils.h"
#include "..\Models\Line.h"
#include "..\Models\Station.h"
#include "..\Models\Subway.h"
#include "..\Utils\RootObjects.h"
#include "..\Utils\JSONHelper.h"
#include "..\Config\Config.h"
#include "..\Middlewares\InputMiddleware.h"

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
		void LineStatementMenu(Line lineData);
		void ActiveStations(Line lineData);//aktif istasyonlar
		void ActiveExpedition(Line lineData);//aktif seferler
		
		void GetAllData();
		void HandleSpecificLine(int index, Line lineData);//belirli çizgiyi işle
		void AddExpedition(Line lineData);//sefer ekle
		void AddStation(Line lineData);
	public:
		void SaveData();
		explicit LineManager();
		void HatOlustur();
		void BakimaAl();
		void HatDurumu(); 
		void HatGorseli();
		void DrawAllLinesInCoordinates();//koordinatlardaki tüm çizgileri çiz
		void AddNewSubwayPool(Subway subway);//yeni metroyu havuza ekle
		
};

