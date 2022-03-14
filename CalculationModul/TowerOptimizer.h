#ifndef TOWEROPTIMIZER_H
#define TOWEROPTIMIZER_H

#include "../Tower/Tower.h"
#include "../InputData/Input.h"
#include "../PhysicalValues/PhysicalValues.h"
#include "TowerOptiShellStressULS.h"

class TowerOptimizer
{
public:
    TowerOptimizer(const InputData& inputData, const Tower& towerData);
    ~TowerOptimizer(){}

private:
   InputData input;
   Tower tower;
};

#endif