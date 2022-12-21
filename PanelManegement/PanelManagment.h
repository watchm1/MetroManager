#include <iostream>
#include <string>
#include <conio.h>
#include "..\LineManagment\LineManagment.h"
#include<unistd.h>
#include <iomanip>
#include <locale.h>
#include <ctime>
#include "windows.h"
#include <fstream>
#include <ctype.h>
#include<unistd.h>


using namespace std;

class MainPanel {
	private:
		string MenuItem[6];
		char selection;
		string Color = "Default";
		void HandleSettings();
		void PrintOptions();
		void MainTheme();
		void MainMenu();
	    int getInput(); 
	    LineManager manager;
	    unsigned int delayAsMicroSecond = 1000000;
	    void MoveCursorPoint(short x, short y);
		// line manager
	public:
		  void HandleOperation();
};
