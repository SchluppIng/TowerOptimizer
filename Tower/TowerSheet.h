#ifndef TOWERSHEET_H
#define TOWERSHEET_H

#include <string>
#include "../PhysicalValues/YieldStrength.h"

class TowerSheet
{
public:
    TowerSheet(){}
    TowerSheet(const double& diaBottomOut, const double& diaTopOut, const double& sheetLen, const double& thickness, const std::string& SteelGrade);
    TowerSheet(const TowerSheet& ts);
    ~TowerSheet(){}

#pragma region Getter
    //Getter
    double getDiameterBottomOut()const { return diameterBottomOut; }
    double getDiameterBottomIn()const {return diameterBottomIn;}
    double getDiameterTopOut()const {return diameterTopOut;}
    double getDiameterTopIn()const {return diameterTopIn;}
    double getSheetLength()const {return sheetLength;}
    double getSheetHeight()const {return sheetHeight;}
    double getSheetThickness()const {return sheetThickness;}
    double getBottomArea()const {return bottomArea;}
    double getTopArea()const {return topArea;}
    double getIyBottom()const {return iyBottom;}
    double getIyTop()const {return iyTop;}
    double getWyBottom()const {return wyBottom;}
    double getWyTop()const {return wyTop;}
    double getSheetWeight() const{return sheetWeight;}
    std::string getSteelGrade() const {return steelGrade;}
    double getYieldStrength() const{ return yieldStrength; }
#pragma endregion

#pragma region Setter and recalculations of values
    //Setter with automatic calculation
    void setDiameterBottomOut(const double& diaBottomOut) 
    { 
        diameterBottomOut = diaBottomOut;
        diameterBottomIn = calcTowerSheetInnerDiameter(diaBottomOut, sheetThickness);
        bottomArea = calcTowerSheetArea(diameterBottomOut, diameterBottomIn);
        iyBottom = calcIy(diameterBottomOut, diameterBottomIn);
        wyBottom = calcWy(diameterBottomOut, iyBottom);
        calcSheetWeight();
    }
    void setDiameterTopOut(const double& diaTopOut) 
    { 
        diameterTopOut = diaTopOut;
        diameterTopIn = calcTowerSheetInnerDiameter(diaTopOut, sheetThickness);
        topArea = calcTowerSheetArea(diameterTopOut, diameterTopIn);
        iyTop = calcIy(diameterTopOut, diameterTopIn);
        wyTop = calcWy(diameterTopOut, iyTop);
        calcSheetWeight();
    }

    void setSheetThickness(const double& thickness)
    {
        sheetThickness = thickness;
        diameterBottomIn = calcTowerSheetInnerDiameter(diameterBottomOut, sheetThickness);
        diameterTopIn = calcTowerSheetInnerDiameter(diameterTopOut, sheetThickness);
        bottomArea = calcTowerSheetArea(diameterBottomOut, diameterBottomIn);
        topArea = calcTowerSheetArea(diameterTopOut, diameterTopIn);
        iyBottom = calcIy(diameterBottomOut, diameterBottomIn);
        wyBottom = calcWy(diameterBottomOut, iyBottom);
        iyTop = calcIy(diameterTopOut, diameterTopIn);
        wyTop = calcWy(diameterTopOut, iyTop);
        calcSheetWeight();
        yieldStrength = CalcYieldStrength().getYieldStrengthForPlateThickness(steelGrade, sheetThickness);
    }

    void setSheetLength(const double& sheetLen)
    {
        sheetLength = sheetLen;
        sheetHeight = calcTowerSheetHeight(diameterBottomOut, diameterTopOut, sheetLength);
        calcSheetWeight();
    }

#pragma endregion

private:
    double calcTowerSheetHeight(const double& diaBottomOut, const double& diaTopOut, const double& sheetLength);
    double calcTowerSheetInnerDiameter(const double& diaOut, const double& thickness);
    double calcTowerSheetArea(const double& diaOut, const double& diaIn);
    double calcIy(const double& diaOut, const double& diaIn);
    double calcWy(const double& diaOut, const double& iy);
    void calcSheetWeight();

    //Attributes from handover
    double diameterBottomOut;
    double diameterTopOut;
    double sheetLength;
    double sheetThickness;

    //Calculated attributes
    double diameterBottomIn;
    double diameterTopIn;
    double sheetHeight;
    double bottomArea;
    double topArea;
    double iyBottom;
    double iyTop;
    double wyBottom;
    double wyTop;
    double sheetWeight;
    double yieldStrength;
    std::string steelGrade;
};
#endif