//MultimodalFusion.h

#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "UimlDoc.h"
#include "SmuimlDoc.h"
#include "EmmaDoc.h"
#include "FusionManager.h"

#include "UimlParser.h"
#include "SmuimlParser.h"
#include "EmmaParser.h"


namespace MultimodalFusion
{

#if defined(_WIN32) || defined(__WIN32__)
	#ifdef MULTIMODALFUSION_EXPORT
		#define MULTIMODALFUSION_API __declspec(dllexport) 
	#else
		#define MULTIMODALFUSION_API
	#endif
#else
	#define MULTIMODALFUSION_API
#endif

/*
This class handles external communication with other projects that will use MultimodalFusion.dll
*/
class MultimodalFusion
{
		
public:
	MULTIMODALFUSION_API MultimodalFusion();
	MULTIMODALFUSION_API ~MultimodalFusion();
	MULTIMODALFUSION_API std::string sayHello();

	MULTIMODALFUSION_API std::string interpretInputFromString(std::string emmaXml);	//Receives a XML EMMA doc representing input, returning a emma xml string representing interpretation of that input;
	MULTIMODALFUSION_API std::string interpretInputFromFile(std::string emmaXmlFilePath);

	MULTIMODALFUSION_API bool setUIMLFromString(std::string uimlXml); //Receives a XML UIML document to give information about the current UI elements and properties
	MULTIMODALFUSION_API bool setUIMLFromFile(std::string uimlXmlFilePath); //Receives a XML UIML document to give information about the current UI elements and properties

	MULTIMODALFUSION_API bool setSMUIMLFromString(std::string smuimlXml); //Receives a XML SMUIL document to set how multimodal interaction should be processed, returning indication of the successfulness of this process
	

private:

	//Variables
	FusionManager fusionManager; //Handles available fusion algorithms, creating context for applications, receiving input and providing interpretations

	//Methods

};

}
