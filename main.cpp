#include <iostream>
#include "InputData/Input.h"
#include "InputData/InputGeometry.h"

using namespace std;

int main()
{
    //Test Data
    double maxDia {6.0}; //m
    double minDia {3.0}; //m
    double towerLength{180.0}; //m
    double maxSectionLength{40.0}; //m
    double maxSheetLength{2.95}; //m
    bool hasDoor{false};
    double maxWeight{500}; //ton
    double maxSectionWeight{250}; //ton
    double topMass{500}; //ton

    //Test Program
    InputGeometry ipGeomData(towerLength, maxSectionLength, maxSheetLength, minDia, maxDia, minDia, maxDia, false);
    InputData ipData(&ipGeomData, maxWeight);
    //Function from base class InputData
    ipData.ToString();
    cout << "Hello World\n";
}