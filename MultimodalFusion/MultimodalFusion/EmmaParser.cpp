//#include "stdafx.h"
#include <stdlib.h>
#include "EmmaParser.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	EmmaDoc EmmaParser::parseEmma(std::string emmaXml)
	{

		
        EmmaDoc emmaDoc;

		pugi::xml_document doc;
		pugi::xml_parse_result result;
		
		result = doc.load(emmaXml.c_str());
		if(result)
		{
			cout << "Emma xml parsing successful \n";

			//Getting the root node
			pugi::xml_node rootNode = doc.first_element_by_path("emma:emma");

			//Parsing header of the emma document
			EmmaParser::parseHeader(emmaDoc, rootNode);

			//Getting the first child (first container which at this moment of implementation should be an interpretation or one-of container
			pugi::xml_node containerNode = rootNode.first_child();

			EmmaParser::parseContainer(emmaDoc, containerNode);

			emmaDoc.validate();
				
		}
		else
			cout << "Emma xml parsing IS not successful \n";

		
		return emmaDoc;
	}

	EmmaDoc EmmaParser::parseEmmaFromFile(std::string emmaXmlFilePath)
	{
		EmmaDoc emmaDoc;

		pugi::xml_document doc;
		pugi::xml_parse_result result;
		
		result = doc.load_file(emmaXmlFilePath.c_str());


		if(result)
		{
			cout << "Emma xml parsing successful \n";
			
			//Getting the root node
			pugi::xml_node rootNode = doc.first_element_by_path("emma:emma");

			//Parsing header of the emma document
			EmmaParser::parseHeader(emmaDoc, rootNode);

			//Getting the first child (first container which at this moment of implementation should be an interpretation or one-of container
			pugi::xml_node containerNode = rootNode.first_child();

			EmmaParser::parseContainer(emmaDoc, containerNode);

			emmaDoc.validate();

		}
		else
			cout << "Emma xml parsing IS not successful \n";

		
		return emmaDoc;
	}

	void EmmaParser::parseHeader(EmmaDoc &doc, pugi::xml_node rootNode)
	{
		std::string version = rootNode.attribute("version").value();
		std::string nameSpace = rootNode.attribute("xmlns:emma").value();

		doc.setVersion(version);
		doc.setXmlNameSpace(nameSpace);
	}

	void EmmaParser::parseContainer(EmmaDoc &doc, pugi::xml_node containerNode)
	{
		std::string containerName = containerNode.name();

		if(containerName == "emma:interpretation")
		{
			doc.setContainerType("interpretation");
			parseInterpretation(doc, containerNode);
		}
		else if(containerName == "emma:one-of")
		{
			doc.setContainerType("one-of");

			for (pugi::xml_node interpretation = containerNode.first_child(); interpretation; interpretation = interpretation.next_sibling())
			{
				parseInterpretation(doc, interpretation);
			}
		}
	}

	void EmmaParser::parseInterpretation(EmmaDoc &doc, pugi::xml_node interpretationNode)
	{
		

		std::string id = interpretationNode.attribute("id").value();
		std::string medium = interpretationNode.attribute("emma:medium").value();
		std::string mode = interpretationNode.attribute("emma:mode").value();
		std::string confidence = interpretationNode.attribute("emma:confidence").value();

		double numericConfidence = 0;

		if(confidence == "") //No confidence value was provided for input, assuming max confidence
			numericConfidence = 1;
		else
			numericConfidence = atof(confidence.c_str()); //CAREFUL: NOT CHECKING IF THIS STRING IS ACTUALLY A DOUBLE

		std::string inputEventTokens = "";

		std::string noInput = interpretationNode.attribute("emma:no-input").value();
		std::string uninterpretedInput = interpretationNode.attribute("emma:uninterpreted").value();

		
		if((noInput == "true") || (uninterpretedInput == "true"))
			numericConfidence = 0;
		else
		{
			//Fetching the tokens from the literal element (if it exists)
			//pugi::xml_node interpretationChild = interpretationNode.first_child();

			std::string interpretationChildName = interpretationNode.first_child().name();

			if(interpretationChildName == "emma:literal")
			{
				inputEventTokens = interpretationNode.first_child().child_value();
			}
		}

		InputEvent input(id, medium, mode, numericConfidence, inputEventTokens);

		doc.addInputEvent(input);
		
	}

}
