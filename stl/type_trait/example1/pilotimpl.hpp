#ifndef PILOT_IMPL_HPP
#define PILOT_IMPL_HPP


#include <iostream>

class PilotBase
{
public:
    virtual void IdentifyPilot() = 0;
};


class NormalPilot : public PilotBase
{
public:
    NormalPilot();
    virtual ~NormalPilot();
    void IdentifyPilot();
};

class AcePilot : public PilotBase
{
public:
    AcePilot();
    virtual ~AcePilot();
    void IdentifyPilot();
};


class Extendent : public PilotBase
{
public:
    Extendent();
    virtual ~Extendent();
    void IdentifyPilot();
};

class Coordinator : public PilotBase
{
public:
    Coordinator();
    virtual ~Coordinator();
    void IdentifyPilot();
};


class NewType : public PilotBase
{
public:
    NewType();
    virtual ~NewType();
    void IdentifyPilot();
};


#endif
