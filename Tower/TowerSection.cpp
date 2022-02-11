#include "TowerSection.h"


TowerSection::TowerSection(const std::vector<TowerSheet>& towerSheet, const bool& hasDoor) :
sectionSheets{towerSheet},
sectionHasDoor{hasDoor},
numberOfSheets{ static_cast<int>(towerSheet.size()) }
{
    calcSectionLength();
    calcSectionWeight();
    calcDiameter();
}

TowerSection::TowerSection(const TowerSection& ts) :
TowerSection(ts.sectionSheets, ts.sectionHasDoor)
{
}

void TowerSection::calcSectionLength()
{
    for(TowerSheet sheet : sectionSheets)
    {
        sectionLength += sheet.getSheetLength();
    }
}

void TowerSection::calcSectionWeight()
{
    for(TowerSheet sheet : sectionSheets)
    {
        sectionWeight += sheet.getSheetWeight();
    }
}

void TowerSection::calcDiameter()
{
    bottomDiameterSection = sectionSheets.front().getDiameterBottomOut();
    topDiameterSection = sectionSheets.back().getDiameterTopOut();
    
}

