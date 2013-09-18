//EmmaInterpretation.h

#pragma once

#include <string>
#include <sstream>

namespace MultimodalFusion
{

class EmmaInterpretation
{
		
public:
	EmmaInterpretation();
	EmmaInterpretation(std::string interpretationId);
	~EmmaInterpretation();

	void setId(std::string interpretationId);
	void setMedium(std::string interpretationMedium);
	void setMode(std::string interpretationMode);
	void setLiteral(std::string interpretationLiteral);

	std::string getId();
	std::string getMedium();
	std::string getMode();
	std::string getLiteral();

private:
	std::string id;
	std::string medium;
	std::string mode;
	std::string literal;
};
}