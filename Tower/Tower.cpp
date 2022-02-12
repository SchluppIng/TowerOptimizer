#include "Tower.h"

Tower::Tower(const std::vector<TowerSection>& vecTowerSections, const double& headMass) :
vecTowerSection{vecTowerSections},
topMass{headMass},
bottomDiameter{vecTowerSection.front().getBottomDiameter()},
topDiameter{vecTowerSection.back().getTopDiameter()},
numberOfSections{static_cast<int>(vecTowerSection.size())}
{
    calcTowerWeight();
}

Tower::Tower(const Tower& tower) :
Tower(tower.vecTowerSection, tower.topMass)
{}

void Tower::calcTowerWeight()
{
    for(TowerSection& ts : vecTowerSection)
    {
        towerWeight += ts.getSectionWeight();
    }
}