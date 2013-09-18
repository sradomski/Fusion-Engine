//FusionManager.h

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "UimlDoc.h"
#include "SmuimlDoc.h"
#include "EmmaDoc.h"
#include "MeaningFrame.h"
#include "FrameTrigger.h"
#include "FrameResult.h"
#include "UiElement.h"

namespace MultimodalFusion
{

class FusionManager
{

public:
	//Methods
	FusionManager();
	~FusionManager();

	void createContext(UimlDoc uimlDoc);
	void createContext(SmuimlDoc smuimlDoc);

	std::string interpretInput(EmmaDoc input);				//Received emmadoc contains a single interpretation
	std::string interpretExclusiveInput(EmmaDoc input);		//Received emmadoc contains a one-of container with multiple interpretations
	std::string interpretSequentialInput(EmmaDoc input);	//Received emmadoc contains a sequence container with different interpretations

	std::string handleInvalidInput();						//Input could not be read due to wrong XML format or some other problem (ToDo: refine this part)

	void setFusionAlgorithm(int algorithmId);

	//Temporary functions to aid debug
	std::string printContext();

private:
	//Variables
	int fusionAlgorithm; //Id for the current algorithm being used to perform fusion of input (0 = frame based)
	std::vector<MeaningFrame> contextFrames;


	//Methods
	
	//Frame-based fusion
	void makeContextFrames(UimlDoc uimlDoc);		//Creates meaning frames, which will represent current knowledge about the current UI and possible inputs
	void addButtonFrames(UiElement button);			//Adds to the context frames related to a button


	void makeContextFrames(SmuimlDoc smuimlDoc);	//Creates meaning frames, which will represent current knowledge about the current UI and possible inputs

	void resetValidFrames();

	int getNumberOfValidFrameResults();
	
};

}