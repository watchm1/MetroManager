#include "PanelManagment.h"
#include <iostream>
#include <string>
#include <conio.h>
#include<unistd.h>
#include <iomanip>
#include <locale.h>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <ctype.h>
#include<unistd.h>


void MainPanel::PrintOptions(){//yazdırma seçenekleri
	
	setlocale(LC_ALL, "Turkish");
	this->MainTheme();//ana tema
	this->MainMenu();
}
void MainPanel::MainTheme()
{
	system("cls");
	time_t now = time(0);
	cout << ctime(&now) << endl;
	Utils::MoveCursorPoint(57,0);
	cout << "Console Color: " + this->Color;
	Utils::MoveCursorPoint(30,3);
	cout << "METRO MANAGMENT SYSTEM" << endl;
	Utils::MoveCursorPoint(15,4);//imleç noktasını taşı
	cout.width(50);//genişliği
	cout.fill('=');//doldurmak
	cout << " ";
	for(int y = 3; y < 20; y++)
	{
		Utils::MoveCursorPoint(15,y);
		cout << "|";
		Utils::MoveCursorPoint(64,y);
		cout << "|";
	}
	for(int x=15; x < 65; x++)
	{
		Utils::MoveCursorPoint(x, 20);
		cout << "+";
	}
	for(int x = 16; x< 64; x++)
	{
		Utils::MoveCursorPoint(x,18);
		cout << "=";
	}
	Utils::MoveCursorPoint(33, 19);
}


void MainPanel::MainMenu()
{
	this->MenuItem[0] = "[1] LINE STATEMENT";//hatlar hakkında bilgi
	this->MenuItem[1] = "[2] ADD LINE";//hat ekle
	this->MenuItem[2] = "[3] REFACTOR LINE";//hattı yeniden düzenleme
	this->MenuItem[3] = "[4] ADD NEW SUBWAY";//yeni metro ekle
	this->MenuItem[4] = "[5] SETTINGS";//ayarlar
	this->MenuItem[5] = "[6] ALL LINES WITH COORDINATES";//tüm satırların koordinatları
	this->MenuItem[6] = "[X] QUIT APPLICATION";
	for(int menu = 0; menu <= 6; menu++)
	{
		Utils::MoveCursorPoint(20, 6+(menu*2));
		cout << this->MenuItem[menu];
	}
	Utils::MoveCursorPoint(15,22);
	cout << "Yapmak istediginiz islemi seciniz:[]";
	Utils::MoveCursorPoint(50,22);
}

void MainPanel::HandleOperation(){
	this->PrintOptions();
	
		this->selection = getch();
		switch(this->selection)
		{
			case '1':
				this->MainTheme();
				this->manager.HatDurumu();
				usleep(3 * this->delayAsMicroSecond);//mikro saniye olarak gecikme
				this->HandleOperation();	
				break;
			case '2':
				this->manager.HatOlustur();
				Utils::MoveCursorPoint(18,6);//imlec noktasını taşı
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();
				
				
				break;
			case '3':
				this->MainTheme();
				this->manager.BakimaAl();
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();
				break;
			case '4':
				this->AddNewSubway();
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();
				break;
			case '5':
				this->HandleSettings();
				break;
			case '6':
				this->manager.DrawAllLinesInCoordinates();//çizgi koordinatlarını çiz
				usleep(3* this->delayAsMicroSecond);
				break;
			case 'x':
				this->manager.SaveData();//veri kaydet
				exit(1);
				break;				
		}
/*	switch(this->getInput())
	{
		case 0:
			return;
			break;
		case 1:
			this->manager.HatDurumu();
			break;
		case 2:
			if(this->manager.HatOlustur() || !this->manager.HatOlustur())
			{
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();
			}
	    	break;
		case 3:
			if(this->manager.BakimaAl() || !this->manager.BakimaAl())
			{
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();
			}
			break;
		default:{
			cout << "Lütfen geçerli bir rakam giriniz.";
			this->HandleOperation();
			break;
		}
	}
*/
}
int MainPanel::getInput(){
	cout<<"Lutfen birini seciniz: ";
	int number; 
	cin>>number;
	return number;
   
}
void MainPanel::HandleSettings()
{
	char colorCode;
	this->MainTheme();
	this->MenuItem[0] = "Please choose a color.";
	this->MenuItem[1] = "1-] Red";
	this->MenuItem[2] = "2-] Blue";
	this->MenuItem[3] = "3-] Green";
	this->MenuItem[4] = "4-] White";
	
	for(int menu = 0; menu <= 4; menu++)
	{
		Utils::MoveCursorPoint(20, 6+(menu*2));
		cout << this->MenuItem[menu];
	}
	Utils::MoveCursorPoint(15,22);
	cout << "Yapmak istediginiz islemi seciniz:[ ]";
	Utils::MoveCursorPoint(50,22);
	colorCode = getch();
	switch(colorCode)
	{
		case '1': system("color 4");
			this->Color = "RED";
			break;
		case '2': system("color 1");
			this->Color = "BLUE";
			break;
		case '3': system("color 2");
			this->Color = "GREEN";
			break;
		case '4': system("color 7");
			this->Color = "WHITE";
			break;
	}
	this->HandleOperation();
}
void MainPanel::AddNewSubway()
{
	system("cls");
	Subway subway;
	subway.ModelUniqueID = Utils::GenerateUniqueID();
	cout << "Subway Name : ";//metro adı
	cin >> subway.ModelName;
	cout << endl << "Carriage Count : ";//taşıma sayısı
	cin >> subway.CarriageCount;
	cout << endl << "Max Mass: ";//maksimum kütle
	cin >> subway.MaxMass;
	subway.isActive = 0;
	subway.currentExpeditionID = "";//mevcut sefer ıd si
	subway.CurrentLineUniqueID = "";
	
	this->manager.AddNewSubwayPool(subway);
	cout << endl << "ADDED SUCCESSFULLY... RETURNING TO THE MENU ";
	
}

