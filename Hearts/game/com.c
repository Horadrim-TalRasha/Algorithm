//--------------- Revision List -----------------------
//   2016-04-01  lichao  create version
//   2016-04-02  lichao  fix segentation fault
//-----------------------------------------------------


#include "com.h"


void
InitCom(com* pCom)
{
    pCom->m_usPokerCount = 0;
    pCom->m_usScore = 0;
    int i;

    for(i = 0; i < (int)MAX_SUITE - 1; i++)
    {
        InitHand(&pCom->m_szHand[i]);
    }
}
