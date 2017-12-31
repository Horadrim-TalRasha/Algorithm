#ifndef WEAPON_IMPL_HPP
#define WEAPON_IMPL_HPP

#include <iostream>

class ArmBase
{
public:
    virtual void IdentifyArm() = 0;
};


class CommonArm : public ArmBase
{
public:
    CommonArm();
    virtual ~CommonArm();
    void IdentifyArm();
};


#endif
