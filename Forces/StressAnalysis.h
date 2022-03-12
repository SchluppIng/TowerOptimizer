#ifndef STRESSANALYSIS_H
#define STRESSANALYSIS_H
#include <string>

class StressAnalysis
{
public:
    StressAnalysis(const double& _diameter, const double& _area, const double& _shellThickness, const double& _normalForce, const double& _shearForceX, 
    const double& _shearForceY, const double& _bendingMomentXX, const double& _bendingMomentYY, const double& _bendingMomentZZ, const double _resistanceMoment );
    StressAnalysis(const StressAnalysis& stress);
    
    ~StressAnalysis(){}

    void calcSheetArea();
    void calcShearForce();
    void calcMoment();
    void calcSigmaZ();
    void calcSigmaV();
    void calcTau();
    void calcUtilisation();
    void calcResidualSafety();

private:
    double diameter;            //m
    double area;                //m²
    double sheetArea;           //m²
    double sheetThickness;      //m
    double normalForce;         //MN
    double shearForceX;         //MN
    double shearForceY;         //MN
    double shearForce;          //MN
    double bendingMomentYY;     //MNm
    double bendingMomentXX;     //MNm
    double bendingMomentZZ;     //MNm
    double bendingMoment;       //MNm
    double resistanceMomment;   //m^4
    

    std::string loadCase;
    double sigmaZ;
    double sigmaV;
    double tauShear;
    double tauTorsion;
    double tau;
    double safetyFactor;
    double utilisation;
    double residualSafety;
    double yieldStrength;
};

#endif