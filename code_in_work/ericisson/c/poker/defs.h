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

const short red_joker_;
const short black_joker_;

typedef struct PokerCard
{
	enum Suits suit_;
	enum Numbers number_;
} PokerCard;


typedef struct Deck
{
	PokerCard deck[MAX_Number * MAX_Suit + 2];
} Deck;

#endif