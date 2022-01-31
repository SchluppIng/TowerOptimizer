#ifndef INPUTCALCFACTORS_H
#define INPUTCALCFACTORS_H

class InputCalcFactors
{
public:
    //Has to be adjust. Factors are maybe not correct here
    InputCalcFactors(const double& TowerTilt, const double& RotStiffness, const double& TransStiffness,
        const double& SaftTowerWallULS = 1.1, const double& SaftBuck = 1.1, const double& SaftFlange = 1.1, const double& SaftTowerWallFLS = 1.15, 
        const double& SaftBoltFLS = 1.15, const double& SaftBoltPretension = 1.0, const char& QualityClass  = 'B', const bool& DucCheck  = true);
private:
    double towerTilt;
    double rotationalStiffness;
    double translationalStiffness;

    double safteyTowerWallULS;
    double safteyBuckling;
    double safteyFlangeULS;
    double safteyTowerWallFLS;
    double safteyBoltFLS;
    double safteyBoltPretension;

    char qualityClass;
    bool ductilityCheck;
};
#endif