//UimlParser.h

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "UimlDoc.h"
#include "pugixml.hpp"
#include "Helper.h"
#include "UiElement.h"

namespace MultimodalFusion
{

//Creates a UimlDoc object from the uiml xml so that multimodal fusion has easy access to all relevant UI information
class UimlParser
{
		
public:
	static UimlDoc parseUimlFromString(std::string uimlXml);
	static UimlDoc parseUimlFromFile(std::string uimlXmlFilePath);

private:
	static void parseButtons(UimlDoc &uimlDoc, pugi::xml_node structure, pugi::xml_node style);

};
}