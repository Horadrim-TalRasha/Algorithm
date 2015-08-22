#ifndef CONCRETE_STATE_B_H
#define CONCRETE_STATE_B_H

#include "state.h"

class ConcreteStateB : public State
{
public:
    explicit ConcreteStateB();
    virtual ~ConcreteStateB();
    void Handle(Context* pCon);
};

#endif
