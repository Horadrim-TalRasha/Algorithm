//--------------- Revision List -----------------------
//   2016-03-28  lichao  create version
//   2016-04-02  lichao  add info message && test InitCom and InitHand
//-----------------------------------------------------

#include <stdio.h>

#include <game/court.h>

const unsigned short
TestHeartPokers()
{
    printf("Test Heart Pokers \n");
    int j;
    for(j = 0; j < (int)KING; ++j)
    {
        if(getPokerRank(szHeartPokerCards[j]) != (enum Rank)(j + 1) ||
           getPokerSuite(szHeartPokerCards[j]) != HEART_SUITE)
        {
            return j;
        }
    }

    return 0;
}

const unsigned short
TestDiamondPokers()
{
    printf("Test diamond Pokers \n");
    int j;
    for(j = 0; j < (int)KING; ++j)
    {
        if(getPokerRank(szDiamondPokerCards[j]) != (enum Rank)(j + 1) ||
           getPokerSuite(szDiamondPokerCards[j]) != DIAMOND_SUITE)
        {
            return j;
        }
    }

    return 0;
}

const unsigned short
TestSpadePokers()
{
    printf("Test spade Pokers \n");
    int j;
    for(j = 0; j < (int)KING; ++j)
    {
        if(getPokerRank(szSpadePokerCards[j]) != (enum Rank)(j + 1) ||
           getPokerSuite(szSpadePokerCards[j]) != SPADE_SUITE)
        {
            return j;
        }
    }

    return 0;
}

const unsigned short
TestClubPokers()
{
    printf("Test club Pokers \n");
    int j;
    for(j = 0; j < (int)KING; ++j)
    {
        if(getPokerRank(szClubPokerCards[j]) != (enum Rank)(j + 1) ||
           getPokerSuite(szClubPokerCards[j]) != CLUB_SUITE)
        {
            return j;
        }
    }

    return 0;
}

const unsigned short
TestInit()
{
    printf("Test com init \n");
    com com_1;
    int i;

    InitCom(&com_1);
    if(com_1.m_usPokerCount != 0 ||
       com_1.m_usScore != 0)
    {
        return 1;
    }

    
    for(i = 0; i < (int)MAX_SUITE - 1; i++)
    {
        if(com_1.m_szHand[i].m_usPokerCount != 0)
        {
            printf("check hand: %d %u\n", i, com_1.m_szHand[i].m_usPokerCount);
            return i;
        }
    }

    return 0;
}

int main(int argc, char** argv)
{
    unsigned short usRes = 0;
    if((usRes = TestHeartPokers()))
    {
        printf("Test Heart Pokers Error at %u\n", usRes);
        return 1;
    }

    if((usRes = TestDiamondPokers()))
    {
        printf("Test Diamond Pokers Error at %u\n", usRes);
        return 1;
    }

    if((usRes = TestSpadePokers()))
    {
        printf("Test Spade Pokers Error at %u\n", usRes);
        return 1;
    }

    if((usRes = TestClubPokers()))
    {
        printf("Test Club Pokers Error at %u\n", usRes);
        return 1;
    }

    if((usRes = TestInit()))
    {
        printf("Test Init Error at %u\n", usRes);
        return 1;
    }
    printf("Test Success\n");
    return 0;
}
