#include "undoCommand.h"

void UndoCommand::Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	auto app = Application::GetInstance();
	app->Undo();
};