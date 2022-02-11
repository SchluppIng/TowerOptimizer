#ifndef TOWERSECTION_H
#define TOWERSECTION_H
#include <vector>
#include "TowerSheet.h"

class TowerSection
{
public:
    TowerSection(const std::vector<TowerSheet>& towerSheets, const bool& hasDoor);
    //TowerSection(const std::vector<TowerSheet>& towerSheets, const Flange& flangeBottom, const Flange& flangeTop, const bool& hasDoor);
    TowerSection(const TowerSection& ts);

    ~TowerSection(){}
    
private:
    void calcSectionLength();
    void calcSectionWeight();
    void calcDiameter();
    void calcSheets();

    std::vector<TowerSheet> sectionSheets;
    //Flange bottomFlange;
    //Flange topFlange;
    bool sectionHasDoor{false};


    double sectionLength{0};
    double bottomDiameterSection{0.0};
    double topDiameterSection{0.0};
    double sectionWeight{0.0};
    int numberOfSheets{0};
};

#endif