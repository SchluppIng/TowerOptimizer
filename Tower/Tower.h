#ifndef TOWER_H
#define TOWER_H

#include "TowerSection.h"
#include "TowerSheet.h"
class Tower
{
public:
    Tower();
    Tower(const std::vector<TowerSection>& vecTowerSections, const double& headMass);
    Tower(const Tower& tower);

    ~Tower(){}

    double getHeadMass() const { return topMass;}
    void setHeadMass(const double& headMass) { topMass = headMass;}

    double getTowerBottomDiameter() const { return bottomDiameter;}
    double getTowerTopDiameter() const { return topDiameter; }
    int getNumberOfSections() const { return numberOfSections; }
    double getTowerWeight() const { return towerWeight; }
    std::vector<TowerSection> getTowerSections() { return vecTowerSection; }

private:

    void calcTowerWeight();

    std::vector<TowerSection> vecTowerSection;
    double topMass;
    double towerTilt;

    double bottomDiameter;
    double topDiameter;
    int numberOfSections;
    double towerWeight;
};

#endif