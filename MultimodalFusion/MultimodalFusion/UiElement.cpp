//#include "stdafx.h"
#include "UiElement.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	UiElement::UiElement(std::string elementId, std::string elementType, std::string elementText, std::string elementLabel, std::string elementDescription, 
		double elementX, double elementY, double elementWidth, double elementHeight)
	{
		id = elementId;
		type = elementType;
		text = elementText;
		label = elementLabel;
		description = elementDescription;
		x = elementX;
		y = elementY;
		width = elementWidth;
		height = elementHeight;
	}

	UiElement::~UiElement()
	{

	}

	std::string UiElement::getId()
	{
		return id;
	}

	std::string UiElement::getType()
	{
		return type;
	}

	std::string UiElement::getText()
	{
		return text;
	}

	std::string UiElement::getLabel()
	{
		return label;
	}

	std::string UiElement::getDescription()
	{
		return description;
	}

	double UiElement::getX()
	{
		return x;
	}

	double UiElement::getY()
	{
		return y;
	}

	double UiElement::getWidth()
	{
		return width;
	}

	double UiElement::getHeight()
	{
		return height;
	}
}
