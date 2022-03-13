#include "Results.h"

Results::Results()
{

}

Results::~Results()
{

}

void Results::setVecStressAnalysis(const StressAnalysis& Stress)
{
    vecStressAnalysis.push_back(Stress);
}