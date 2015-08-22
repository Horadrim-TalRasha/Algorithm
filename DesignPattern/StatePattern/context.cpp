/*
 * context.cpp
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */

#include "context.h"

Context::Context(State* pState) :
m_pCurState(pState)
{

}

Context::~Context()
{

}

void Context::Handle()
{
    m_pCurState->Handle(this);
}

void Context::OperateForStateA()
{
    printf("Do operation in State A\n");
}

void Context::OperateForStateB()
{
    printf("Do operation in State B\n");
}

void Context::ChangeState(State* pState)
{
    m_pCurState = pState;
}


