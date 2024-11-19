#include "memento.h"

Memento::Memento(const std::vector<std::shared_ptr<DrawDecorator>>& state)
{
	//m_state = state;
	for (const auto& shape : state) {
		m_state.push_back(shape->Clone());
	}
};

std::vector<std::shared_ptr<DrawDecorator>> Memento::GetState() const
{
	return m_state;
};