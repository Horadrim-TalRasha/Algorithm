//--------------- Revision List -----------------------
//   2016-04-01  lichao  create version
//-----------------------------------------------------


#include "poker.h"


typedef struct com
{
  hand m_szHand[MAX_SUITE - 1];
  unsigned short m_usScore;
  unsigned short m_usPokerCount;
} com;

void
InitCom(com* pCom);
