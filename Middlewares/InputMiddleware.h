#include <string>
#include "..\Models\Subway.h"
#include "..\Models\Station.h"
#include "..\Models\Line.h"
#include <vector>
class InputMiddleware {
	private:	
	public:
		static bool CheckIsActiveInput(int parameter);//aktif girişi kontrol edin
		static bool CheckAvaliableSubway(Subway subwayData);//mevcut metroyu kontrol edin
		static bool CheckAvaliableStation(Station stationData);//mevcut istasyonu kontrol edim
		static bool CheckAvaliableLine(Line lineData);//mevcut hattı kontrol edin
		static bool CheckStationHaveAnotherLine(Station stationData);//kontrol istasyonunda başka bir hat var mı kontrol edin		
};
//static:tatic anahtar sözcüğü değişkenin bu işleve yapılan çağrılar arasında durumunu koruduğunu belirtir. Bir sınıf bildiriminde bir veri üyesi bildirdiğinizde, static anahtar sözcüğü üyenin bir kopyasının sınıfın tüm örnekleri tarafından paylaşıldığını belirtir.
//bool:Bu tür bir değişken ve false değerlerine true sahip olabilir. Koşullu ifadeler türüne bool sahiptir ve bu nedenle türünde bool değerlere sahiptir. Örneğin, i != 0 şimdi değerine false i veya değerine bağlı olarak bulunur true