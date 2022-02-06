#ifndef INPUTCALCFACTORS_H
#define INPUTCALCFACTORS_H

class InputCalcFactors
{
public:
    //Has to be adjust. Factors are maybe not correct here
    InputCalcFactors(const double& TowerTilt, const double& RotStiffness, const double& TransStiffness,
        const double& SaftTowerWallULS = 1.1, const double& SaftBuck = 1.1, const double& SaftFlange = 1.1, const double& SaftTowerWallFLS = 1.15, 
        const double& SaftBoltFLS = 1.15, const double& SaftBoltPretension = 1.0, const char& QualityClass  = 'B', const bool& DucCheck  = true);
    InputCalcFactors(const InputCalcFactors& ipC);
    ~InputCalcFactors(){}

    double getTowerTilt() {return towerTilt;}
    double getRotationalStiffness() {return rotationalStiffness;}
    double getTranslationalStiffness() {return translationalStiffness;}
    double getSafeTyTowerWallULS() {return safteyTowerWallULS;}
    double getSafteyBuckling() {return safteyBuckling;}
    double getSafteyFlangeULS() {return safteyFlangeULS;}
    double getSafteyTowerWallFLS() {return safteyTowerWallFLS;}
    double getSafteyBoltFLS() {return safteyBoltFLS;}
    double getSafteyBoltPretension() {return safteyBoltPretension;}
    char getQualityClass() { return qualityClass;}
    bool getDuctilityCheck() { return ductilityCheck;}

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