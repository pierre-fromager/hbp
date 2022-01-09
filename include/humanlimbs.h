
#ifndef H_HUMAN_LIMBS
#define H_HUMAN_LIMBS

#include <map>

namespace Human
{
namespace Limbs
{
enum Id
{
    TRUNC = 0,
    HEAD = 1,
    ARM_L_UP = 10,
    ARM_L_LO = 11,
    ARM_L_HAND = 12,
    ARM_R_UP = 20,
    ARM_R_LO = 21,
    ARM_R_HAND = 22,
    LEG_L_UP = 30,
    LEG_L_LO = 31,
    LEG_L_FOOT = 32,
    LEG_R_UP = 40,
    LEG_R_LO = 41,
    LEG_R_FOOT = 42,
};

static const Id IdAll[] = {
    TRUNC, HEAD,
    ARM_L_UP, ARM_L_LO, ARM_L_HAND,
    ARM_R_UP, ARM_R_LO, ARM_R_HAND,
    LEG_L_UP, LEG_L_LO, LEG_L_FOOT,
    LEG_R_UP, LEG_R_LO, LEG_R_FOOT};

static const std::map<Id, std::string> Labels = {
    {TRUNC, "Trunc"},
    {HEAD, "Head"},
    {ARM_L_UP, "Left upper arm"},
    {ARM_L_LO, "Left lower arm"},
    {ARM_L_HAND, "Left hand"},
    {ARM_R_UP, "Right upper arm"},
    {ARM_R_LO, "Right lower arm"},
    {ARM_R_HAND, "Right hand"},
    {LEG_L_UP, "Left upper leg"},
    {LEG_L_LO, "Left lower leg"},
    {LEG_L_FOOT, "Left foot"},
    {LEG_R_UP, "Left upper leg"},
    {LEG_R_LO, "Left lower leg"},
    {LEG_R_FOOT, "Left foot"},
};

} // namespace Limbs

} // namespace Human

#endif