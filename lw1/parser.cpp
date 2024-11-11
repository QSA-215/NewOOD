#include "parser.h"

std::vector<double> ParseParameters(const std::string& command)
{
	std::vector<double> parameters;
	std::string temp = command.substr(command.find("=") + 1, command.find(";") - command.find("=") - 1);
	parameters.push_back(std::stof(temp.substr(0, temp.find(","))));
	parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	temp = command.substr(command.find(";") + 2);
	if (temp.find(",") == std::string::npos)
	{
		parameters.push_back(std::stof(temp.substr(2)));
	}
	else if (temp.find(";") == std::string::npos)
	{
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	}
	else
	{
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1)));
		temp = temp.substr(temp.find(";") + 2);
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	}
	return parameters;
};

std::shared_ptr<Circle> ParseCircle(const std::vector<double>& parameters)
{
	return std::make_shared<Circle>(Circle({ parameters[0], parameters[1] }, parameters[2]));
};

std::shared_ptr<Rectangle> ParseRectangle(const std::vector<double>& parameters)
{
	return std::make_shared<Rectangle>(Rectangle({ parameters[0], parameters[1] }, parameters[2] - parameters[0], parameters[3] - parameters[1]));
};

std::shared_ptr<Triangle> ParseTriangle(const std::vector<double>& parameters)
{
	return std::make_shared<Triangle>(Triangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] }));
};

void ParseCommand(const std::string& command, std::vector<std::shared_ptr<MathDecorator>>& mathShapes, std::vector<std::shared_ptr<DrawDecorator>>& drawShapes)
{
	std::string figureName = command.substr(0, command.find(" "));
	if (figureName == "CIRCLE:")
	{
		std::shared_ptr<Circle> circle = ParseCircle(ParseParameters(command));
		mathShapes.push_back(std::make_shared<MathCircleDecorator>(circle));
		drawShapes.push_back(std::make_shared<DrawCircleDecorator>(circle));
	}
	else if (figureName == "RECTANGLE:")
	{
		std::shared_ptr<Rectangle> rectangle = ParseRectangle(ParseParameters(command));
		mathShapes.push_back(std::make_shared<MathRectangleDecorator>(rectangle));
		drawShapes.push_back(std::make_shared<DrawRectangleDecorator>(rectangle));
	}
	else if (figureName == "TRIANGLE:")
	{
		std::shared_ptr<Triangle> triangle = ParseTriangle(ParseParameters(command));
		mathShapes.push_back(std::make_shared<MathTriangleDecorator>(triangle));
		drawShapes.push_back(std::make_shared<DrawTriangleDecorator>(triangle));
	}
};