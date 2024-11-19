#include "saveToFileCommand.h"

SaveToFileCommand::SaveToFileCommand(const std::string& outputFileName)
{
	m_outputFileName = outputFileName;
};

void SaveToFileCommand::Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	SaveContext context;
	SaveToTextStrategy strategy;
	context.SetStrategy(std::make_shared<SaveToTextStrategy>(strategy));
	context.ExecuteStrategy(m_outputFileName, shapes);
};