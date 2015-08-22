/*
 * concretestatea.h
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */

#ifndef CONCRETE_STATE_A_H_
#define CONCRETE_STATE_A_H_

#include "state.h"

class ConcreteStateA : public State
{
public:
    explicit ConcreteStateA();
    virtual ~ConcreteStateA();
    void Handle(Context* pCon);
};


#endif /* CONCRETESTATEA_H_ */
