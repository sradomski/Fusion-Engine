//#include "stdafx.h"
#include "FusionManager.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	FusionManager::FusionManager()
	{
		fusionAlgorithm = 0; //frame-based fusion is the default algorithm used
	}

	FusionManager::~FusionManager()
	{

	}

	void FusionManager::setFusionAlgorithm(int algorithmId)
	{
		switch(algorithmId)
		{
		case 0: //frame-based fusion
			fusionAlgorithm = 0; break;
		default: break;
		}
	}

	void FusionManager::createContext(UimlDoc uimlDoc)
	{
		switch(fusionAlgorithm)
		{
		case 0: //frame-based fusion
			makeContextFrames(uimlDoc); 
			break;

		default: break;
		}
	}

	void FusionManager::createContext(SmuimlDoc uimlDoc)
	{

	}

	void FusionManager::makeContextFrames(UimlDoc uimlDoc)
	{
		std::vector<UiElement> uiElements = uimlDoc.getUiElements(); 

		std::string elementType;

		for(std::vector<UiElement>::iterator it = uiElements.begin(); it != uiElements.end(); ++it) 
		{
			elementType = (*it).getType();

			if(elementType == "button")
			{
				addButtonFrames((*it));
			}
		}
	}

	void FusionManager::addButtonFrames(UiElement button)
	{
		//This function will create frames for the button received (Note: at the moment this frames are created with no special criteria in mind)

		MeaningFrame buttonSpeechOnlyFrame; //With this frame, button id is sent as result when using the button's label or text for voice only command

		buttonSpeechOnlyFrame.setMode("par_and");

		std::string buttonSpeechCommand;
		std::string buttonLabel = button.getLabel();

		if(buttonLabel != "") //label was provided
			buttonSpeechCommand = buttonLabel;
		else
			buttonSpeechCommand = button.getText(); //Note: this text may have to be checked for integrity (non-alpha characters) ?

		std::string id = button.getId();
		std::string medium = "acoustic";
		std::string mode = "voice";
		double confidence = 0;
		std::string eventTokens = buttonSpeechCommand;

		InputEvent triggerActivationEvent(id, medium, mode, confidence, eventTokens);

		FrameTrigger buttonSpeechTrigger(triggerActivationEvent);
		FrameResult buttonSpeechResult(id);

		buttonSpeechOnlyFrame.addTrigger(buttonSpeechTrigger);
		buttonSpeechOnlyFrame.addResult(buttonSpeechResult);


		//Adding frame to set of frames
		contextFrames.push_back(buttonSpeechOnlyFrame);

		MeaningFrame buttonSpeechAndGestureMoveSelectionFrame; //This frame allows to perform a gesture (up, down, left, right) and a voice command (move)
	}

	void FusionManager::makeContextFrames(SmuimlDoc smuimlDoc)
	{

	}
	
	std::string FusionManager::interpretInput(EmmaDoc input)
	{
		stringstream emmaResult;

		//Putting emma header into response
		emmaResult << "<emma:emma version=\"1.0\" xmlns:emma=\"http://www.w3.org/2003/04/emma\">";

		std::vector<InputEvent> eventsReceived = input.getInputEvents();

		stringstream resultsOfActivatedFrames;

		//Giving the input event to each frame to check triggers and validate the frame (if it can be validated)
		for(std::vector<InputEvent>::iterator it1 = eventsReceived.begin(); it1 != eventsReceived.end(); ++it1) 
		{
			for(std::vector<MeaningFrame>::iterator it2 = contextFrames.begin(); it2 != contextFrames.end(); ++it2) 
			{
				if(!(*it2).isValid())
				{
					(*it2).processInput((*it1));

					if((*it2).isValid())
						resultsOfActivatedFrames << (*it2).getResultsAsEmmaInterpretations();
				}
			}
		}

		int numberOfValidFrameResults = getNumberOfValidFrameResults();

		if(numberOfValidFrameResults == 0) //return uninterpreted emma interpretation
		{
			emmaResult << "<emma:interpretation id=\"interp1\" emma:uninterpreted=\"true\"/>";
		}
		else if(numberOfValidFrameResults == 1) //return a single interpretation container
		{
			emmaResult << resultsOfActivatedFrames.str();
		}
		else if(numberOfValidFrameResults > 1) //return several interpretations inside a group container
		{
			emmaResult << "<emma:group id=\"grp\">";
			emmaResult << resultsOfActivatedFrames.str();
			emmaResult << "</emma:group>";
		}

		emmaResult << "</emma:emma>";

		resetValidFrames();

		return emmaResult.str();
	}

	std::string FusionManager::interpretExclusiveInput(EmmaDoc input)
	{
		stringstream emmaResult;

		//Putting emma header into response
		emmaResult << "<emma:emma version=\"1.0\" xmlns:emma=\"http://www.w3.org/2003/04/emma\">";

		std::vector<InputEvent> eventsReceived = input.getInputEvents();

		InputEvent highestConfidenceInputEvent;
		double maxConfidence = 0;
		double currentInputEventConfidence = 0;

		if(eventsReceived.size() > 0)
		{
			//Select highest confidence interpretation
			for(std::vector<InputEvent>::iterator it1 = eventsReceived.begin(); it1 != eventsReceived.end(); ++it1) 
			{
				currentInputEventConfidence = (*it1).getConfidence();

				if(currentInputEventConfidence > maxConfidence)
				{
					highestConfidenceInputEvent = (*it1);
					maxConfidence = currentInputEventConfidence;
				}
			}

			stringstream resultsOfActivatedFrames;

			for(std::vector<MeaningFrame>::iterator it2 = contextFrames.begin(); it2 != contextFrames.end(); ++it2) 
			{
				if(!(*it2).isValid())
				{
					(*it2).processInput(highestConfidenceInputEvent);

					if((*it2).isValid())
						resultsOfActivatedFrames << (*it2).getResultsAsEmmaInterpretations();
				}
			}

			int numberOfValidFrameResults = getNumberOfValidFrameResults();

			if(numberOfValidFrameResults == 0) //return uninterpreted emma interpretation
			{
				emmaResult << "<emma:interpretation id=\"interp1\" emma:uninterpreted=\"true\"/>";
			}
			else if(numberOfValidFrameResults == 1) //return a single interpretation container
			{
				emmaResult << resultsOfActivatedFrames.str();
			}
			else if(numberOfValidFrameResults > 1) //return several interpretations inside a group container
			{
				emmaResult << "<emma:group id=\"grp\">";
				emmaResult << resultsOfActivatedFrames.str();
				emmaResult << "</emma:group>";
			}
		}

		emmaResult << "</emma:emma>";

		resetValidFrames();

		return emmaResult.str();
	}

	std::string FusionManager::interpretSequentialInput(EmmaDoc input)
	{
		stringstream emmaResult;

		return emmaResult.str();
	}

	std::string FusionManager::handleInvalidInput()
	{
		stringstream emmaResult;

		return emmaResult.str();
	}

	int FusionManager::getNumberOfValidFrameResults()
	{
		int result = 0;

		for(std::vector<MeaningFrame>::iterator it2 = contextFrames.begin(); it2 != contextFrames.end(); ++it2) 
		{
			if((*it2).isValid())
				result += (*it2).getNumberOfResults();
		}
		return result;
	}

	void FusionManager::resetValidFrames()
	{
		for(std::vector<MeaningFrame>::iterator it = contextFrames.begin(); it != contextFrames.end(); ++it) 
		{
			if((*it).isValid())
				(*it).reset();
		}
	}

	std::string FusionManager::printContext()
	{
		stringstream ss;
		ss << "Print frames begin";
		ss << "\n";

		for(std::vector<MeaningFrame>::iterator it = contextFrames.begin(); it != contextFrames.end(); ++it) 
		{
			ss << (*it).print() << "\n";
		}

		ss << "Print frames end";
		ss << "\n";
		return ss.str();
	}

}
