#ifndef INPUT_H
#define INPUT_H

#include "InputGeometry.h"

class InputData
{
public:
    InputData();
    InputData(double MaxWeight);
    InputData(const InputGeometry& InputGeom, const double& MaxWeight);//, const Loads& InputLoads, const CalcFactors& CalculationFactors);

    void setMaxWeight(const double& MaxWeight ) { maxWeight = MaxWeight; }
    void ToString();

private:
    InputGeometry inputGeometry;
    double maxWeight;
    //Loads inputLoads;
    //CalcFactors calculationFactors;
};
#endif