#include <cmath>
#include "TowerSheet.h"
#include "../PhysicalValues/PhysicalValues.h"


TowerSheet::TowerSheet(const double& diaBottomOut, const double& diaTopOut, const double& sheetLen, const double& thickness, const std::string& SteelGrade) :
    diameterBottomOut{diaBottomOut},
    diameterTopOut{diaTopOut},
    sheetLength{sheetLen},
    sheetThickness{thickness},
    steelGrade{SteelGrade}
{
    sheetHeight = calcTowerSheetHeight(diaBottomOut, diameterTopOut, sheetLength);
    diameterBottomIn = calcTowerSheetInnerDiameter(diameterBottomOut, thickness);
    diameterTopIn = calcTowerSheetInnerDiameter(diameterTopOut, thickness);
    bottomArea = calcTowerSheetArea(diameterBottomOut, diameterBottomIn);
    topArea = calcTowerSheetArea(diameterTopOut, diameterTopIn);
    iyBottom = calcIy(diameterBottomOut, diameterBottomIn);
    iyTop = calcIy(diameterTopOut, diameterTopIn);
    wyBottom = calcWy(diameterBottomOut, iyBottom);
    wyTop = calcWy(diameterTopOut, iyTop);
    yieldStrength = CalcYieldStrength().getYieldStrengthForPlateThickness(steelGrade, sheetThickness);
    calcSheetWeight();
}

TowerSheet::TowerSheet(const TowerSheet& ts) :
    TowerSheet(ts.diameterBottomOut, ts.diameterTopOut, ts.sheetLength, ts.sheetThickness, ts.steelGrade)
{
}

double TowerSheet::calcTowerSheetInnerDiameter(const double& diaOut, const double& thickness)
{
    return diaOut - 2.0 * thickness;
}


double TowerSheet::calcTowerSheetHeight(const double& diaBottom, const double& diaTop, const double& sheetLength)
{
    //Hight of the sheet including inclination
    double radiusBottom = diaBottom / 2.0;
    double radiusTop = diaTop / 2.0;
    return sqrt(pow(sheetLength, 2) - pow((radiusBottom - radiusTop), 2));
}

double TowerSheet::calcTowerSheetArea(const double& diaOut, const double& diaIn)
{
    double radiusOut = diaOut / 2.0;
    double radiusIn = diaIn / 2.0;
    return M_PI* (pow(radiusOut, 2) - pow(radiusIn, 2));
}

double TowerSheet::calcIy(const double& diaOut, const double& diaIn)
{
    double radiusOut = diaOut / 2.0;
    double radiusIn = diaIn / 2.0;
    return M_PI / 4.0 * (pow(radiusOut, 4) - pow(radiusIn, 4));
}

double TowerSheet::calcWy(const double& diaOut, const double& iy)
{
    double radiusOut = diaOut / 2.0;
    return iy / radiusOut;
}

void TowerSheet::calcSheetWeight()
{
    double radiusTopOut = diameterTopOut / 2.0;
    double radiusBttomOut = diameterBottomOut / 2.0;
    double radiusTopIn = diameterTopIn / 2.0;
    double radiusBottomIn = diameterBottomIn / 2.0;

    double outerVolume = (sheetHeight * M_PI) / 3 * ( pow(radiusBttomOut, 2) + radiusBttomOut * radiusTopOut + pow(radiusTopOut, 2)); //m³
    double innerVolume = (sheetHeight * M_PI) / 3 * ( pow(radiusBottomIn, 2)+ radiusBottomIn * radiusTopIn + pow(radiusTopIn, 2)); //m³
    sheetWeight = (outerVolume - innerVolume) * steelWeigth;
}