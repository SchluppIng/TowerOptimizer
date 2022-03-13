#ifndef STRESSANALYSIS_H
#define STRESSANALYSIS_H
#include <string>

class StressAnalysis
{
public:
    StressAnalysis(const std::string DLC, const double& Diameter, const double& Area, const double& SheetThickness, const double& ResistanceMoment, const double& Fz, const double& Fres, 
    const double& Mz, const double Mxy, const double& YieldStrength, const double& SafetyFactor);
    StressAnalysis(const StressAnalysis& stress);

    ~StressAnalysis(){}

    void calcSheetArea();
    void calcShearForce();
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
    double normalForceZ;        //MN
    double normalForceRes;      //MN
    double bendingMomentZ;      //MNm
    double bendingMomentXY;     //MNm
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
    double yieldStrengthSaftey;
};

#endif