//--------------- Revision List -----------------------
//   2016-03-20  lichao  create version
//   2016-03-26  lichao  initialize global variable
//                       inplement func 'getPokerSuite'
//   2016-03-28  lichao  implement func 'getPokerRank'
//-----------------------------------------------------

#include "poker.h"


const unsigned short szHeartPokerCards[] = {0x0101, 0x0102, 0x0103, 0x0104, 0x0105,
                                            0x0106, 0x0107, 0x0108, 0x0109, 0x010a,
                                            0x010b, 0x010c, 0x010d};

const unsigned short szDiamondPokerCards[] = {0x0201, 0x0202, 0x0203, 0x0204, 0x0205,
                                              0x0206, 0x0207, 0x0208, 0x0209, 0x020a,
                                              0x020b, 0x020c, 0x020d};

const unsigned short szSpadePokerCards[] = {0x0301, 0x0302, 0x0303, 0x0304, 0x0305,
                                            0x0306, 0x0307, 0x0308, 0x0309, 0x030a,
                                            0x030b, 0x030c, 0x030d};

const unsigned short szClubPokerCards[] = {0x0401, 0x0402, 0x0403, 0x0404, 0x0405,
                                           0x0406, 0x0407, 0x0408, 0x0409, 0x040a,
                                           0x040b, 0x040c, 0x040d};

const unsigned short usBlackJoker = 0x0f;

const unsigned short usRedJoker = 0xf0;


const enum Suite
getPokerSuite(const unsigned short usPoker)
{
    char nSuite = *(char*)(&usPoker);
    if(nSuite <= (char)CLUB_SUITE && nSuite >= (char)HEART_SUITE)
    {
        return (enum Suite)nSuite;
    }

    return ERR_SUITE;
}

const enum Rank
getPokerRank(const unsigned short usPoker)
{
    char nRank = *(char*)((&usPoker) + sizeof(char));
    if(nRank <= (char)KING && nRank >= (char)ACE)
    {
        return (enum Rank)nRank;
    }

    return ERR_RANK;
}



