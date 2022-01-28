#ifndef INPUTGEOMETRY_H
#define INPUTGEOMETRY_H

class InputGeometry
{
public:
    InputGeometry(const double& TowerLength, const double& SectionLength, const double& SheetLength, const double& minODiameter, 
                const double& maxODiameter, const double& minIDiameter, const double& maxIDiameter, const bool& Door);
    InputGeometry(const InputGeometry&);

    ~InputGeometry();

    double getTowerLength(){ return towerLength;}
    double getSectionLength() { return sectionLength; }
    double getSheetLength() { return sheetLength; }
    double getMinOuterDiameter() { return minOuterDiameter; }
    double getMaxOuterDiameter() { return maxOuterDiameter; }
    double getMinInnerDiameter() { return minInnerDiameter; }
    double getMaxInnerDiameter() { return maxInnerDiameter; }
    bool getDoot() {return door; } 
    
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