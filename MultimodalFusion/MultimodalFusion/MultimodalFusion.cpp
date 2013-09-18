// MultimodalFusion.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "MultimodalFusion.h"
#include <stdexcept>

#if defined(_WIN32) || defined(__WIN32__)
    #define  LIB_EXPORT __declspec(dllexport)
#elif defined(linux) || defined(__linux)
 #define LIB_EXPORT
#endif

using namespace std;

namespace MultimodalFusion
{
	MULTIMODALFUSION_API MultimodalFusion::MultimodalFusion()
	{
		
	}
	MULTIMODALFUSION_API MultimodalFusion::~MultimodalFusion()
	{
		
	}

   MULTIMODALFUSION_API std::string MultimodalFusion::sayHello()
   {
	   stringstream result;
	   result << "Hello world, from MultimodalFusion!";
	  
	   return result.str();
   }

   MULTIMODALFUSION_API std::string MultimodalFusion::interpretInputFromString(std::string emmaXml)
   {
	  EmmaDoc input = EmmaParser::parseEmma(emmaXml);
	   std::string inputInterpretation;

	   if(input.isValid()) //if input was correctly parsed and information retrieved:
	   {
			if(input.getContainerType() == "interpretation")
				inputInterpretation = fusionManager.interpretInput(input);
			else if(input.getContainerType() == "one-of")
				inputInterpretation = fusionManager.interpretExclusiveInput(input);
			else if(input.getContainerType() == "sequential")
				inputInterpretation = fusionManager.interpretSequentialInput(input);
	   } //else create special emma response indicating a problem has occured
	   else
		   inputInterpretation = fusionManager.handleInvalidInput();

	   return inputInterpretation;
   }

   MULTIMODALFUSION_API std::string MultimodalFusion::interpretInputFromFile(std::string emmaXmlFilePath)
   {
	   EmmaDoc input = EmmaParser::parseEmmaFromFile(emmaXmlFilePath);
	   std::string inputInterpretation;

	   if(input.isValid()) //if input was correctly parsed and information retrieved:
	   {
			if(input.getContainerType() == "interpretation")
				inputInterpretation = fusionManager.interpretInput(input);
			else if(input.getContainerType() == "one-of")
				inputInterpretation = fusionManager.interpretExclusiveInput(input);
			else if(input.getContainerType() == "sequential")
				inputInterpretation = fusionManager.interpretSequentialInput(input);
	   } //else create special emma response indicating a problem has occured
	   else
		   inputInterpretation = fusionManager.handleInvalidInput();

	   return inputInterpretation;
   }

   MULTIMODALFUSION_API bool MultimodalFusion::setUIMLFromString(std::string uimlXml)
   {
	   UimlDoc uimlDoc = UimlParser::parseUimlFromString(uimlXml);

	   fusionManager.createContext(uimlDoc);

	   //Debugging
	   //cout << "Fusion created the following frames: \n" << fusionManager.printContext();

	   return false;
   }

   MULTIMODALFUSION_API bool MultimodalFusion::setUIMLFromFile(std::string uimlXmlFilePath)
   {
	   UimlDoc uimlDoc = UimlParser::parseUimlFromFile(uimlXmlFilePath);

	   bool parsingSucessful = uimlDoc.isValid();

	   if(parsingSucessful)
		fusionManager.createContext(uimlDoc);

	   //Debugging
	   //cout << "Fusion created the following frames: \n" << fusionManager.printContext();

	   return uimlDoc.isValid();
   }


   MULTIMODALFUSION_API bool MultimodalFusion::setSMUIMLFromString(std::string smuimlXml)
   {
	   SmuimlDoc smuimlDoc = SmuimlParser::parseSmuiml(smuimlXml);

	   fusionManager.createContext(smuimlDoc);

	   return false;
   }

}


