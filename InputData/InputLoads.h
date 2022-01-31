#ifndef INPUTLOADS_H
#define INPUTLOADS_H

class InputLoads
{
public:
    InputLoads(const double& maxWeight, const double& maxSectionWeight, const double& topMass, const double& bottomMxy, const double& bottomMz, 
        const double& bottomFz, const double& bottomFres);
private:
    double MaxWeight;
    double MaxSectionWeight;
    double TopMass;
    
    double BottomMxy;
    double BottomMz;
    double BottomFz;
    double BottomFres;
};
#endif