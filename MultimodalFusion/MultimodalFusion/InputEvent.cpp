//#include "stdafx.h"
#include "InputEvent.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	InputEvent::InputEvent()
	{
		id = "";
		medium = "";
		mode = "";
		confidence = 0;
		tokens = "";
	}

	InputEvent::InputEvent(std::string eventId, std::string eventMedium, std::string eventMode, double eventConfidence, std::string eventTokens)
	{
		id = eventId;
		medium = eventMedium;
		mode = eventMode;
		confidence = eventConfidence;
		tokens = eventTokens;
	}

	InputEvent::~InputEvent()
	{

	}

	void InputEvent::setId(std::string eventId)
	{
		id = eventId;
	}

	void InputEvent::setMedium(std::string eventMedium)
	{
		medium = eventMedium;
	}

	void InputEvent::setMode(std::string eventMode)
	{
		mode = eventMode;
	}

	void InputEvent::setConfidence(double eventConfidence)
	{
		confidence = eventConfidence;
	}

	void InputEvent::setTokens(std::string eventTokens)
	{
		tokens = eventTokens;
	}

	std::string InputEvent::getId()
	{
		return id;
	}

	std::string InputEvent::getMedium()
	{
		return medium;
	}

	std::string InputEvent::getMode()
	{
		return mode;
	}

	double InputEvent::getConfidence()
	{
		return confidence;
	}

	std::string InputEvent::getTokens()
	{
		return tokens;
	}

	std::string InputEvent::print()
	{
		stringstream ss;

		ss << "Id=" << id << " || Medium=" << medium << " || Mode=" << mode << " || Confidence=" << confidence << " || Tokens=" << tokens << "\n"; 

		return ss.str();
	}

}
