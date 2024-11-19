#pragma once
#include "command.h"
#include "saveToTextStrategy.h"
#include "saveContext.h"

class SaveToFileCommand : public Command
{
public:
	SaveToFileCommand(const std::string& outputFileName);
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;

private:
	std::string m_outputFileName;
};