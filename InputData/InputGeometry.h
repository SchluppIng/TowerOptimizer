#ifndef INPUTGEOMETRY_H
#define INPUTGEOMETRY_H

#include "Input.h"

class InputGeometry
{
public:
    InputGeometry(){}
    InputGeometry(const double& TowerLength, const double& SectionLength, const double& SheetLength, const double& minODiameter, 
                const double& maxODiameter, const double& minIDiameter, const double& maxIDiameter, const bool& Door);
    //InputGeometry(const InputGeometry&);

    ~InputGeometry(){}

    //Getter
    double getTowerLength() const { return towerLength;}
    double getSectionLength() const { return sectionLength; }
    double getSheetLength() const { return sheetLength; }
    double getMinOuterDiameter() const { return minOuterDiameter; }
    double getMaxOuterDiameter() const { return maxOuterDiameter; }
    double getMinInnerDiameter() const { return minInnerDiameter; }
    double getMaxInnerDiameter() const { return maxInnerDiameter; }
    bool getDoot() const {return door; } 
    
private:
    double towerLength;
    double sectionLength;
    double sheetLength;

    double minOuterDiameter;
    double maxOuterDiameter;
    double minInnerDiameter;
    double maxInnerDiameter;

    bool door;
};
#endif