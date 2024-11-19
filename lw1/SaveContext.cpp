#include "saveContext.h"

void SaveContext::SetStrategy(std::shared_ptr<SaveStrategy> saveStrategy)
{
	m_saveStrategy = saveStrategy;
};

void SaveContext::ExecuteStrategy(const std::string& fileName, const std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	m_saveStrategy->SaveToFile(fileName, shapes);
};