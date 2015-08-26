/*
 * observe.cpp
 *
 *  Created on: 2015年8月23日
 *      Author: li.chao
 */


#include "observe.h"

Observer::~Observer()
{

}

ObserveObj::~ObserveObj()
{

}

Publisher::Publisher(MessagePool* pMsgPool) :
m_pMsgPool(pMsgPool)
{

}

Publisher::~Publisher()
{

}

void Publisher::Update()
{
	PublisherUpdate(m_pMsgPool->CurState());
}

void Publisher::PublisherUpdate(const int& nState)
{
    printf("Publisher Found MessagePool State = %d\n", nState);
}

Friend::Friend(MessagePool* pMsgPool) :
m_pMsgPool(pMsgPool)
{

}

Friend::~Friend()
{

}

void Friend::Update()
{
    FriendUpdate(m_pMsgPool->CurState());
}

void Friend::FriendUpdate(const int& nState)
{
	printf("Friend Found MessagePool State = %d\n", nState);
}

MessagePool::MessagePool():
m_nState(0)
{

}

MessagePool::~MessagePool()
{

}

void MessagePool::AddObserver(Observer* pObserver)
{
    m_Observers.push_back(pObserver);
}

void MessagePool::RemoveObserver(Observer* pObserver)
{
    m_Observers.remove(pObserver);
}

void MessagePool::Notify()
{
    std::list<Observer*>::iterator iter = m_Observers.begin();
    for ( ;iter != m_Observers.end(); iter++ )
    {
        (*iter)->Update();
    }
}

void MessagePool::ChangeState(const int& nState)
{
    m_nState = nState;
}

int MessagePool::CurState() const
{
    return m_nState;
}

void MessagePool::ChangeStateAndNotify(const int& nState)
{
    m_nState = nState;
    Notify();
}
