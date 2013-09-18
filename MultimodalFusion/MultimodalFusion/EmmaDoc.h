//EmmaDoc.h

#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "InputEvent.h"
#include "FrameResult.h"

namespace MultimodalFusion
{

class EmmaDoc
{
		
public:
	EmmaDoc();
	~EmmaDoc();


	void setContainerType(std::string emmaContainerType);
	std::string getContainerType(); //i.e. single interpretation, one-of, sequential
	
	void addInputEvent(InputEvent input);
	std::vector<InputEvent> getInputEvents();

	bool isValid();
	void validate();

	void setVersion(std::string docVersion);
	std::string getVersion();

	void setXmlNameSpace(std::string docXmlNameSpace);
	std::string getXmlNameSpace();

	std::string print();

private:
	//Header attributes
	std::string version;
	std::string xmlNameSpace;


	std::string containerType;
	std::vector<InputEvent> inputEvents;

	bool valid; //this indicates if the creation an emma doc was sucessful (parsing of xml)
	
	std::string printHeaderBeginning();
	std::string printHeaderEnding();

};
}