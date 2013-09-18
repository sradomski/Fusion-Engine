//#include "stdafx.h"
#include "FrameTrigger.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	FrameTrigger::FrameTrigger(InputEvent ie)
	{
		triggerInputEvent = ie;

		activated = false;
	}

	/*
	FrameTrigger::FrameTrigger(MeaningFrame mf)
	{
		triggerMeaningFrame = mf;

		isTriggerInputEvent = false;
		isTriggerMeaningFrame = true;

		activated = false;
	}
	*/

	FrameTrigger::~FrameTrigger()
	{

	}

	void FrameTrigger::processInput(InputEvent eventReceived)
	{
		if(!activated)
			activated = isTriggerInputEventEquivalentTo(eventReceived);
		
	}

	bool FrameTrigger::isValid()
	{	
		return activated;
	}

	void FrameTrigger::reset()
	{
		activated = false;
	}

	bool FrameTrigger::isTriggerInputEventEquivalentTo(InputEvent inputEventReceived)
	{
		//Compare trigger input event with the one received
		std::string inputEventReceivedMedium = inputEventReceived.getMedium();
		std::string inputEventReceivedMode = inputEventReceived.getMode();
		std::string inputEventReceivedTokens = inputEventReceived.getTokens();

		std::transform(inputEventReceivedMedium.begin(), inputEventReceivedMedium.end(), inputEventReceivedMedium.begin(), ::tolower);
		std::transform(inputEventReceivedMode.begin(), inputEventReceivedMode.end(), inputEventReceivedMode.begin(), ::tolower);
		std::transform(inputEventReceivedTokens.begin(), inputEventReceivedTokens.end(), inputEventReceivedTokens.begin(), ::tolower);

		std::string triggerInputEventMedium = triggerInputEvent.getMedium();
		std::string triggerInputEventMode = triggerInputEvent.getMode();
		std::string triggerInputEventTokens = triggerInputEvent.getTokens();

		std::transform(triggerInputEventMedium.begin(), triggerInputEventMedium.end(), triggerInputEventMedium.begin(), ::tolower);
		std::transform(triggerInputEventMode.begin(), triggerInputEventMode.end(), triggerInputEventMode.begin(), ::tolower);
		std::transform(triggerInputEventTokens.begin(), triggerInputEventTokens.end(), triggerInputEventTokens.begin(), ::tolower);

		bool result = (inputEventReceivedMedium == triggerInputEventMedium) &&
			(inputEventReceivedMode == triggerInputEventMode) &&
			(inputEventReceivedTokens == triggerInputEventTokens);

		return result;
	}

	std::string FrameTrigger::print()
	{
		stringstream ss;

		ss << "Trigger || " << "Activated=" << activated << " || " << triggerInputEvent.print() << "\n";

		return ss.str();
	}

}
