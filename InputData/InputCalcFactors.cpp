#include "InputCalcFactors.h"

InputCalcFactors::InputCalcFactors(const double& TowerTilt, const double& RotStiffness, const double& TransStiffness,
    const double& SaftTowerWallULS, const double& SaftBuck , const double& SaftFlange , const double& SaftTowerWallFLS, 
    const double& SaftBoltFLS, const double& SaftBoltPretension, const char& QualityClass, const bool& DucCheck) :
    towerTilt{TowerTilt},
    rotationalStiffness{RotStiffness},
    translationalStiffness{TransStiffness},
    safteyTowerWallULS{SaftTowerWallULS},
    safteyBuckling{SaftBuck},
    safteyFlangeULS{SaftFlange},
    safteyTowerWallFLS{SaftTowerWallFLS},
    safteyBoltFLS{SaftBoltFLS},
    safteyBoltPretension{SaftBoltPretension},
    qualityClass{QualityClass},
    ductilityCheck{DucCheck}
    {

    }