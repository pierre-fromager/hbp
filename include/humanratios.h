
#ifndef H_HUMAN_RATIOS
#define H_HUMAN_RATIOS

#include <map>
#include "humanlimbs.h"
#include "humangenders.h"

namespace Human
{

/**
 * @brief Human limbs weight & size calculator
 * @url http://villemin.gerard.free.fr/Biologie/CorpsPro.htm
 * 
 */
class Ratios
{

public:
    Ratios(unsigned int gender, long double size, long double weight);
    ~Ratios();
    /**
     * @brief Get the limb weight from limbId
     * @todo 14.5% missing to share out to existing limbs
     * 
     * @param limbId 
     * @return long double 
     */
    long double getWeight(unsigned int limbId);
    /**
     * @brief Get the main weight
     * 
     * @return long double 
     */
    long double getWeight();
    /**
     * @brief Get the limb size from limbId
     * 
     * @param limbId 
     * @return long double 
     */
    long double getSize(unsigned int limbId);
    /**
     * @brief Get the main size
     * 
     * @return long double 
     */
    long double getSize();
    /**
     * @brief Get the gender
     * 
     * @return unsigned int 
     */
    unsigned int getGender();
    /**
     * @brief Set the gender
     * 
     * @param gender 
     */
    void setGender(unsigned int gender);
    /**
     * @brief Set the main size
     * 
     * @param size 
     */
    void setSize(long double size);
    /**
     * @brief Set the main weight
     * 
     * @param weight 
     */
    void setWeight(long double weight);

private:
    unsigned int m_gender;
    long double m_size;
    long double m_weight;
    std::map<unsigned int, long double> m_size_ratios;
    std::map<unsigned int, long double> m_weight_ratios;
    void reset();
    void build();
    void buildWeights();
    void buildSizes();
    void addWeightRatio(unsigned int limbId, long double ratio);
    long double getWeightRatio(unsigned int limbId);
    void addSizeRatio(unsigned int limbId, long double ratio);
    long double getSizeRatio(unsigned int limbId);
};

} // namespace Human

#endif