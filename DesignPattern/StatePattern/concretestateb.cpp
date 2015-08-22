/*
 * concretestateb.cpp
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */

#include "concretestateb.h"
#include "concretestatea.h"

ConcreteStateB::ConcreteStateB()
{

}

ConcreteStateB::~ConcreteStateB()
{

}

void ConcreteStateB::Handle(Context* pCon)
{
	pCon->OperateForStateB();
	printf("Change State from B to A\n");
	State::ChangeState(pCon, new ConcreteStateA());
}


