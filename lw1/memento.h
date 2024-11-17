#pragma once
#include "drawDecorator.h"

class Memento
{
public:
	Memento(const std::vector<std::shared_ptr<DrawDecorator>>& state);
	std::vector<std::shared_ptr<DrawDecorator>> GetState() const;

private:
	std::vector<std::shared_ptr<DrawDecorator>> m_state;
};