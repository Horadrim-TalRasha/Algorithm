/*
 * state.cpp
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */
#include "state.h"


State::State()
{

}

State::~State()
{

}

void State::ChangeState(Context* pCon, State* pState)
{
    pCon->ChangeState(pState);
}

