#pragma once
#include "drawDecorator.h"
#include <fstream>

class SaveStrategy
{
public:
	virtual void SaveToFile(const std::string& fileName, const std::vector<std::shared_ptr<DrawDecorator>>& shapes) = 0;
	virtual ~SaveStrategy() = default;

};