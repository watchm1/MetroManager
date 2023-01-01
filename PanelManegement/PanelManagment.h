#include "..\LineManagment\LineManagment.h"



using namespace std;

class MainPanel {
	private:
		string MenuItem[7];
		char selection;
		string Color = "Default";
		void HandleSettings();
		void PrintOptions();
		void MainTheme();
		void MainMenu();
	    int getInput(); 
	    LineManager manager;
	    unsigned int delayAsMicroSecond = 1000000;
	    
		void AddNewSubway();
		// line manager
	public:
		  void HandleOperation();
};
