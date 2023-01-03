#include "GraphicHelper.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <conio.h>
#include <string>
std::string GraphicHelper::exec(std::string command)
{
	char buffer[128];//Buffer parametresine yazdırılabilecek maksimum karakter sayısını gösterir 
	std::string result = "";
	FILE* pipe = popen(command.c_str(), "r");
	if(!pipe)
	{
		std::cout << "popen failed" << std::endl;
	}
	
	while(!feof(pipe))//Fonksiyon stream parametresi ile gösterilen dosya akışının sonuna erişilip erişilmediğini kontrol eder
	{
		if(fgets(buffer, 128, pipe) != NULL)
		{
			result += buffer;
		}
	}
	
	pclose(pipe);
	return result;
}
void GraphicHelper::main()
{
	std::string gotoLocation = this->exec("start .\\Config\\Graphs\\draw.exe");
	std::string run = this->exec("dir");
	system(run.c_str());
	system("PAUSE");
	getch();
}