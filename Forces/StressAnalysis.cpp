#include "StressAnalysis.h"
#include <cmath>

StressAnalysis::StressAnalysis(const double& _diameter, const double& _area, const double& _shellThickness, const double& _normalForce, const double& _shearForceX, 
const double& _shearForceY, const double& _bendingMomentXX, const double& _bendingMomentYY, const double& _bendingMomentZZ, const double _resistanceMoment ) :
diameter{_diameter},
area{_area},
sheetThickness{_shellThickness},
normalForce{_normalForce},
shearForceX{_shearForceX},
shearForceY{_shearForceY},
bendingMomentXX{_bendingMomentXX},
bendingMomentYY{_bendingMomentYY},
bendingMomentZZ{_bendingMomentZZ},
resistanceMomment{_resistanceMoment}
{
    calcSheetArea();
    calcShearForce();
    calcMoment();
    calcSigmaZ();
    calcTau();
    calcSigmaV();
    calcUtilisation();
    calcResidualSafety();
}

StressAnalysis::StressAnalysis(const StressAnalysis& stress) :
StressAnalysis(stress.diameter, stress.area, stress.sheetThickness, stress.normalForce, stress.shearForceX, stress.shearForceY, stress.bendingMomentXX, 
stress.bendingMomentYY, stress.bendingMomentZZ, stress.resistanceMomment)
{}

void StressAnalysis::calcSheetArea()
{
    sheetArea = pow((diameter - sheetThickness)/ 2, 2) * M_PI;
}

void StressAnalysis::calcShearForce()
{
    shearForce = sqrt(pow(shearForceX, 2) + pow(shearForceY, 2));
}

void StressAnalysis::calcMoment()
{
    bendingMoment = sqrt(pow(bendingMomentYY, 2) + pow(bendingMomentZZ, 2));
}

void StressAnalysis::calcSigmaZ()
{
    sigmaZ = abs(normalForce / area) + abs(bendingMoment / resistanceMomment);
}

void StressAnalysis::calcTau()
{

    tauShear = 2 * shearForce / area;
    tauTorsion = abs(bendingMomentXX) / (2*sheetArea*sheetThickness);
    tau = tauShear + tauTorsion;
}

void StressAnalysis::calcSigmaV()
{
    sigmaV = sqrt(pow(sigmaZ, 2)) + 3 * sqrt(pow(tau, 2));
}

void StressAnalysis::calcUtilisation()
{
    utilisation = sigmaV / yieldStrength;
}

void StressAnalysis::calcResidualSafety()
{
    residualSafety = 1/utilisation;
}