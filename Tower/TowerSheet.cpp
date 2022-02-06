#include <cmath>
#include "TowerSheet.h"


TowerSheet::TowerSheet(const double& diaBottomOut, const double& diaTopOut, const double& sheetLen, const double& thickness) :
    diameterBottomOut{diaBottomOut},
    diameterTopOut{diaTopOut},
    sheetLength{sheetLen},
    sheetThickness{thickness}
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
}

TowerSheet::TowerSheet(const TowerSheet& ts) :
    TowerSheet(ts.diameterBottomOut, ts.diameterTopOut, ts.sheetLength, ts.sheetThickness)
{
}

double TowerSheet::calcTowerSheetInnerDiameter(const double& diaOut, const double& thickness)
{
    return diaOut - 2.0 * thickness;
}


double TowerSheet::calcTowerSheetHeight(const double& diaBottom, const double& diaTop, const double& sheetLength)
{
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