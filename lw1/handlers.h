#pragma once
#include "parser.h"

void ReadShapesFromFile(const std::string& inputFileName, std::vector<std::shared_ptr<MathDecorator>>& mathShapes, std::vector<std::shared_ptr<DrawDecorator>>& drawShapes);
void WriteResultsInFile(const std::string& outputFileName, const std::vector<std::shared_ptr<MathDecorator>>& mathShapes);

void DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<DrawDecorator>>& shapes);
void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<DrawDecorator>>& shapes, bool& isMove);
void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<DrawDecorator>>& shapes, bool& isMove);