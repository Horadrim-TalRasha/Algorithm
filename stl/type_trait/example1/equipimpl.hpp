#ifndef EQUIP_IMPL_HPP
#define EQUIP_IMPL_HPP


#include <iostream>


class EquipBase
{
public:
    virtual void IdentifyEquip() = 0;
};


class CommonEquip : public EquipBase
{
public:
    CommonEquip();
    virtual ~CommonEquip();
    void IdentifyEquip();
};

#endif
