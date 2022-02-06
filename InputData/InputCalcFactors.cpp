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

InputCalcFactors::InputCalcFactors(const InputCalcFactors& ipC) :
    InputCalcFactors( ipC.towerTilt,
    ipC.rotationalStiffness,
    ipC.translationalStiffness,
    ipC.safteyTowerWallULS,
    ipC.safteyBuckling,
    ipC.safteyFlangeULS,
    ipC.safteyTowerWallFLS,
    ipC.safteyBoltFLS,
    ipC.safteyBoltPretension,
    ipC.qualityClass,
    ipC.ductilityCheck)
{
    
}