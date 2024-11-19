#pragma once
#include "saveStrategy.h"

class SaveContext
{
public:
	void SetStrategy(std::shared_ptr<SaveStrategy> saveStrategy);
	void ExecuteStrategy(const std::string& fileName, const std::vector<std::shared_ptr<DrawDecorator>>& shapes);

private:
	std::shared_ptr<SaveStrategy> m_saveStrategy;
};