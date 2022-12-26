#include "LineManagment.h"
#include <conio.h>
using namespace std; 

LineManager::LineManager(){
	this->GetAllData();
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	
}
bool LineManager::HatOlustur()
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
	
	return true;
}

bool LineManager::BakimaAl() {
	system("cls");
	cout << "AKTIF HATLAR " << endl << endl;
	// will check avaliable lines
	int activeCount = 0;
	
	if(this->rootLine.lists.size() > 0)
	{
		for(int i = 0; i < this->rootLine.lists.size(); i++)
		{
			if(InputMiddleware::CheckAvaliableLine(this->rootLine.lists[i]))
			{
				activeCount +=1;
				cout<< "[" << i << "] " << "[" << this->rootLine.lists[i].ModelUniqueID  << "] - " << "[ " << this->rootLine.lists[i].ModelName << " ]" << endl;
			}
		}
		if(activeCount > 0)
		{
			git:
			int id;
			cout << "Bakima almak istediginiz hatti seciniz :";	
			cin >> id;
			if(this->rootLine.lists[id].isActive  == 1)
			{
				this->rootLine.lists[id].isActive = 0;
				cout << "HAT BAKIMA ALINDI. ANA MENUYE GERI DONUS YAPILIYOR..." << endl;
				return true;	
			}
			else {
				cout << "GECERSIZ GIRIS. TEKRAR DENEYIN" << endl;
				goto git;
			}
			
		}	
		else {
			cout << "AKTIF METRO HATTI BULUNAMADI. ANA MENUYE DONULUYOR..." << endl;
			activeCount = 0;
			return false;	
		}
	}
}

void LineManager::HatDurumu()
{
	system("cls");
	int selected = 0;
	int counter = 0;
	for(auto &element: this->rootLine.lists)
	{
		if(InputMiddleware::CheckAvaliableLine(element))
		{
			SetConsoleTextAttribute(this->h,2); // green color
		}
		else {
			SetConsoleTextAttribute(this->h, 4); // red color
		}
		cout<< "[" << counter << "] " << "[" << element.ModelUniqueID  << "] - " << "[ " << element.ModelName << " ]" << endl;	
		counter ++;
	}
	SetConsoleTextAttribute(this->h, 7);
	cout << "Islem yapmak istediginiz hatti seciniz : " ;
	cin >> selected;
	if(selected < this->rootLine.lists.size())
	{
		this->HandleSpecificLine(selected, this->rootLine.lists[selected]);
	}
	else 
	{
		this->HatDurumu(); 
	}
	
}
void LineManager::ActiveStations(Line lineData)
{
	system("cls");
	cout << "\t\t\t STATIONS" << endl;
		// sefer sayısı arttırma
		// yeni durak ekleme
		// aktif seferleri görüntüleme 
		// Durakları yazdırma +	
		for(auto &element : this->rootStation.lists)
		{
			if(element.LineUniqueID == lineData.ModelUniqueID)
			{
				if(InputMiddleware::CheckAvaliableStation(element))
				{
					SetConsoleTextAttribute(this->h,2);	
				}	
				else 
				{
					SetConsoleTextAttribute(this->h,4);	
				}
				cout << "\t" << "[" << element.ModelUniqueID << "] " << "[" << element.ModelUniqueID  << "] - " << "[ " << element.ModelName << " ]" << endl;	
				
			}
			SetConsoleTextAttribute(this->h,7);
			
		}
}
void LineManager::ActiveExpedition(Line lineData)
{
	system("cls");
	cout << "\t\t\t EXPEDITIONS" << endl;
	
	for(auto &element : this->rootSubway.lists)
	{
		if(element.CurrentLineUniqueID == lineData.ModelUniqueID)
		{
			if(InputMiddleware::CheckAvaliableSubway(element))
			{
				SetConsoleTextAttribute(this->h,2);	
			}
			else 
			{
				SetConsoleTextAttribute(this->h,4);
			}
			cout << "\t" << "[" << element.ModelUniqueID << "] " << "[" << element.ModelUniqueID  << "] - " << "[ " << element.ModelName << " ]" << endl;
		}		
	}
	SetConsoleTextAttribute(this->h,7);
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
		char selection = getch();
		cout << "Hatti tekrar aktiflestirmek ister misiniz? Y/N : " ;
		cin >> selection;
		switch(selection)
		{
			case 'y':
				lineData.isActive = 1;
				this->rootLine.lists[index] = lineData;
				cout << "Basariyla aktiflestirildi... Ana menuye donuluyor..." << endl;
				break;
			case 'n':
				this->HatDurumu();
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
	cout << "5) BACK TO MENU" << endl;
	char option = getch();
	switch(option)
	{
		case '1':
			this->ActiveExpedition(lineData);
			break;
		case '2':
			this->ActiveStations(lineData);
			break;
		case '3':
			this->AddExpedition(lineData);
			break;
		case '4':
			this->AddStation(lineData);
			break;
		case '5':
			this->HatDurumu();
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
}
void LineManager::AddNewSubwayPool(Subway subway)
{
	this->rootSubway.lists.push_back(subway);
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
