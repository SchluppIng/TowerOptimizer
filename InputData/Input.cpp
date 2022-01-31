#include <string>
#include <iostream>
#include "Input.h"

InputData::InputData()
{
}

InputData::InputData(InputGeometry* InputGeom, InputLoads* InputLoads) : inputGeometry{InputGeom}, inputLoads{InputLoads}
{
}

void InputData::ToString()
{
    std::cout << "ToString Func von InputData" << std::endl;
}

