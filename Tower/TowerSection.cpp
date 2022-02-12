#include "TowerSection.h"

TowerSection::TowerSection(const std::vector<TowerSheet>& vecTowerSheets, const bool& hasDoor, const int& sectionNum) :
sectionSheets{vecTowerSheets},
sectionHasDoor{hasDoor},
numberOfSheets{ static_cast<int>(vecTowerSheets.size()) },
sectionNumber{sectionNum}
{
    calcSectionLength();
    calcSectionWeight();
    calcDiameter();
}

TowerSection::TowerSection(const TowerSection& ts) :
TowerSection(ts.sectionSheets, ts.sectionHasDoor, ts.sectionNumber)
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

