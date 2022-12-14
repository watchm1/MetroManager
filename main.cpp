#include <iostream>
#include <vector>
#include "Models/Line.h"
#include "Models/Subway.h"
#include "Utils/JSONHelper.h"
#include "Utils/RootObjects.h"
int main() {
  
  
  Line lineData;
  NOSqlService<RootObject<Line>> lineService;
  lineData.ModelUniqueID = "test1";
  lineData.ModelName = "model 1";
  lineData.isActive = 1;
  RootObject<Line> root;
  root.lists.push_back(lineData); 
  RootObject<Line> newLine = lineService.WriteData("lines.txt", root);
  std::cout << newLine.lists[0].ModelName << std::endl;
  
  return 0;
}                                  