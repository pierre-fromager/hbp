
#include "humanratios.h"

Human::Ratios::Ratios(unsigned int g, long double s, long double w) : m_gender(g),
                                                                      m_size(s),
                                                                      m_weight(w)
{
    build();
}

Human::Ratios::~Ratios()
{
    reset();
}

void Human::Ratios::setGender(unsigned int gender)
{
    m_gender = gender;
}

void Human::Ratios::setSize(long double size)
{
    m_size = size;
}

void Human::Ratios::setWeight(long double weight)
{
    m_weight = weight;
}

long double Human::Ratios::getWeight(unsigned int limbId)
{
    return getWeightRatio(limbId) / 100 * m_weight;
}

long double Human::Ratios::getSize(unsigned int limbId)
{
    return getSizeRatio(limbId) / 100 * m_size;
}

void Human::Ratios::buildWeights()
{
    const bool is_male = (m_gender == Human::Genders::Id::MALE);
    const long double arm_up = is_male ? 3.2 : 2.9;
    const long double arm_lo = is_male ? 1.9 : 1.6;
    const long double arm_hand = is_male ? 0.6 : 0.5;
    const long double leg_up = is_male ? 10.5 : 11.7;
    const long double leg_lo = is_male ? 4.7 : 5.3;
    const long double leg_foot = is_male ? 1.4 : 1.3;
    addWeightRatio(Human::Limbs::Id::HEAD, 8.2);
    addWeightRatio(Human::Limbs::Id::TRUNC, is_male ? 55 : 53);
    addWeightRatio(Human::Limbs::Id::ARM_L_UP, arm_up);
    addWeightRatio(Human::Limbs::Id::ARM_L_LO, arm_lo);
    addWeightRatio(Human::Limbs::Id::ARM_L_HAND, arm_hand);
    addWeightRatio(Human::Limbs::Id::ARM_R_UP, arm_up);
    addWeightRatio(Human::Limbs::Id::ARM_R_LO, arm_lo);
    addWeightRatio(Human::Limbs::Id::ARM_R_HAND, arm_hand);
    addWeightRatio(Human::Limbs::Id::LEG_L_UP, leg_up);
    addWeightRatio(Human::Limbs::Id::LEG_L_LO, leg_lo);
    addWeightRatio(Human::Limbs::Id::LEG_L_FOOT, leg_foot);
    addWeightRatio(Human::Limbs::Id::LEG_R_UP, leg_up);
    addWeightRatio(Human::Limbs::Id::LEG_R_LO, leg_lo);
    addWeightRatio(Human::Limbs::Id::LEG_R_FOOT, leg_foot);
}

void Human::Ratios::buildSizes()
{
    const bool is_male = (m_gender == Human::Genders::Id::MALE);
    const long double arm_up = is_male ? 17.2 : 19.3;
    const long double arm_lo = is_male ? 15.7 : 16.6;
    const long double arm_hand = 10.4;
    const long double leg_up = is_male ? 23.2 : 24.7;
    const long double leg_lo = is_male ? 24.7 : 25.6;
    const long double leg_foot = is_male ? 4.2 : 4;
    addSizeRatio(Human::Limbs::Id::HEAD, is_male ? 13.8 : 13);
    addSizeRatio(Human::Limbs::Id::TRUNC, 30);
    addSizeRatio(Human::Limbs::Id::ARM_L_UP, arm_up);
    addSizeRatio(Human::Limbs::Id::ARM_L_LO, arm_lo);
    addSizeRatio(Human::Limbs::Id::ARM_L_HAND, arm_hand);
    addSizeRatio(Human::Limbs::Id::ARM_R_UP, arm_up);
    addSizeRatio(Human::Limbs::Id::ARM_R_LO, arm_lo);
    addSizeRatio(Human::Limbs::Id::ARM_R_HAND, arm_hand);
    addSizeRatio(Human::Limbs::Id::LEG_L_UP, leg_up);
    addSizeRatio(Human::Limbs::Id::LEG_L_LO, leg_lo);
    addSizeRatio(Human::Limbs::Id::LEG_L_FOOT, leg_foot);
    addSizeRatio(Human::Limbs::Id::LEG_R_UP, leg_up);
    addSizeRatio(Human::Limbs::Id::LEG_R_LO, leg_lo);
    addSizeRatio(Human::Limbs::Id::LEG_R_FOOT, leg_foot);
}

void Human::Ratios::addWeightRatio(unsigned int limbId, long double ratio)
{
    m_weight_ratios[limbId] = ratio;
}

long double Human::Ratios::getWeightRatio(unsigned int limbId)
{
    return m_weight_ratios[limbId];
}

void Human::Ratios::addSizeRatio(unsigned int limbId, long double ratio)
{
    m_size_ratios[limbId] = ratio;
}

long double Human::Ratios::getSizeRatio(unsigned int limbId)
{
    return m_size_ratios[limbId];
}

void Human::Ratios::reset()
{
    m_weight_ratios.clear();
    m_size_ratios.clear();
}

void Human::Ratios::build()
{
    Human::Ratios::buildWeights();
    Human::Ratios::buildSizes();
}