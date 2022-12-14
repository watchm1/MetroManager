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
  
  Line lineData2;
  lineData2.ModelName = "model 2";
  lineData2.ModelUniqueID = "test 2";
  lineData2.isActive = 0;
  
  RootObject<Line> root;
  root.lists.push_back(lineData); 
  root.lists.push_back(lineData2);
  lineService.WriteData("lines.txt", root);
  
  return 0;
}                                  