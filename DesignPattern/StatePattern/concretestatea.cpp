/*
 * concretestatea.cpp
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */


#include "concretestatea.h"
#include "concretestateb.h"

ConcreteStateA::ConcreteStateA()
{

}

ConcreteStateA::~ConcreteStateA()
{

}

void ConcreteStateA::Handle(Context* pCon)
{
    pCon->OperateForStateA();
    printf("Change State from A to B\n");
    State::ChangeState(pCon, new ConcreteStateB());
}
