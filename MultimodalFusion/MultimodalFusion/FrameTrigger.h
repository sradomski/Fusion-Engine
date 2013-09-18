//FrameTrigger.h

#pragma once

#ifndef FRAMETRIGGER_Included
#define	FRAMETRIGGER_Included
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "InputEvent.h"

namespace MultimodalFusion
{

class FrameTrigger
{
		
public:
	FrameTrigger(InputEvent ie);
	~FrameTrigger();

	void processInput(InputEvent eventReceived);

	bool isValid();

	std::string print();

	void reset();

private:
	InputEvent triggerInputEvent;			
	
	bool activated;

	bool isTriggerInputEventEquivalentTo(InputEvent inputEventReceived); //compares the trigger input event with the one received to see if they match
};
}
#endif	