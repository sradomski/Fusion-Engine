//#include "stdafx.h"
#include "UimlParser.h"
#include <stdexcept>

using namespace std;

namespace MultimodalFusion
{
	UimlDoc UimlParser::parseUimlFromString(std::string uimlXml)
	{
		UimlDoc uimlDoc;

		pugi::xml_document doc;
		pugi::xml_parse_result result;
		
		result = doc.load(uimlXml.c_str());

		if(result)
		{
			cout << "Uiml xml parsing successful \n";
			
			//Getting the node with the structure elements (e.g. buttons) and their ids
			pugi::xml_node structure = doc.first_element_by_path("uiml/interface/structure");

			//Getting the node with the style properties for each element (e.g size, location)
			pugi::xml_node style = doc.first_element_by_path("uiml/interface/style");

			//Fetching different ui elements and their properties
			UimlParser::parseButtons(uimlDoc, structure, style);

			uimlDoc.validate();
		}
		else
			cout << "Uiml xml parsing not successful \n";

		return uimlDoc;
	}

	UimlDoc UimlParser::parseUimlFromFile(std::string uimlXmlFilePath)
	{
		UimlDoc uimlDoc;

		pugi::xml_document doc;
		pugi::xml_parse_result result;
		
		result = doc.load_file(uimlXmlFilePath.c_str());

		if(result)
		{
			cout << "Uiml xml parsing successful \n";

			//Getting the node with the structure elements (e.g. buttons) and their ids
			pugi::xml_node structure = doc.first_element_by_path("uiml/interface/structure");

			//Getting the node with the style properties for each element (e.g size, location)
			pugi::xml_node style = doc.first_element_by_path("uiml/interface/style");
			
			//Fetching different ui elements and their properties
			UimlParser::parseButtons(uimlDoc, structure, style);

			uimlDoc.validate();
		}
		else
			cout << "Uiml xml parsing not successful \n";

		return uimlDoc;
	}

	void UimlParser::parseButtons(UimlDoc &uimlDoc, pugi::xml_node structure, pugi::xml_node style)
	{
		pugi::xpath_query query_buttons("//*[@class='button']");
		pugi::xpath_node_set buttons = query_buttons.evaluate_node_set(structure);
	
		std::string buttonId;

		for (unsigned int n=0; n<buttons.size(); n++)
		{
		
			pugi::xpath_node button = buttons[n];

			pugi::xpath_variable_set vars;
			vars.add("id", pugi::xpath_type_string);

			buttonId = button.node().attribute("id").value();

			vars.set("id", button.node().attribute("id").value());
			pugi::xpath_node button_position = style.select_single_node("//property[@part-name=string($id) and @name='position']", &vars);
			pugi::xpath_node button_width = style.select_single_node("//property[@part-name=string($id) and @name='width']", &vars);
			pugi::xpath_node button_height = style.select_single_node("//property[@part-name=string($id) and @name='height']", &vars);
			pugi::xpath_node button_text = style.select_single_node("//property[@part-name=string($id) and @name='text']", &vars);
			pugi::xpath_node button_label = style.select_single_node("//property[@part-name=string($id) and @name='label']", &vars);
			pugi::xpath_node button_description = style.select_single_node("//property[@part-name=string($id) and @name='description']", &vars);

			string buttonPosition = button_position.node().child_value();
			string buttonWidth = button_width.node().child_value();
			string buttonHeight = button_height.node().child_value();
			string buttonText = button_text.node().child_value();	
			string buttonLabel = button_label.node().child_value();
			string buttonDescription = button_description.node().child_value();

			double buttonX = Helper::getX(buttonPosition, ',');
			double buttonY = Helper::getY(buttonPosition, ',');
			double bWidth = atof(buttonWidth.c_str());
			double bHeight = atof(buttonHeight.c_str());

			UiElement element(buttonId, "button", buttonText, buttonLabel, buttonDescription, buttonX, buttonY, bWidth, bHeight);

			uimlDoc.addUiElement(element);
		}
	}

	
}
