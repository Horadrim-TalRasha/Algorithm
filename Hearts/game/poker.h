//--------------- Revision List -----------------------
//   2016-03-20  lichao  create version
//   2016-03-26  lichao  add interface get the suite of poker
//-----------------------------------------------------

#ifndef POKER_H
#define POKER_H

enum Suite
{
    ERR_SUITE = -1,
    HEART_SUITE = 1,
    DIAMOND_SUITE = 2,
    SPADE_SUITE = 3,
    CLUB_SUITE = 4
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
    KING = 13
};

extern const unsigned short szHeartPokerCards[];

extern const unsigned short szDiamondPokerCards[];

extern const unsigned short szSpadePokerCards[];

extern const unsigned short szClubPokerCards[];

extern const unsigned short usBlackJoker;

extern const unsigned short usRedJoker;

const enum Suite
getPokerSuite(const unsigned short usPoker);

#endif
