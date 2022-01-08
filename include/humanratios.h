
#ifndef H_HUMAN_RATIOS
#define H_HUMAN_RATIOS

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
    /**
     * @brief Get the Weight object
     * 
     * @param limbId 
     * @return long double 
     */
    long double getWeight(unsigned int limbId);
    /**
     * @brief Get the Size object
     * 
     * @param limbId 
     * @return long double 
     */
    long double getSize(unsigned int limbId);
    /**
     * @brief Set the Gender object
     * 
     * @param gender 
     */
    void setGender(unsigned int gender);
    /**
     * @brief Set the Size object
     * 
     * @param size 
     */
    void setSize(long double size);
    /**
     * @brief Set the Weight object
     * 
     * @param weight 
     */
    void setWeight(long double weight);

private:
    void reset();
    void build();
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