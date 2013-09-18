//#include "stdafx.h"
#include "FrameResult.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	FrameResult::FrameResult()
	{
		tokens = "";
	}

	FrameResult::FrameResult(std::string resultTokens)
	{
		tokens = resultTokens;
	}

	FrameResult::~FrameResult()
	{

	}

	void FrameResult::setTokens(std::string resultTokens)
	{
		tokens = resultTokens;
	}

	std::string FrameResult::getTokens()
	{
		return tokens;
	}

	std::string FrameResult::print()
	{
		stringstream ss;

		ss << "Result || Tokens=" << tokens << "\n";

		return ss.str();
	}

}
