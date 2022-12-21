#include <string>
#include "..\Models\Subway.h"
#include "..\Models\Station.h"
#include "..\Models\Line.h"
#include <vector>
class InputMiddleware {
	private:	
	public:
		static bool CheckIsActiveInput(int parameter);
		static bool CheckAvaliableSubway(Subway subwayData);
		static bool CheckAvaliableStation(Station stationData);
		static bool CheckAvaliableLine(Line lineData);
		static bool CheckStationHaveAnotherLine(Station stationData);		
};