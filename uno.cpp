#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include "uno.h"
using namespace std;

/*
srand((unsigned) time(NULL));
int random = rand() % 10;
*/

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

void uno::give_card(int playerNumber, int amount)
{
    for (int x = 0; x < playerNumber; x++) {
        playerInventory[x] += amount;
    }
}
//Functions of Uno Database
void uno::startUno()
{
    int answer;

    cout << "How many will play? [1-10]: ";
    cin >> answer;
    cout << endl; 
    assert(answer <= 10 && answer > 0);

    playerInventory.resize(answer);

    for (int x = 0; x < answer; x++) {
        playerInventory[x] = 10;
    }
}

void uno::reset_game()
{
    deckOfNumbers = 72;
    deckOfRed[0] = 18;
    deckOfBlue[0] = 18;
    deckOfGreen[0] = 18;
    deckOfYellow[0] = 18;

    deckOfAction = 24;
    deckOfRed[0] = 6;
    deckOfBlue[0] = 6;
    deckOfGreen[0] = 6;
    deckOfYellow[0] = 6;

    deckOfWild = 8;
}

bool is_valid()
{
    //still need to implement
    return true;
}