//--------------- Revision List -----------------------
//   2016-03-28  lichao  create version
//-----------------------------------------------------

#include <stdio.h>

#include <game/poker.h>

const unsigned short
TestHeartPokers()
{
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

    printf("Test Success\n");
    return 0;
}
