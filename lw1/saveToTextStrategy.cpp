#include "saveToTextStrategy.h"

void SaveToTextStrategy::SaveToFile(const std::string& fileName, const std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        for (const auto& shape : shapes)
            outputFile << shape->GetInfo() << std::endl;
        outputFile.close();
    }
};