//#include "stdafx.h"
#include "UimlDoc.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	UimlDoc::UimlDoc()
	{
		valid = false;
	}

	UimlDoc::~UimlDoc()
	{

	}

	void UimlDoc::addUiElement(UiElement element)
	{
		uiElements.push_back(element);
	}

	std::vector<UiElement> UimlDoc::getUiElements()
	{
		return uiElements;
	}

	bool UimlDoc::isValid()
	{
		return valid;
	}

	void UimlDoc::validate()
	{
		valid = true;
	}
}
