#include <iostream>
#include "InputData/Input.h"
#include "InputData/InputGeometry.h"
#include "InputData/InputLoads.h"
#include "InputData/InputCalcFactors.h"
#include "Tower/TowerSheet.h"

using namespace std;

int main()
{
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
    double bottomDia {4.0}; //m
    double topDia{3.9}; //m
    double thickness{0.1}; //m
    double sheetLen{maxSheetLength};
    //__________________________________________________________
    //Test Program
    InputGeometry ipGeomData(towerLength, maxSectionLength, maxSheetLength, minDia, maxDia, minDia, maxDia, hasDoor);
    InputLoads ipLoads(maxWeight, maxSectionWeight, topMass, bottomMxy, bottomMz, bottomFz, bottomFres, topMxy, topMz, topFz, topFres);
    InputCalcFactors ipCalcFacotrs(towerTilt, rotStiff, transStiff);
    InputData ipData(ipGeomData, ipLoads, ipCalcFacotrs);

    //Test TowerSheet
    TowerSheet ts(bottomDia, topDia, sheetLen, thickness);
    //Test to change Values
    ts.setDiameterBottomOut(4.4);
    ts.setDiameterTopOut(4.4);
    ts.setSheetThickness(0.043);
    
    cout << "End of this f*cking Program\n";
}