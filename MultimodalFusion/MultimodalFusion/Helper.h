//Helper.h

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
namespace MultimodalFusion
{

//Helper class that provides helping static functions for different purposes
class Helper
{
		
public:
	static vector<string> split(const char *str, char c); //splits a string str according to a delimiter c
	static double getX(std::string position, char delimiter);		//gets x coordinate from a position string with a format x;y (the delimiter can be specified in 2nd argument)
	static double getY(std::string position, char delimiter);		//gets y coordinate from a position string with a format x;y (the delimiter can be specified in 2nd argument)

private:
	
};
}