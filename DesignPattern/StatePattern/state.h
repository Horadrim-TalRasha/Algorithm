/*
 * state.h
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */

#ifndef STATE_H_
#define STATE_H_

#include "context.h"

class Context;

class State
{
public:
    explicit State();
    virtual ~State();
    virtual void Handle(Context* pCon) = 0;
protected:
    void ChangeState(Context* pCon, State* pState);
};



#endif /* STATE_H_ */
