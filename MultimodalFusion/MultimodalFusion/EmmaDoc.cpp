//#include "stdafx.h"
#include "EmmaDoc.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	EmmaDoc::EmmaDoc()
	{
		version ="1.0";
		xmlNameSpace = "http://www.w3.org/2003/04/emma";

		containerType = "";
		valid = false;
	}

	EmmaDoc::~EmmaDoc()
	{

	}

	void EmmaDoc::setVersion(std::string docVersion)
	{
		version = docVersion;
	}

	std::string EmmaDoc::getVersion()
	{
		return version;
	}

	void EmmaDoc::setXmlNameSpace(std::string docXmlNameSpace)
	{
		xmlNameSpace = docXmlNameSpace;
	}

	std::string EmmaDoc::getXmlNameSpace()
	{
		return xmlNameSpace;
	}

	void EmmaDoc::setContainerType(std::string emmaContainerType)
	{
		containerType = emmaContainerType;
	}

	std::string EmmaDoc::getContainerType()
	{
		return containerType;
	}

	void EmmaDoc::addInputEvent(InputEvent input)
	{
		inputEvents.push_back(input);
	}

	vector<InputEvent> EmmaDoc::getInputEvents()
	{
		return inputEvents;
	}

	bool EmmaDoc::isValid()
	{
		return valid;
	}

	void EmmaDoc::validate()
	{
		valid = true;
	}

	std::string EmmaDoc::print()
	{
		stringstream ss;

		ss << printHeaderBeginning();

		ss << printHeaderEnding();

		return ss.str();
	}

	std::string EmmaDoc::printHeaderBeginning()
	{
		stringstream ss;

		ss << "<emma:emma version=\"" << version << "\" xmlns:emma=\"" << xmlNameSpace << "\">";

		return ss.str();
	}

	std::string EmmaDoc::printHeaderEnding()
	{
		stringstream ss;

		ss << "</emma:emma>";

		return ss.str();
	}
}
