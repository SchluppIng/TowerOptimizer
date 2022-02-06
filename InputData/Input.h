#ifndef INPUT_H
#define INPUT_H

#include "InputGeometry.h"
#include "InputLoads.h"
#include "InputCalcFactors.h"

class InputData
{
public:
    InputData();
    InputData(const InputGeometry& InputGeom, const InputLoads& InputLoads, const InputCalcFactors& CalculationFactors);
    InputData(const InputData& ipD);
    ~InputData(){}

    void ToString();

private:
    InputGeometry inputGeometry;
    InputLoads inputLoads;
    InputCalcFactors calcFactors;
};
#endif