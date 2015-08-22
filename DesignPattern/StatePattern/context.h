/*
 * context.h
 *
 *  Created on: 2015年8月22日
 *      Author: li.chao
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <stdio.h>
#include "state.h"

class State;

class Context
{
public:
    explicit Context(State* pState);
    virtual ~Context();
    void Handle();
    void OperateForStateA();
    void OperateForStateB();

protected:

private:
    friend class State;
    void ChangeState(State* pState);

    State* m_pCurState;
};


#endif /* CONTEXT_H_ */
