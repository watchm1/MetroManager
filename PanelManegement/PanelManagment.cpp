#include "PanelManagment.h"


void MainPanel::PrintOptions(){
	
	setlocale(LC_ALL, "Turkish");
	this->MainTheme();
	this->MainMenu();
}
void MainPanel::MainTheme()
{
	system("cls");
	time_t now = time(0);
	cout << ctime(&now) << endl;
	this->MoveCursorPoint(57,0);
	cout << "Console Color: " + this->Color;
	this->MoveCursorPoint(30,3);
	cout << "METRO MANAGMENT SYSTEM" << endl;
	this->MoveCursorPoint(15,4);
	cout.width(50);
	cout.fill('=');
	cout << " ";
	
	for(int y = 3; y < 20; y++)
	{
		this->MoveCursorPoint(15,y);
		cout << "|";
		this->MoveCursorPoint(64,y);
		cout << "|";
	}
	for(int x=15; x < 65; x++)
	{
		this->MoveCursorPoint(x, 20);
		cout << "+";
	}
	for(int x = 16; x< 64; x++)
	{
		this->MoveCursorPoint(x,18);
		cout << "=";
	}
}


void MainPanel::MainMenu()
{
	this->MenuItem[0] = "[1] LINE STATEMENT";
	this->MenuItem[1] = "[2] ADD LINE";
	this->MenuItem[2] = "[3] REFACTOR LINE";
	this->MenuItem[3] = "[4] SETTINGS";
	this->MenuItem[4] = "[5] CLOCK INFORMATION";
	this->MenuItem[5] = "[X] QUIT APPLICATION";
	for(int menu = 0; menu <= 5; menu++)
	{
		this->MoveCursorPoint(20, 6+(menu*2));
		cout << this->MenuItem[menu];
	}
	this->MoveCursorPoint(15,22);
	cout << "Yapmak istediginiz islemi seciniz:[]";
	this->MoveCursorPoint(50,22);
}

void MainPanel::HandleOperation(){
	this->PrintOptions();
	
		this->selection = getch();
		switch(this->selection)
		{
			case '1':
				this->manager.HatDurumu();
				usleep(3 * this->delayAsMicroSecond);
				this->HandleOperation();	
				break;
			case '2':
				this->MainTheme();
				this->MoveCursorPoint(18,6);
				if(this->manager.HatOlustur() || !this->manager.HatOlustur())
				{
					usleep(3 * this->delayAsMicroSecond);
					this->HandleOperation();
				}
				
				break;
			case '3':
				this->MainTheme();
				if(this->manager.BakimaAl() || !this->manager.BakimaAl())
				{
					usleep(3 * this->delayAsMicroSecond);
					this->HandleOperation();
				}
				break;
			case '4':
				this->HandleSettings();
				break;
			case '5':
				break;
			case 'x':
				this->manager.SaveData();
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
		this->MoveCursorPoint(20, 6+(menu*2));
		cout << this->MenuItem[menu];
	}
	this->MoveCursorPoint(15,22);
	cout << "Yapmak istediginiz islemi seciniz:[ ]";
	this->MoveCursorPoint(50,22);
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
}

void MainPanel::MoveCursorPoint(short x, short y)
{
	COORD post = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), post);
}
