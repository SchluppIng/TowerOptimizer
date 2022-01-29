#include <string>
#include <iostream>
#include "Input.h"

InputData::InputData(const double MaxWeight) : maxWeight{MaxWeight}
{
}

InputData::InputData(InputGeometry* InputGeom, const double& MaxWeight) : inputGeometry{InputGeom}, maxWeight{MaxWeight}
{

}

void InputData::ToString()
{
    std::cout << std::to_string(maxWeight) << std::endl;
}

