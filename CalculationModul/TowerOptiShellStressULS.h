#ifndef TOWEROPTISTRESSULS_H
#define TOWEROPTISTRESSULS_H

#include "../Analysis/Results.h"
#include "../Tower/Tower.h"
#include "../InputData/Input.h"

class TowerOptiShellStressULS
{
public:
    TowerOptiShellStressULS(){}
    TowerOptiShellStressULS(const InputData& InputData, const Tower& TowerInput);
    ~TowerOptiShellStressULS();

    void optimizeShellStressULS();

private:    
    Tower tower;
    InputData ipData;
};

#endif