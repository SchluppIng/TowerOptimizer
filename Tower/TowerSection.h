#ifndef TOWERSECTION_H
#define TOWERSECTION_H
#include <vector>
#include "TowerSheet.h"

class TowerSection
{
public:
    TowerSection(const std::vector<TowerSheet>& vecTowerSheets, const bool& hasDoor, const int& sectionNum);
    //TowerSection(const std::vector<TowerSheet>& towerSheets, const Flange& flangeBottom, const Flange& flangeTop, const bool& hasDoor);
    TowerSection(const TowerSection& ts);

    ~TowerSection(){}
    
    int getNumberOfSheets() const { return numberOfSheets;}
    int getNumberOfSection() const {return sectionNumber;}
    double getBottomDiameter() const {return bottomDiameterSection;}
    double getTopDiameter()const {return topDiameterSection;}
    double getSectionWeight()const {return sectionWeight;}
    double getSectionLength() const {return sectionLength;}

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
    int sectionNumber{0};
};

#endif