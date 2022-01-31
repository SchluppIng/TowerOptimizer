#include <iostream>
#include "InputData/Input.h"
#include "InputData/InputGeometry.h"
#include "InputData/InputLoads.h"

using namespace std;

int main()
{
    //Test data for geometry
    double maxDia {6.0}; //m
    double minDia {3.0}; //m
    double towerLength{180}; //m
    double maxSectionLength{40.0}; //m
    double maxSheetLength{2.95}; //m
    bool hasDoor{false};

    //Test data for loads
    double maxWeight{500}; //ton
    double maxSectionWeight{40}; //ton
    double topMass{500}; //ton
    double bottomMxy{0}; //kNm
    double bottomMz{0};  //kNm
    double bottomFz{0}; //kN
    double bottomFres{0}; //kN


    //Test Program
    InputGeometry ipGeomData(towerLength, maxSectionLength, maxSheetLength, minDia, maxDia, minDia, maxDia, false);
    InputLoads ipLoads(maxWeight, maxSectionWeight, topMass, bottomMxy, bottomMz, bottomFz, bottomFres);
    InputData ipData(&ipGeomData, &ipLoads);


    ipData.ToString();
    cout << "End of this f*cking Program\n";
}