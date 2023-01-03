#include "LineManagment.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std; 

LineManager::LineManager(){
	this->GetAllData();
	h = GetStdHandle(STD_OUTPUT_HANDLE);//handle: bir veri yapısına erişmek için kullanılan anahtarlar
}
void LineManager::HatOlustur()
{
	
	system("cls");
	string HatAdi;
	string lineID;
	int DurakSayisi;
	cout << "Hat ismi: ";
	cin >> HatAdi;
	cout << " \nDurak Sayisi: ";
	cin >> DurakSayisi;
	Line newLine;
	
	newLine.ModelUniqueID = Utils::GenerateUniqueID();
	newLine.ModelName = HatAdi;
	newLine.isActive = 1;
	this->rootLine.lists.push_back(newLine);
	for(int i = 0; i < DurakSayisi ; i ++)
	{
		Station newStation;
		newStation.ModelUniqueID = Utils::GenerateUniqueID();
		cout << endl << " Durak Adi : ";
		cin >> newStation.ModelName;
		newStation.LineUniqueID = newLine.ModelUniqueID;
		newStation.extraLineID = "";
		newStation.is_active = 1;
		cout << endl << "KOORDINAT X :";
		cin >> newStation.locationX;
		cout << endl << "KOORDINAT Y :";
		cin >> newStation.locationY;
		this->rootStation.lists.push_back(newStation);
	}
	
	cout << endl << "HAT BASARIYLA EKLENDI" << endl;
	cout << endl << "ANA MENUYE DONULUYOR..." << endl;
	this->SaveData();
	
}

void LineManager::BakimaAl() {
	cout << "AKTIF HATLAR " << endl << endl;
	// will check avaliable lines
	int activeCount = 0;
	
	if(this->rootLine.lists.size() > 0)
	{
		for(int i = 0; i < this->rootLine.lists.size(); i++)
		{
			if(InputMiddleware::CheckAvaliableLine(this->rootLine.lists[i]))
			{//uygun hattı kontrol edin
				activeCount +=1;
				Utils::MoveCursorPoint(20, 6+(i*2));//imleç noktasını taşı
				Utils::ChangeColor(this->h, 2);
				cout<< "[" << i << "] " << "[" << this->rootLine.lists[i].ModelUniqueID  << "] - " << "[ " << this->rootLine.lists[i].ModelName << " ]" << endl;
			}
		}
		Utils::ChangeColor(this->h, 7);
		if(activeCount > 0)
		{
			
			int id;
			Utils::MoveCursorPoint(9,22);
			cout << "Bakima almak istediginiz hatti seciniz :[ ]";	
			Utils::MoveCursorPoint(50,22);
			cin >> id;
			if(this->rootLine.lists[id].isActive  == 1)
			{
				this->rootLine.lists[id].isActive = 0;
				cout << "HAT BAKIMA ALINDI. ANA MENUYE GERI DONUS YAPILIYOR..." << endl;
					
			}
			else if(this->rootLine.lists[id].isActive == 0) {
				cout << "GECERSIZ GIRIS. ANA MENUYE GERI DONUS YAPILIYOR..." << endl;
				
			}	
			else {
				cout << "GECERSIZ GIRIS. ANA MENUYE GERI DONUS YAPILIYOR..." << endl;
				
			}
		}	
		else {
			cout << "AKTIF METRO HATTI BULUNAMADI. ANA MENUYE DONULUYOR..." << endl;
			activeCount = 0;
		}
	}
	this->SaveData();
}

