#include <iostream>
#include <vector>
#include "Middlewares/DataMiddleware.h"
int main() {
  RootObject<Line> lineRoot;
  Line example;
  example.ModelUniqueID = "asdşalmsdas";
  example.ModelName = "muhammed ali test 1";
  example.isActive = 0;
  
  Line example2;
  example2.ModelUniqueID = "asdadadsas";
  example2.ModelName = "muhammed ali test 2";
  example2.isActive = 1;
  
  lineRoot.lists.push_back(example);
  lineRoot.lists.push_back(example2);
  
  DataMiddleWare middleware;
  //middleware.WriteAll(lineRoot);  

  //DataMiddleWare middleware;
  
  RootObject<Line> root;
  
  root = middleware.GetAllDataFromLines();
  std::cout << root.lists[0].ModelName << std::endl;
  return 0;
}