//UimlDoc.h

#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "UiElement.h"

namespace MultimodalFusion
{

class UimlDoc
{
		
public:
	UimlDoc();
	~UimlDoc();

	void addUiElement(UiElement element);

	std::vector<UiElement> getUiElements();

	bool isValid();
	void validate();

private:
	std::vector<UiElement> uiElements;
	bool valid; //indicates if parsing of xml was valid

};
}
