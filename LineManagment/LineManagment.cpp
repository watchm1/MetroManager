#include "LineManagment.h"

using namespace std; 

LineManager::LineManager(){
	this->GetAllData();
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
	cout << rootLine.lists.size() << endl;
	for(int i = 0; i < DurakSayisi ; i ++)
	{
		Station newStation;
		newStation.ModelUniqueID = Utils::GenerateUniqueID();
		cout << " Durak Adi : ";
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
	
	// kullanacağın değişken lineHelper
	//vector<Line> lines = lineHelper.GetAllData();
	// bu şekilde tanımlama yaparak bunları ekrana bastırmaya çalış
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
