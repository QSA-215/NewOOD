#include "application.h"
//#include "caretaker.h"
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";

int main()
{
	std::shared_ptr<Application> app = Application::GetInstance();
	//std::shared_ptr<Caretaker> caretaker = std::make_shared<Caretaker>(app);
	app->Load(INPUT_FILE_NAME, OUTPUT_FILE_NAME);
	app->Run();
}