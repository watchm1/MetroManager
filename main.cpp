#include <iostream>
#include <vector>
#include "Models/Line.h"
#include "Models/Subway.h"
#include "Utils/JSONHelper.h"

int main() {
  
  
  Line lineData;
  NOSqlService<Line> lineService;
  lineData.ModelUniqueID = "test1";
  lineData.ModelName = "model 1";
  lineData.isActive = 1;
  Line newLine = lineService.WriteData("lines.txt", lineData);
  std::cout << newLine.ModelName << std::endl;
  
  return 0;
}                                  