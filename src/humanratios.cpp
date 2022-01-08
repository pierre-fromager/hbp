
#include "humanratios.h"

Human::Ratios::Ratios(unsigned int g, long double s, long double w) : m_gender(g),
                                                                      m_size(s),
                                                                      m_weight(w)
{
}

Human::Ratios::~Ratios()
{
    /*m_weight.clear();
    m_size.clear();*/
}

void Human::Ratios::buildWeights()
{
    const long double arm_up = 3.2;
    const long double arm_lo = 1.9;
    const long double arm_hand = 0.6;
    const long double leg_up = 10.5;
    const long double leg_lo = 4.7;
    const long double leg_foot = 1.4;
    addWeightRatio(Human::Limbs::Id::HEAD, 8.2);
    addWeightRatio(Human::Limbs::Id::TRUNC, 55);
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
    const long double arm_up = 17.2;
    const long double arm_lo = 15.7;
    const long double arm_hand = 10.4;
    const long double leg_up = 23.2;
    const long double leg_lo = 24.7;
    const long double leg_foot = 4.2;
    addSizeRatio(Human::Limbs::Id::HEAD, 13.8);
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