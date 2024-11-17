#include "handlers.h"
#include <fstream>

void ReadShapesFromFile(const std::string& inputFileName, std::vector<std::shared_ptr<MathDecorator>>& mathShapes, std::vector<std::shared_ptr<DrawDecorator>>& drawShapes)
{
	std::ifstream input(inputFileName);
	std::string command;
	while (std::getline(input, command))
		ParseCommand(command, mathShapes, drawShapes);
	input.close();
};

void WriteResultsInFile(const std::string& outputFileName, const std::vector<std::shared_ptr<MathDecorator>>& mathShapes)
{
	std::ofstream output(outputFileName);
	for (auto shape : mathShapes)
		output << shape->GetParams() << std::endl;
	output.close();
};

void DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	for (auto shape : shapes)
		shape->Draw(window);
};

void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<DrawDecorator>>& shapes, bool& isMove, Caretaker& caretaker)
{
	static sf::Vector2i lastMousePosition;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!isMove)
		{
			isMove = true;
			lastMousePosition = sf::Mouse::getPosition(window);
		}
		sf::Vector2i currentPosition = sf::Mouse::getPosition(window);
		for (auto shape : shapes)
			if (shape->IsSelected())
				shape->Move(sf::Vector2f(currentPosition - lastMousePosition));
		lastMousePosition = currentPosition;
	}
	else
	{
		isMove = false;
	}
};

void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<DrawDecorator>>& shapes, bool& isMove, Toolbar& toolbar, Caretaker& caretaker)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			for (auto shape : shapes)
			{
				if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					shape->Select(true);
				}
				else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				{
					shape->Select(false);
				}
			}
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
			toolbar.ButtonClick(mousePosition, shapes, caretaker);
		}

		if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::G)
		{
			caretaker.Save(std::make_shared<Memento>(shapes));
			std::shared_ptr<DrawCompositeShapeDecorator> compositeShape = std::make_shared<DrawCompositeShapeDecorator>();
			std::vector<int> tempShapes;
			for (int i = 0; i < shapes.size(); i++)
			{
				if (shapes[i]->IsSelected())
				{
					compositeShape->AddShape(shapes[i]);
					tempShapes.push_back(i);
				}
			}
			for (int i = tempShapes.size(); i-- > 0; )
			{
				shapes[tempShapes[i]]->Select(false);
				shapes.erase(shapes.begin() + tempShapes[i]);
			}
			if (!compositeShape->IsEmpty())
			{
				compositeShape->MakeFrame();
				shapes.push_back(compositeShape);
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::U)
		{
			caretaker.Save(std::make_shared<Memento>(shapes));
			for (int i = 0; i < shapes.size(); i++)
			{
				if (shapes[i]->IsSelected() && shapes[i]->IsCompositeShape())
				{
					std::shared_ptr<DrawCompositeShapeDecorator> compositeShape = std::dynamic_pointer_cast<DrawCompositeShapeDecorator>(shapes[i]);
					if (!compositeShape->IsEmpty())
					{
						auto shapesFromGroup = compositeShape->GetShapes();
						shapes.push_back(shapesFromGroup.back());
						compositeShape->DeleteShape(shapesFromGroup.back());
						compositeShape->MakeFrame();
					}
					else
					{
						shapes.erase(shapes.begin() + i);
					}
				}
			}
		}
		ShapesMoving(window, shapes, isMove, caretaker);
	}
};