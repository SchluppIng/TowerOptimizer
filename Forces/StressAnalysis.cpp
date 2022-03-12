#include "StressAnalysis.h"
#include <cmath>

StressAnalysis::StressAnalysis(const std::string DLC, const double& Diameter, const double& Area, const double& SheetThickness, const double& ResistanceMoment, 
const double& Fz, const double& Fres, const double& Mz, const double Mxy, const double& YieldStrength, const double& SafetyFactor) :
loadCase{DLC},
diameter{Diameter},
area{Area},
sheetThickness{SheetThickness},
resistanceMomment{ResistanceMoment},
normalForceZ{Fz},
normalForceRes{Fres},
bendingMomentZ{Mz},
bendingMomentXY{Mxy},
yieldStrength{YieldStrength},
safetyFactor{SafetyFactor}
{
    calcSheetArea();
    calcSigmaZ();
    calcTau();
    calcSigmaV();
    calcUtilisation();
    calcResidualSafety();
}

StressAnalysis::StressAnalysis(const StressAnalysis& stress) :
StressAnalysis(stress.loadCase ,stress.diameter, stress.area, stress.sheetThickness, stress.resistanceMomment, stress.normalForceZ,
 stress.normalForceRes, stress.bendingMomentZ, stress.bendingMomentXY, stress.yieldStrength, stress.safetyFactor) 
{}

void StressAnalysis::calcSheetArea()
{
    sheetArea = pow((diameter - sheetThickness)/ 2, 2) * M_PI;
}

void StressAnalysis::calcSigmaZ()
{
    sigmaZ = (abs(normalForceZ/ area) + abs(bendingMomentXY / resistanceMomment)); //N/mm²
}

void StressAnalysis::calcTau()
{
    tauShear = 2 * (normalForceRes) / area;
    tauTorsion = abs(bendingMomentZ) / (2*sheetArea*sheetThickness);
    tau = (tauShear + tauTorsion); //N/mm²
}

void StressAnalysis::calcSigmaV()
{
    sigmaV = sqrt(pow(sigmaZ, 2)) + 3 * sqrt(pow(tauTorsion, 2)); //N/mm²;
}

void StressAnalysis::calcUtilisation()
{
    yieldStrengthSaftey = yieldStrength / safetyFactor;
    utilisation = sigmaV / yieldStrengthSaftey;
}

void StressAnalysis::calcResidualSafety()
{
    residualSafety = 1/utilisation;
}