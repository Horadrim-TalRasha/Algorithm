#ifndef MOBILE_SUIT_BASE_HPP
#define MOBILE_SUIT_BASE_HPP


#include "pilotimpl.hpp"
#include "armimpl.hpp"
#include "equipimpl.hpp"


template<typename _Pl, typename _Ar, typename _Ep>
struct MobileSuitBase
{
    typedef _Pl   PilotImpl;
    typedef _Ar   ArmImpl;
    typedef _Ep   EquipImpl;
};

template<typename _MsBase>
struct MobileSuitTrait
{
    typedef typename _MsBase::PilotImpl    PilotImpl;
    typedef typename _MsBase::ArmImpl      ArmImpl;
    typedef typename _MsBase::EquipImpl    EquipImpl;
};

template<typename _Pl, typename _Ar, typename _Ep>
class AllTypeMobileSuit : public MobileSuitBase<_Pl, _Ar, _Ep>
{
public:
    void ListPerformance()
    {
        m_Pilot.IdentifyPilot();
        m_Arm.IdentifyArm();
        m_Equip.IdentifyEquip();
    }

private:
    typedef MobileSuitBase<_Pl, _Ar, _Ep>       _Base;

    typedef typename MobileSuitTrait<_Base>::PilotImpl    _PilotImpl;
    typedef typename MobileSuitTrait<_Base>::ArmImpl      _ArmImpl;
    typedef typename MobileSuitTrait<_Base>::EquipImpl    _EquipImpl;

    _PilotImpl   m_Pilot;
    _ArmImpl     m_Arm;
    _EquipImpl   m_Equip;
};


#endif
