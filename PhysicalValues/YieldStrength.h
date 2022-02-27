#ifndef YIELDSTRENGTH_H
#define YIELDSTRENGTH_H

#include <vector>
#include <utility>
#include <string>

static const std::vector<std::pair<int, std::vector<double>>> vecYieldStrength
 {
     //Plate thickness is in mm and Yied Strength is in N/mm²
     std::make_pair(16, std::vector<double>{235.0, 275.0, 355.0}),
     std::make_pair(40, std::vector<double>{225.0, 265.0, 345.0}),
     std::make_pair(63, std::vector<double>{215.0, 255.0, 335.0}),
     std::make_pair(80, std::vector<double>{215.0, 245.0, 325.0}),
     std::make_pair(100, std::vector<double>{215.0, 235.0, 315.0}),
     std::make_pair(150, std::vector<double>{195.0, 225.0, 295.0}),
     std::make_pair(200, std::vector<double>{185.0, 215.0, 285.0}),
     std::make_pair(250, std::vector<double>{175.0, 205.0, 275.0})
 };

class CalcYieldStrength
{
    public:
    double getYieldStrengthForPlateThickness(const std::string& SteelGrade, const double& PlateThickness)
    {
        int columnNum;
        if( SteelGrade == "S235" || SteelGrade == "s235" )
            columnNum = 0;
        else if(SteelGrade == "275" || SteelGrade == "s275")
            columnNum = 1;
        else
            columnNum = 2;
            
        for( int i = 0; i < vecYieldStrength.size(); i++)
        {
            
            if( PlateThickness <= (vecYieldStrength.at(i).first / 1000.0))
                return vecYieldStrength.at(i).second.at(columnNum);
        }
        return 0.0;
    }

    private:
};
#endif