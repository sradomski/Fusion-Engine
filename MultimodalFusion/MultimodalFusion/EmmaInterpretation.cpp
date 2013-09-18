//#include "stdafx.h"
#include "EmmaInterpretation.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	EmmaInterpretation::EmmaInterpretation()
	{
		id = "none";
	}

	EmmaInterpretation::EmmaInterpretation(std::string interpretationId)
	{
		id = interpretationId;

		medium = "";
		mode = "";
		literal = "";
	}

	EmmaInterpretation::~EmmaInterpretation()
	{

	}

	void EmmaInterpretation::setId(std::string interpretationId)
	{
		id = interpretationId;
	}

	void EmmaInterpretation::setMedium(std::string interpretationMedium)
	{
		medium = interpretationMedium;
	}

	void EmmaInterpretation::setMode(std::string interpretationMode)
	{
		mode = interpretationMode;
	}

	void EmmaInterpretation::setLiteral(std::string interpretationLiteral)
	{
		literal = interpretationLiteral;
	}

	std::string EmmaInterpretation::getId()
	{
		return id;
	}

	std::string EmmaInterpretation::getMedium()
	{
		return medium;
	}

	std::string EmmaInterpretation::getMode()
	{
		return mode;
	}

	std::string EmmaInterpretation::getLiteral()
	{
		return literal;
	}
}
