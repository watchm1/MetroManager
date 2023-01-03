#include <windows.h>
#include "..\Utils\Utils.h"
#include "..\Models\Line.h"
#include "..\Models\Station.h"
#include "..\Models\Subway.h"
#include "..\Utils\RootObjects.h"
#include "..\Utils\JSONHelper.h"
#include "..\Config\Config.h"
#include "..\Middlewares\InputMiddleware.h"
#include "..\Middlewares\DataMiddleware.h"
using namespace std;
class LineManager{
	private:
		
		// SERVICES
		DataMiddleWare middleware;
		HANDLE h;
		// ROOT OBJECTS
		RootObject<Line> rootLine;
		RootObject<Station> rootStation;
		RootObject<Subway> rootSubway;
		void LineStatementMenu(Line lineData);
		void ActiveStations(Line lineData);
		void ActiveExpedition(Line lineData);
		
		void GetAllData();
		void HandleSpecificLine(int index, Line lineData);
		void AddExpedition(Line lineData);
		void AddStation(Line lineData);
	public:
		void SaveData();
		explicit LineManager();
		void HatOlustur();
		void BakimaAl();
		void HatDurumu(); 
		void HatGorseli();
		void DrawAllLinesInCoordinates();
		void AddNewSubwayPool(Subway subway);
		
};

