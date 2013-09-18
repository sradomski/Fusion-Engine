//EmmaParser.h

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "EmmaDoc.h"
#include "pugixml.hpp"

namespace MultimodalFusion
{

//Creates a EmmaDoc object from emma input xml so that multimodal fusion has easy access to input properties
class EmmaParser
{
		
public:
	static EmmaDoc parseEmma(std::string emmaXml);
	static EmmaDoc parseEmmaFromFile(std::string emmaXml);

private:
	static void parseHeader(EmmaDoc &doc, pugi::xml_node rootNode);
	static void parseContainer(EmmaDoc &doc, pugi::xml_node containerNode);
	static void parseInterpretation(EmmaDoc &doc, pugi::xml_node interpretationNode);
	

};
}