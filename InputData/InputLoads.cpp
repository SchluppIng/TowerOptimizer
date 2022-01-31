#include "InputLoads.h"

InputLoads::InputLoads(const double& maxWeight, const double& maxSectionWeight, const double& topMass, 
    const double& bottomFz, const double& bottomFres, const double& bottomMz, const double& bottomMxy,
    const double& topFz, const double& topFres, const double& topMz, const double& topMxy) : 
    MaxWeight{maxWeight}, 
    MaxSectionWeight{maxSectionWeight},
    TopMass{topMass},
    BottomFz{bottomFz},
    BottomFres{bottomFres},
    BottomMz{bottomMz},
    BottomMxy{bottomMxy},
    TopFz{topFz},
    TopFres{topFres},
    TopMz{topMz},
    TopMxy{topMxy}
    {

    }