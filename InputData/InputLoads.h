#ifndef INPUTLOADS_H
#define INPUTLOADS_H

class InputLoads
{
public:
    InputLoads(const double& maxWeight, const double& maxSectionWeight, const double& topMass, 
        const double& bottomFz, const double& bottomFres, const double& bottomMz, const double& bottomMxy,
        const double& topFz, const double& topFres, const double& topMz, const double& topMxy);
    InputLoads(const InputLoads& ipL);
    ~InputLoads(){}

    //Getter
    double getMaxWeight() const { return MaxWeight;}
    double getMaxSectionWeight() const { return MaxSectionWeight;}
    double getTopMass() const { return TopMass;}
    double getBottomFz() const { return BottomFz;}
    double getBottomFres() const { return BottomFres;}
    double getBottomMz() const { return BottomMz;}
    double getBottomMxy() const { return BottomMxy;}
    double getTopFz() const { return TopFz;}
    double getTopFres() const { return TopFres;}
    double getTopMz() const { return TopMz;}
    double getTopMxy() const { return TopMxy;}   

private:
    double MaxWeight;
    double MaxSectionWeight;
    double TopMass;
    
    double BottomFz;
    double BottomFres;
    double BottomMz;
    double BottomMxy;
    
    double TopFz;
    double TopFres;    
    double TopMz;
    double TopMxy;   
    
};
#endif