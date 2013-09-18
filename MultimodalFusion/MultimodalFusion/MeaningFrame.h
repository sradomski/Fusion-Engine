//MeaningFrame.h

#pragma once

#ifndef MEANINGFRAME_Included
#define	MEANINGFRAME_Included
#include <string>
#include <sstream>
#include <vector>

#include "FrameTrigger.h"
#include "FrameResult.h"


namespace MultimodalFusion
{

class MeaningFrame
{
		
public:
	MeaningFrame();
	MeaningFrame(std::string frameMode, std::vector<FrameTrigger> frameTriggers, std::vector<FrameResult> frameResults);
	~MeaningFrame();

	void processInput(InputEvent inputReceived);

	bool isValid(); //returns the value of variable activated which indicates if a frame fulfills all triggers requirements

	void addTrigger(FrameTrigger trigger);
	void addResult(FrameResult result);

	void setMode(std::string frameMode);

	std::vector<FrameResult> getResults();

	std::string getResultsAsEmmaInterpretations();

	int getNumberOfTriggers();
	int getNumberOfResults();

	void reset();

	std::string print(); //prints the content of the frame (triggers + results) for debugging purposes

private:

	std::string mode;		//Frame synchronicity mode. Possibe values: par_and, par_or, seq_and, seq_or
	double leadtime;	//Time window used to check synchronicity between frame triggers (for now 1500 is default value, but make it customizable later)

	bool activated;

	bool validate(); //After input is process with processInput() the frame is checked for activation (i.e. check if triggers rules are respected and if so sets activated=true)

	std::vector<FrameTrigger> triggers; //Frame conditions that must be met (according to frame mode) in order for the frame to be activated (valid)
	std::vector<FrameResult> results;	//Frame results that are delivered when frame is activated

};
}
#endif