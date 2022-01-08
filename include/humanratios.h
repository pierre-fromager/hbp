
#ifndef H_HUMAN_RATIOS
#define H_HUMAN_RATIOS

#include <iostream>
#include <map>

#include "humanlimbs.h"
#include "humangenders.h"

namespace Human
{

class Ratios
{

public:
    Ratios(unsigned int gender, long double size, long double weight);
    ~Ratios();

private:
    void buildWeights();
    void buildSizes();
    void addWeightRatio(unsigned int limbId, long double ratio);
    long double getWeightRatio(unsigned int limbId);
    void addSizeRatio(unsigned int limbId, long double ratio);
    long double getSizeRatio(unsigned int limbId);
    unsigned int m_gender;
    long double m_size;
    long double m_weight;
    std::map<unsigned int, long double> m_size_ratios;
    std::map<unsigned int, long double> m_weight_ratios;
};

} // namespace Human

#endif