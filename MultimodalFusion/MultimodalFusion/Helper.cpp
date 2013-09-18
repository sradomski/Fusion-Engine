//#include "stdafx.h"
#include "Helper.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	vector<string> Helper::split(const char *str, char c)
	{
		std::vector<string> result;

		while(1)
		{
			const char *begin = str;

			while(*str != c && *str)
					str++;

			result.push_back(string(begin, str));

			if(0 == *str++)
					break;
		}

		return result;
	}

	double Helper::getX(std::string position, char delimiter)
	{
		std::vector<string> tokens = Helper::split(position.c_str(), delimiter);
		std::vector<string>::iterator i = tokens.begin();
		std::string x = *i;

		return atof(x.c_str());
	}

	double Helper::getY(std::string position, char delimiter)
	{
		std::vector<string> tokens = Helper::split(position.c_str(), delimiter);
		std::vector<string>::iterator i = tokens.begin();
		++i;
		std::string y = *i;

		return atof(y.c_str());
	}

}
