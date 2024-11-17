#include "memento.h"

Memento::Memento(const std::vector<std::shared_ptr<DrawDecorator>>& state)
{
	m_state = state;
};

std::vector<std::shared_ptr<DrawDecorator>> Memento::GetState() const
{
	return m_state;
};