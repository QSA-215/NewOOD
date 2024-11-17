#include "caretaker.h"

//Caretaker::Caretaker(std::shared_ptr<Application> application)
//{
//	m_application = application;
//};
//
//void Caretaker::Save(const std::shared_ptr<Memento>& state)
//{
//	m_history.push_back(m_application->Save());
//};
//
//void Caretaker::Undo()
//{
//	if (!m_history.empty())
//	{
//		std::shared_ptr<Memento> lastState = m_history.back();
//		m_history.pop_back();
//		m_application->Undo(lastState);
//	}
//};

void Caretaker::Save(const std::shared_ptr<Memento>& state)
{
	m_history.push_back(state);
};

bool Caretaker::CanUndo() const
{
	return !m_history.empty();
};

std::shared_ptr<Memento> Caretaker::Undo()
{
	if (!m_history.empty())
	{
		std::shared_ptr<Memento> lastState = m_history.back();
		m_history.pop_back();
		return lastState;
	}
};