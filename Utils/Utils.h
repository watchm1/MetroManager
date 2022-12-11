#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
// this scripts will be about to drawing library
// dynamicly drawing library

//TODO(MuhammedAli#1#): Adding Middlewares About Input Check System
//TODO(MuhammedAli#2#): Add opencv library and make draw algorithm 
//TODO(MuhammedAli#3#): Making MetroManagment Controllers about dealing with Data Access Helper
using namespace std;

class Utils {
	private:
		 // for id generator
	public:
		
		static string GenerateUniqueID();
		static string ConvertIntToString(int value);
		
};
#endif
