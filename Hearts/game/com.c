//--------------- Revision List -----------------------
//   2016-04-01  lichao  create version
//-----------------------------------------------------


#include "com.h"


void
InitCom(com* pCom)
{
    pCom->m_usPokerCount = 0;
    pCom->m_usScore = 0;
    int i;

    for(i = 1; i < (int)MAX_SUITE; i++)
    {
        InitHand(&pCom->m_szHand[i]);
    }
}
