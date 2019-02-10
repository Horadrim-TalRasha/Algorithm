#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <stdlib.h>

enum Suits
{
    Diamond = 0,
    Spade,
    Hearts,
    Club,
    MAX_Suit
};

enum Numbers
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    MAX_Number
};

const short red_joker_ = MAX_Number + 2;
const short black_joker_ = MAX_Number + 1;

#endif