#include "InputLoads.h"

InputLoads::InputLoads(const double& maxWeight, const double& maxSectionWeight, const double& topMass, const double& bottomMxy, const double& bottomMz, 
    const double& bottomFz, const double& bottomFres) : 
    MaxWeight{maxWeight}, 
    MaxSectionWeight{maxSectionWeight},
    TopMass{topMass},
    BottomMxy{bottomMxy},
    BottomMz{bottomMz},
    BottomFz{bottomFz},
    BottomFres{bottomFres}
    {

    }