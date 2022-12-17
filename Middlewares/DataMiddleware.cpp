#include "DataMiddleware.h"
#include <algorithm>


RootObject<Line> DataMiddleWare::GetAllDataFromLines()
{
	return this->lineService.ReadData(this->configs.GetPathOfLines());
}

bool DataMiddleWare::WriteAll(RootObject<Line> lineRoot){
	this->lineService.WriteData(this->configs.GetPathOfLines(), lineRoot);
	return true;
	
}




