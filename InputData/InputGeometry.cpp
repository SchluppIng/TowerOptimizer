#include "InputGeometry.h"

InputGeometry::InputGeometry(const double& TowerLength, const double& SectionLength, const double& SheetLength, const double& minODiameter, 
const double& maxODiameter, const double& minIDiameter, const double& maxIDiameter, const bool& Door) : 
    towerLength{TowerLength},
    sectionLength{SectionLength},
    sheetLength{SheetLength},
    minOuterDiameter{minODiameter},
    maxOuterDiameter{maxODiameter},
    minInnerDiameter{minIDiameter},
    maxInnerDiameter{maxIDiameter},
    door{Door}
    {
    }

InputGeometry::InputGeometry(const InputGeometry& ipG) :
    InputGeometry(ipG.towerLength,
    ipG.sectionLength,
    ipG.sheetLength,
    ipG.minOuterDiameter,
    ipG.maxOuterDiameter,
    ipG.minInnerDiameter,
    ipG.maxInnerDiameter,
    ipG.door)
{}
