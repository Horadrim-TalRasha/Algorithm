//--------------- Revision List -----------------------
//   2016-03-20  lichao  create version
//   2016-03-26  lichao  add interface get the suite of poker
//   2016-03-28  lichao  add interface getPokerRank
//   2016-04-01  lichao  add max_suite in enum Suite &
//                       add max_rank in enum Rank
//                       declare hand struct & InitHand
//-----------------------------------------------------

#ifndef POKER_H
#define POKER_H

#include <string.h>

enum Suite
{
    ERR_SUITE = -1,
    HEART_SUITE = 1,
    DIAMOND_SUITE = 2,
    SPADE_SUITE = 3,
    CLUB_SUITE = 4,
    MAX_SUITE
};

enum Rank
{
    ERR_RANK = -1,
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JAKE = 11,
    QUEEN = 12,
    KING = 13,
    MAX_RANK = 14
};

typedef struct hand
{
  unsigned short m_szHand[MAX_RANK - 1];
  unsigned short m_usHandCount;
} hand; 

extern const unsigned short szHeartPokerCards[];

extern const unsigned short szDiamondPokerCards[];

extern const unsigned short szSpadePokerCards[];

extern const unsigned short szClubPokerCards[];

extern const unsigned short usBlackJoker;

extern const unsigned short usRedJoker;

const enum Suite
getPokerSuite(const unsigned short usPoker);

const enum Rank
getPokerRank(const unsigned short usPoker);

void
InitHand(hand* pHand);


#endif
