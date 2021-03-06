#include <iostream>
#include <vector>
#include "InputData/Input.h"
#include "InputData/InputGeometry.h"
#include "InputData/InputLoads.h"
#include "InputData/InputCalcFactors.h"
#include "Tower/TowerSheet.h"
#include "Tower/TowerSection.h"
#include "Tower/Tower.h"
#include "Analysis/StressAnalysis.h"
#include "Analysis/Results.h"
#include "CalculationModul/TowerOptimizer.h"

#include <time.h>

using namespace std;

int main()
{
    double time1{0.0}, start;
    start = clock();
    //Test data for geometry
    double maxDia {6.0}; //m
    double minDia {3.0}; //m
    double towerLength{127.5}; //m
    double maxSectionLength{30.0}; //m
    double maxSheetLength{2.95}; //m
    bool hasDoor{true};
    //__________________________________________________________
    //Test data for loads from Senvion 4.2M140hh130m 
    double maxWeight{400}; //ton
    double maxSectionWeight{80}; //ton
    double topMass{235.0}; //ton
    
    //ULS Loads
    double bottomFz{-6957}; //kN    
    double bottomFres{1255}; //kN
    double bottomMz{15};  //kNm  
    double bottomMxy{166012}; //kNm

    double topFz{-3138}; //kN
    double topFres{243}; //kN
    double topMz{-3996};  //kNm
    double topMxy{16320}; //kNm
    //__________________________________________________________
    double towerTilt = 8.0; // mm/m 
    double rotStiff = 150000000.0; // kNm/m
    double transStiff = 240000; // kN/m
    //__________________________________________________________
    //TestData for tower sheet
    double bottomDia {4.4}; //m
    double topDia{4.4}; //m
    double thickness{0.034}; //m
    double sheetLen{maxSheetLength};
    //__________________________________________________________
    //Test Program
    InputGeometry ipGeomData(towerLength, maxSectionLength, maxSheetLength, minDia, maxDia, minDia, maxDia, hasDoor);
    InputLoads ipLoads(maxWeight, maxSectionWeight, topMass, bottomMxy, bottomMz, bottomFz, bottomFres, topMxy, topMz, topFz, topFres);
    InputCalcFactors ipCalcFacotrs(towerTilt, rotStiff, transStiff);
    InputData ipData(ipGeomData, ipLoads, ipCalcFacotrs);

    //Test TowerSheet
    TowerSheet ts0(4.4, 4.4, 0.195, 0.036, "S355");
    TowerSheet ts1(4.4, 4.4, 2.785, 0.034, "S355");
    TowerSheet ts2(4.4, 4.4, 2.950, 0.033, "S355");
    TowerSheet ts3(4.4, 4.4, 2.950, 0.031, "S355");
    TowerSheet ts4(4.4, 4.4, 2.950, 0.031, "S355");
    TowerSheet ts5(4.4, 4.4, 2.950, 0.029, "S355");
    TowerSheet ts6(4.4, 4.4, 2.950, 0.029, "S355");
    TowerSheet ts7(4.4, 4.3, 0.170, 0.029, "S355");
    vector<TowerSheet> vecTs = {ts0, ts1, ts2, ts3, ts4, ts5, ts6, ts7};

    //Test TowerSection
    TowerSection towerSec(vecTs, false, 1);
    TowerSection copyTowerSec{towerSec};
    TowerSection copyTowerSec2{towerSec};

    vector<TowerSection> vecTowerSections = { towerSec, copyTowerSec, copyTowerSec2};
    
    //Test Tower
    Tower tower{vecTowerSections, topMass};

    //Test Stess Analysis
    StressAnalysis stress("LoadCase", ts1.getDiameterBottomOut(), ts1.getBottomArea(), ts1.getSheetThickness(), ts1.getWyBottom(), 
    -5.3280, 1.2330, -2.0660, 127.2680, ts1.getYieldStrength(), ipCalcFacotrs.getSafeTyTowerWallULS() );
    
    Results rs;
    //Test Results
    for(TowerSheet& sheet : vecTs)
    {
        rs.setVecStressAnalysis(stress);
    }

    int i = 1;

    for(TowerSection& sec : tower.getTowerSections())
    {
        for(TowerSheet sheet : sec.getTowerSheets())
        {
            cout << i++ << " " << sheet.getBottomArea() << endl;
        }
    }

    TowerOptimizer towerOpt(ipData, tower);
    
    time1 += clock() - start;
    time1 = time1/CLOCKS_PER_SEC;
    cout << "Laufzeit des Programms: " << time1 << " sec.\n";
    
    cout << "End of this f*cking Program\n";
}