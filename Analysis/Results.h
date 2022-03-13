#ifndef RESULTS_H
#define RESULTS_H

#include <vector>
#include "StressAnalysis.h"

class Results
{
public:
    Results();
    ~Results();

    void setVecStressAnalysis(const StressAnalysis& Stress);

    std::vector<StressAnalysis> getVecStressAnalysis() { return vecStressAnalysis;}

private:
    std::vector<StressAnalysis> vecStressAnalysis;
};

#endif