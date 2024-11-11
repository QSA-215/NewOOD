#pragma once
#include "mathDecorators.h"
#include "drawDecorators.h"

std::vector<double> ParseParameters(const std::string& command);
std::shared_ptr<Circle> ParseCircle(const std::vector<double>& parameters);
std::shared_ptr<Rectangle> ParseRectangle(const std::vector<double>& parameters);
std::shared_ptr<Triangle> ParseTriangle(const std::vector<double>& parameters);
void ParseCommand(const std::string& command, std::vector<std::shared_ptr<MathDecorator>>& mathShapes, std::vector<std::shared_ptr<DrawDecorator>>& drawShapes);