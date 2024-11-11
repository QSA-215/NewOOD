#include "application.h"
#include "toolbar.h"

std::shared_ptr<Application> Application::m_instance = nullptr;

Application::Application()
	:
	//m_windowSettings.antialiasingLevel(8),
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Default)//, m_windowSettings)
{
};

void Application::Load(const std::string& INPUT_FILE_NAME, const std::string& OUTPUT_FILE_NAME)
{
	ReadShapesFromFile(INPUT_FILE_NAME, m_mathShapes, m_drawShapes);
	WriteResultsInFile(OUTPUT_FILE_NAME, m_mathShapes);
};

void Application::Run()
{
	Toolbar toolbar;
	toolbar.LoadButtons();
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::White);
		ListenEvents(m_window, m_drawShapes, m_isMove, toolbar);
		toolbar.Draw(m_window);
		DrawShapes(m_window, m_drawShapes);
		m_window.display();
	}
};

std::shared_ptr<Application> Application::GetInstance()
{
	if (!m_instance)
		m_instance = std::shared_ptr<Application>(new Application());
	return m_instance;
};