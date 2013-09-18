//#include "stdafx.h"
#include "MeaningFrame.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	MeaningFrame::MeaningFrame()
	{
		mode = "par_and";
		activated = false;
	}

	MeaningFrame::MeaningFrame(std::string frameMode, vector<FrameTrigger> frameTriggers, vector<FrameResult> frameResults)
	{
		mode = frameMode;
		triggers = frameTriggers;
		results = frameResults;

		leadtime = 1500;
		activated = false;
	}

	MeaningFrame::~MeaningFrame()
	{
		
	}

	void MeaningFrame::setMode(std::string frameMode)
	{
		mode = frameMode;
	}

	void MeaningFrame::addTrigger(FrameTrigger trigger)
	{
		triggers.push_back(trigger);
	}

	void MeaningFrame::addResult(FrameResult result)
	{
		results.push_back(result);
	}

	bool MeaningFrame::isValid()
	{
		return activated;
	}

	void MeaningFrame::processInput(InputEvent inputReceived)
	{
		for(std::vector<FrameTrigger>::iterator it = triggers.begin(); it != triggers.end(); ++it) 
		{
			(*it).processInput(inputReceived);
		}

		validate();
	}

	bool MeaningFrame::validate()
	{
		bool result = true;

		if(mode == "par_and") //All triggers must be valid and activated in the same time window (time constraints still not implemented)
		{
			//Check all triggers, if one is not valid then frame cannot be validated
			std::vector<FrameTrigger>::iterator it = triggers.begin();
			
			while(it != triggers.end() && result)
			{
				if(!(*it).isValid())
					result = false;

				++it;
			}
		}
		else if(mode == "par_or")
		{

		}
		else if(mode == "seq_and")
		{

		}
		else if(mode == "seq_or")
		{

		}

		activated = result;
		return activated;
	}

	int MeaningFrame::getNumberOfTriggers()
	{
		return triggers.size();
	}

	int MeaningFrame::getNumberOfResults()
	{
		return results.size();
	}

	void MeaningFrame::reset()
	{
		activated = false;

		for(std::vector<FrameTrigger>::iterator it = triggers.begin(); it != triggers.end(); ++it) 
		{
			(*it).reset();
		}
	}

	std::string MeaningFrame::print()
	{
		stringstream ss;
		ss << "Frame || " << "Mode=" << mode << " || No. of triggers=" << triggers.size() << " || No. of results=" << results.size() << "\n";

		for(std::vector<FrameTrigger>::iterator it = triggers.begin(); it != triggers.end(); ++it) 
		{
			ss << (*it).print() << "\n";
		}

		for(std::vector<FrameResult>::iterator it = results.begin(); it != results.end(); ++it) 
		{
			ss << (*it).print() << "\n";
		}

		return ss.str();
	}

	vector<FrameResult> MeaningFrame::getResults()
	{
		return results;
	}

	std::string MeaningFrame::getResultsAsEmmaInterpretations()
	{
		stringstream ss;
		std::string interpretationId = "interpId";

		for(std::vector<FrameResult>::iterator it = results.begin(); it != results.end(); ++it) 
		{
			
			ss << "<emma:interpretation id=\"" << interpretationId << "\">";
			ss << "<emma:literal>" << (*it).getTokens() << "</emma:literal>";
			ss << "</emma:interpretation>";
		}

		return ss.str();
	}

}
