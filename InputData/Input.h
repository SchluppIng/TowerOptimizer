#ifndef INPUT_H
#define INPUT_H

#include "InputGeometry.h"
#include "InputLoads.h"

//Forward declaration
class InputGeometry;
class InputLoads;

class InputData
{
public:
    InputData();
    InputData(const double MaxWeight);
    InputData(InputGeometry* InputGeom, InputLoads* InputLoads );// const CalcFactors& CalculationFactors);

    void ToString();

private:
    InputGeometry* inputGeometry;
    InputLoads* inputLoads;
    //Loads inputLoads;
    //CalcFactors calculationFactors;
};
#endif