#include <iostream>
#include "uno.h"

uno::uno()
{
    count = 0;
}

//Functions of the Uno Game
int uno::current_cardNumber()
{
    return cardNumber;
}

int uno::current_cardValue()
{
    return cardValue;
}

//Functions of Uno Database
void uno::setCard()
{
    
}

void uno::reset_game()
{
    deckOfNumbers = 72;
    deckOfAction = 24;
    deckOfWild = 8;

    deckOfRed.fill(0);
    deckOfBlue.fill(0);
    deckOfGreen.fill(0);
    deckOfYellow.fill(0);
}

bool is_valid()
{
    //still need to implement
    return true;
}