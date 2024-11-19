#pragma once
#include "saveStrategy.h"

class SaveToTextStrategy : public SaveStrategy
{
	void SaveToFile(const std::string& fileName, const std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;
};