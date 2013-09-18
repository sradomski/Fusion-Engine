//FrameResult.h

#pragma once

#include <string>
#include <sstream>

namespace MultimodalFusion
{

class FrameResult
{
		
public:
	FrameResult();
	FrameResult(std::string token);
	~FrameResult();

	void setTokens(std::string tokens);
	
	std::string getTokens();

	std::string print(); //prints the content of the frame result for debugging purposes

private:
	std::string tokens;
};
}