void LineManager::HatDurumu()
{
	cout << "HAT DURUMU" << endl;
	int selected = 0;
	int counter = 0;
	
	for(auto &element: this->rootLine.lists)
	{
		if(InputMiddleware::CheckAvaliableLine(element))
		{
			Utils::ChangeColor(this->h,2); // green color
		}
		else {
			Utils::ChangeColor(this->h, 4); // red color
		}
		Utils::MoveCursorPoint(20, 6+(counter*2));
		cout<< "[" << counter << "] " << "[" << element.ModelUniqueID  << "] - " << "[ " << element.ModelName << " ]" << endl;	
		counter ++;
	}
	Utils::MoveCursorPoint(10,22);//imlaç noktasını taşı
	Utils::ChangeColor(this->h, 7);
	cout << "Islem yapmak istediginiz hatti seciniz:[ ] " ;
	Utils::MoveCursorPoint(50,22);
	cin>>selected;
	if(selected < this->rootLine.lists.size())
	{
		this->HandleSpecificLine(selected, this->rootLine.lists[selected]);
	}//belirli çizgeyi işle
	else {
		cout << "GECERSIZ GIRIS. ANA MENUYE GERI DONUS YAPILIYOR..." << endl;
	}
	
}
void LineManager::ActiveStations(Line lineData)//hat yöneticisi:: aktif istasyonlar
{
	system("cls");
	cout << "\t\t\t\t\t\t STATIONS" << endl << endl << endl;
	cout << "\tLINE-ID\t";
	cout << "\t\t" << " STATION-ID \t";
	cout << "\t\t" << " STATION NAME";
	cout << "\t\t" << "  IS ACTIVE \n";
	cout << "------------------------------------------------------------------------------------------------------------ \n"; 
		// sefer sayısı arttırma
		// yeni durak ekleme
		// aktif seferleri görüntüleme 
		// Durakları yazdırma +	
	
	for(auto &element : this->rootStation.lists)
	{
		if(element.LineUniqueID == lineData.ModelUniqueID)
		{
			string value = "";
			cout <<"    "<< "[ " << element.LineUniqueID << " ]";
			cout << "\t\t[ " << element.ModelUniqueID  << " ]" ;
			cout << "\t\t\t[ " << element.ModelName << " ]";
			if(InputMiddleware::CheckAvaliableStation(element))
			{
				Utils::ChangeColor(this->h,2);	
				value ="ACTIVE";
			}	
			else 
			{
				Utils::ChangeColor(this->h,4);	
				value = "DEACTIVE";
			}
			cout << "\t\t[ " << value << " ]" << endl;
			Utils::ChangeColor(this->h, 7);
		}
		Utils::ChangeColor(this->h,7);
	}
	getch();
}
void LineManager::ActiveExpedition(Line lineData)
{
	system("cls");
	cout << "\t\t\t\t\t\t EXPEDITIONS" << endl << endl << endl;//seferler
	cout << "\tID\t";//ıd
	cout << "\t\t" << " NEXT STATION \t";//gelecek istasyon
	cout << "\t\t" << " PASSANGER COUNT";//yolcu sayısı
	cout << "\t\t" << "  TIME \n";//zaman
	cout << "------------------------------------------------------------------------------------------------------------ \n"; 
 	vector<Station> lineStations;
 	for(auto &element: this->rootStation.lists)
 	{
 		if(element.LineUniqueID == lineData.ModelUniqueID)
		{
			lineStations.push_back(element); 	
		}	
	}
	srand(time(0));
	for(auto &element : this->rootSubway.lists)
	{
		if(element.CurrentLineUniqueID == lineData.ModelUniqueID)
		{
			if(InputMiddleware::CheckAvaliableSubway(element))
			{
				Utils::ChangeColor(this->h,2);	
			}
			else 
			{
				Utils::ChangeColor(this->h,4);
			}
			cout << right << "[ " <<element.currentExpeditionID << " ]";
			cout << right << "\t\t\t" << "[ " << lineStations[(int)(rand() % lineStations.size())].ModelName << " ]";
			cout << right << "\t\t\t  " << "[ " << (int)(rand() % 1000) +1 << " ]";
			cout << right << "\t\t"<< Utils::CurrentDateTime() << endl;
		}	
	}
	Utils::ChangeColor(this->h,7);
	getch();
}
void LineManager::HandleSpecificLine(int index, Line lineData)
{
	system("cls");
	cout<< "[" << index << "] " << "[" << lineData.ModelUniqueID  << "] - " << "[ " << lineData.ModelName << " ]" << endl;
	if(lineData.isActive == 1)
	{
		// aktif seferleri göster
		// sefer ekleme
		this->LineStatementMenu(lineData);
	}
	else 
	{
		char selection = getch();//klavyeden karakter girmemiz gerekirken, karakter girmek yerine ENTER tuşuna basarsak, getchar() fonksiyonu \n karakterini geri verir.
		cout << "Hatti tekrar aktiflestirmek ister misiniz? Y/N : " ;
		cin >> selection;
		switch(selection)
		{
			case 'y':
				lineData.isActive = 1;
				this->rootLine.lists[index] = lineData;
				cout << "Basariyla aktiflestirildi... Ana menuye donuluyor..." << endl;
				this->SaveData();
				break;
			case 'n':
				this->HatDurumu();
				break;
			default:
				break;
		}
	}
}
void LineManager::LineStatementMenu(Line lineData)
{
	cout << endl << "1) SHOW ACTIVE EXPEDITIONS" << endl;
	cout << "2) SHOW ACTIVE STATIONS" << endl;
	cout << "3) ADD EXPEDITIONS" << endl;
	cout << "4) ADD STATIONS" << endl;
	
	char option = getch();
	switch(option)
	{
		case '1':
			this->ActiveExpedition(lineData);//aktif sefer
			break;
		case '2':
			this->ActiveStations(lineData);//aktif istasyonlar
			break;
		case '3':
			this->AddExpedition(lineData);//sefer ekleme
			break;
		case '4':
			this->AddStation(lineData);//istasyon ekleme
			break;
		default:
			break;
	}
}
void LineManager::AddExpedition(Line lineData)
{
	
	system("cls");
	cout << "\t ALL SUBWAYS" << endl;
	int counter, selection = 0;
	vector<int> options;
	for(auto &element: this->rootSubway.lists)
	{
		if(!InputMiddleware::CheckAvaliableSubway(element))
		{
			cout<< "[" << counter << "] " << "[" << element.ModelUniqueID  << "] - " << "[ " << element.ModelName << " ]" << endl;
			options.push_back(counter);
		}
		counter++;
	}
	cout << endl << "SECMEK ISTEDIGINIZ TREN : ";
	cin >> selection;
	if(Utils::ContainsInVector(selection, options))
	{
		this->rootSubway.lists[selection].CurrentLineUniqueID = lineData.ModelUniqueID;
		this->rootSubway.lists[selection].currentExpeditionID = Utils::GenerateUniqueID();
		this->rootSubway.lists[selection].isActive = 1;
		cout << "BASARIYLA YENI SEFER OLUSTURULDU. ANA MENUYE DONULUYOR..." << endl;
	}
	else 
	{
		this->AddExpedition(lineData);
	}
	this->SaveData();
}
void LineManager::AddStation(Line lineData)
{
	system("cls");
	Station newStation;

	vector<int> xLocations;
	vector<int> yLocations;
	for(int i = 0; i < this->rootSubway.lists.size(); i++)
	{
		if(this->rootStation.lists[i].LineUniqueID == lineData.ModelUniqueID)
		{
			xLocations.push_back(this->rootStation.lists[i].locationX);
			yLocations.push_back(this->rootStation.lists[i].locationY);
		}
	}
	git:
	int xInput, yInput = 0;
	newStation.ModelUniqueID = Utils::GenerateUniqueID();
	cout << endl << "DURAK ADI : ";
	cin >> newStation.ModelName;
	newStation.LineUniqueID = lineData.ModelUniqueID;
	newStation.extraLineID = "";
	cout << endl << "X KOORDINATI : ";
	cin >> xInput;
	cout << endl << "Y KOORDINATI : ";
	cin>> yInput;
	
	bool condition = !Utils::ContainsInVector(xInput, xLocations) || !Utils::ContainsInVector(yInput, yLocations);
	if(condition)
	{
		cout << "YENI DURAK BASARIYLA EKLENDI. ANA MENUYE DONULUYOR..." << endl;
		this->rootStation.lists.push_back(newStation);
		xLocations.clear();
		yLocations.clear();
	}
	else 
	{
		cout << "KOORDINATLAR YANLIS. LUTFEN TEKRAR DENEYIN." << endl;
		goto git;	
	}
	this->SaveData();
}
void LineManager::AddNewSubwayPool(Subway subway)
{
	this->rootSubway.lists.push_back(subway);
	this->SaveData();
}
void LineManager::DrawAllLinesInCoordinates()
{
	
}
void LineManager::GetAllData()
{	
	this->rootLine = this->lineService.ReadData(this->config.GetPathOfLines());
	this->rootStation = this->stationService.ReadData(this->config.GetPathOfStations());
	this->rootSubway = this->subwayService.ReadData(this->config.GetPathOfSubways());
}	
void LineManager::SaveData()
{
	this->lineService.WriteData(this->config.GetPathOfLines(), this->rootLine);
	this->stationService.WriteData(this->config.GetPathOfStations(), this->rootStation);
	this->subwayService.WriteData(this->config.GetPathOfSubways(), this->rootSubway);
}
