//SmuimlParser.h

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "SmuimlDoc.h"
#include "pugixml.hpp"

namespace MultimodalFusion
{

//Creates a SmuimlDoc object from the uiml xml so that multimodal fusion has easy access to all relevant UI information
class SmuimlParser
{
		
public:
	static SmuimlDoc parseSmuiml(std::string smuimlXml);

private:
	

};
}