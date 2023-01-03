#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string>
class Configurations{
	
	private:
		
		std::string SubwayDataPath;//trenin datası
		std::string LineDataPath;//hattın datası
		std::string StationDataPath;//istasyonun datası
		void Initializer();//başlatıcı
	public:
		int WIDTH, HEIGHT;//genişlik ve yükseklik
		explicit Configurations(); //explicit: derleyiciye belirtilen dönüştürmenin örtük dönüştürmeleri gerçekleştirmek için kullanılamadığını söyler.
		std::string GetPathOfLines();//hatların yolunu alın
		std::string GetPathOfSubways();//metro yolunu alın
		std::string GetPathOfStations();//istasyon yolunu alın
		
};
#endif