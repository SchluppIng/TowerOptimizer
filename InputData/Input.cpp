#include <string>
#include <iostream>
#include "Input.h"

InputData::InputData(const InputGeometry& InputGeom, const InputLoads& InputLoads, const InputCalcFactors& CalculationFactors) : 
    inputGeometry{InputGeom}, 
    inputLoads{InputLoads},
    calcFactors{CalculationFactors}
{
}

InputData::InputData(const InputData& ipD) :
    InputData(ipD.inputGeometry, ipD.inputLoads, ipD.calcFactors)
{    
}

void InputData::ToString()
{
    //Just for stupid testing
    std::cout << "Tower has door? " << std::boolalpha << this->inputGeometry.getDoor() << std::endl;
}

