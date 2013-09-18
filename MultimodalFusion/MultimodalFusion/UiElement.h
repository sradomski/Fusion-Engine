//UiElement.h

#pragma once

#include <string>
#include <sstream>

namespace MultimodalFusion
{

class UiElement
{
		
public:
	UiElement(std::string elementId, std::string elementType, std::string elementText, std::string elementLabel, std::string elementDescription, 
		double elementX, double elementY, double elementWidth, double elementHeight);
	~UiElement();

	std::string getId();
	std::string getType();
	std::string getText();
	std::string getLabel();
	std::string getDescription();

	double getX();
	double getY();
	double getWidth();
	double getHeight();

private:
	std::string id;			//id of the element, set by the developer on the UIML xml
	std::string type;		//e.g. button, text label, virtual character
	std::string text;		//text of the element (generally the text visible in buttons)
	std::string label;		//label of the element (this is an alternative to text to form speech commands)
	std::string description;

	double x;
	double y;
	double width;
	double height;
};
}