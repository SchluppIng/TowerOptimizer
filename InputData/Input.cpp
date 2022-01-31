#include <string>
#include <iostream>
#include "Input.h"

InputData::InputData()
{
}

InputData::InputData(InputGeometry* InputGeom, InputLoads* InputLoads, InputCalcFactors* CalculationFactors) : 
    inputGeometry{InputGeom}, 
    inputLoads{InputLoads},
    calcFactors{CalculationFactors}
{
}

void InputData::ToString()
{
    //Just for stupid testing
    std::cout << "Tower has door? " << std::boolalpha << this->inputGeometry->getDoor() << std::endl;
}

