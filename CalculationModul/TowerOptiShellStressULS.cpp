#include "TowerOptiShellStressULS.h"
#include <iostream>

TowerOptiShellStressULS::TowerOptiShellStressULS(const InputData& InputData, const Tower& TowerInput) :
ipData{InputData},
tower{TowerInput}
{
    optimizeShellStressULS();
}

TowerOptiShellStressULS::~TowerOptiShellStressULS()
{

}

void TowerOptiShellStressULS::optimizeShellStressULS()
{
    std::cout << "Hier bin ich" << std::endl;
}