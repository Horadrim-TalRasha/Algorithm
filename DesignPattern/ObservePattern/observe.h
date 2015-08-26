/*
 * observe.h
 *
 *  Created on: 2015年8月23日
 *      Author: li.chao
 */

#ifndef OBSERVE_H_
#define OBSERVE_H_

#include <stdio.h>
#include <list>

class MessagePool;

class Observer
{
public:
    virtual ~Observer();
    virtual void Update() = 0;
};

class ObserveObj
{
public:
    virtual ~ObserveObj();
    virtual void AddObserver(Observer* pObserver) = 0;
    virtual void RemoveObserver(Observer* pObserver) = 0;
    virtual void Notify() = 0;
};

class Publisher : public Observer
{
public:
    explicit Publisher(MessagePool* pMsgPool);
    virtual ~Publisher();
    void Update();
private:
    void PublisherUpdate(const int& nState);

    MessagePool* m_pMsgPool;
};

class Friend : public Observer
{
public:
    explicit Friend(MessagePool* pMsgPool);
    virtual ~Friend();
    void Update();
private:
    void FriendUpdate(const int& nState);

    MessagePool* m_pMsgPool;
};

class MessagePool : public ObserveObj
{
public:
    explicit MessagePool();
    virtual ~MessagePool();
    void AddObserver(Observer* pObserver);
    void RemoveObserver(Observer* pObserver);
    void Notify();
    void ChangeState(const int& nState);
    void ChangeStateAndNotify(const int& nState);
    int CurState() const;

private:
    void Update(const int& nState);

    std::list<Observer*> m_Observers;
    int m_nState;
};
#endif /* OBSERVE_H_ */
