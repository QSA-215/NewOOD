#pragma once
#include "memento.h"
//#include "application.h"

class Caretaker
{
public:
	//Caretaker(std::shared_ptr<Application> application);
	void Save(const std::shared_ptr<Memento>& state);
	bool CanUndo() const;
	std::shared_ptr<Memento> Undo();

private:
	std::vector<std::shared_ptr<Memento>> m_history;
	//std::shared_ptr<Application> m_application;
};