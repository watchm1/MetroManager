#include <windows.h>
#include "..\Utils\Utils.h"
#include "..\Models\Line.h"
#include "..\Models\Station.h"
#include "..\Models\Subway.h"
#include "..\Utils\RootObjects.h"
#include "..\Utils\JSONHelper.h"
#include "..\Config\Config.h"
#include "..\Middlewares\InputMiddleware.h"
<<<<<<< HEAD

=======
#include "..\Middlewares\DataMiddleware.h"
>>>>>>> d1b463d7b72404e78ec0b3013cbbdbe669e2dffc
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

