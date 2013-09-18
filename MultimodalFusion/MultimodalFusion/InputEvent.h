//InputEvent.h

#pragma once

#include <string>
#include <sstream>

namespace MultimodalFusion
{

class InputEvent
{
		
public:
	InputEvent();
	InputEvent(std::string eventId, std::string eventMedium, std::string eventMode, double eventConfidence, std::string eventTokens);
	~InputEvent();

	void setId(std::string eventId);
	void setMedium(std::string eventMedium);
	void setMode(std::string eventMode);
	void setConfidence(double eventConfidence);
	void setTokens(std::string eventTokens);

	std::string getId();
	std::string getMedium();
	std::string getMode();
	double getConfidence();
	std::string getTokens();

	std::string print();

private:
	//These are attributes inspired by the structure of EMMA docs
	std::string id;
	std::string medium; //e.g. acoustic, visual, tactile
	std::string mode;	//e.g. voice, gesture, pen input
	double confidence;
	std::string tokens;
	
};
}