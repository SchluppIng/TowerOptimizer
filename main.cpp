#include <iostream>
#include "InputData/Input.h"

using namespace std;

int main()
{
    //Test Data
    double maxDia {5.0}; //m
    double minDia {2.0}; //m
    double towerLength{80}; //m
    double maxSectionLength{40.0}; //m
    double maxSheetLength{2.95}; //m
    bool hasDoor{false};
    double maxWeight{500}; //ton
    double maxSectionWeight{250}; //ton
    double topMass{500}; //ton

    //Test Program
    InputData ipData(maxWeight);

    ipData.ToString();

    cout << "Hello World\n";
    return 0;
}