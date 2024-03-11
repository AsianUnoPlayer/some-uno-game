#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*  TO DO LIST
fix up the relationship between playerInv and gameInv
the rest of the game lol
stop procrastinating
*/

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
const int YELLOW = 3;
const int DRAW2 = 10;
const int SKIP = 11;
const int REVERSE = 12;

int gameInventory[13];
int colorInventory[4];
int wildInventory = 8;
vector<int> playerInventory;
vector<int> aiInventory;

bool hasWinner = false;

/*
Card 0-10, Draw 2 [11], Skip [12], Reverse [13] 
Green [+14], Blue [+28], Yellow [+42], Black [+56]
*/

enum card_names {
    RED_ZERO,
    RED_ONE,
    RED_TWO,
    RED_THREE,
    RED_FOUR,
    RED_FIVE,
    RED_SIX,
    RED_SEVEN,
    RED_EIGHT,
    RED_NINE,
    RED_TEN,
    RED_DRAW_2,
    RED_SKIP,
    RED_REVERSE,
    GREEN_ZERO,
    GREEN_ONE,
    GREEN_TWO,
    GREEN_THREE,
    GREEN_FOUR,
    GREEN_FIVE,
    GREEN_SIX,
    GREEN_SEVEN,
    GREEN_EIGHT,
    GREEN_NINE,
    GREEN_TEN,
    GREEN_DRAW_2,
    GREEN_SKIP,
    GREEN_REVERSE,
    BLUE_ZERO,
    BLUE_ONE,
    BLUE_TWO,
    BLUE_THREE,
    BLUE_FOUR,
    BLUE_FIVE,
    BLUE_SIX,
    BLUE_SEVEN,
    BLUE_EIGHT,
    BLUE_NINE,
    BLUE_TEN,
    BLUE_DRAW_2,
    BLUE_SKIP,
    BLUE_REVERSE,
    YELLOW_ZERO,
    YELLOW_ONE,
    YELLOW_TWO,
    YELLOW_THREE,
    YELLOW_FOUR,
    YELLOW_FIVE,
    YELLOW_SIX,
    YELLOW_SEVEN,
    YELLOW_EIGHT,
    YELLOW_NINE,
    YELLOW_TEN,
    YELLOW_DRAW_2,
    YELLOW_SKIP,
    YELLOW_REVERSE,
    DRAW_ANY,
    DRAW_FOUR,
};

map<int, string> card_converter = {
    {RED_ZERO, "Red 0"},
    {RED_ONE, "Red 1"},
    {RED_TWO, "Red 2"},
    {RED_THREE, "Red 3"},
    {RED_FOUR, "Red 4"},
    {RED_FIVE, "Red 5"},
    {RED_SIX, "Red 6"},
    {RED_SEVEN, "Red 7"},
    {RED_EIGHT, "Red 8"},
    {RED_NINE, "Red 9"},
    {RED_TEN, "Red 10"},
    {RED_DRAW_2, "Red Draw 2"},
    {RED_SKIP, "Red Skip"},
    {RED_REVERSE, "Red Reverse"},
    {GREEN_ZERO, "Green 0"},
    {GREEN_ONE, "Green 1"},
    {GREEN_TWO, "Green 2"},
    {GREEN_FOUR, "Green 3"},
    {GREEN_FOUR, "Green 4"},
    {GREEN_FIVE, "Green 5"},
    {GREEN_SIX, "Green 6"},
    {GREEN_SEVEN, "Green 7"},
    {GREEN_EIGHT, "Green 8"},
    {GREEN_NINE, "Green 9"},
    {GREEN_TEN, "Green 10"},
    {GREEN_DRAW_2, "Green Draw 2"},
    {GREEN_SKIP, "Green Skip"},
    {GREEN_REVERSE, "Green Reverse"},
    {BLUE_ZERO, "Blue 0"},
    {BLUE_ONE, "Blue 1"},
    {BLUE_TWO, "Blue 2"},
    {BLUE_THREE, "Blue 3"},
    {BLUE_FOUR, "Blue 4"},
    {BLUE_FIVE, "Blue 5"},
    {BLUE_SIX, "Blue 6"},
    {BLUE_SEVEN, "Blue 7"},
    {BLUE_EIGHT, "Blue 8"},
    {BLUE_NINE, "Blue 9"},
    {BLUE_TEN, "Blue 10"},
    {BLUE_DRAW_2, "Blue Draw 2"},
    {BLUE_SKIP, "Blue Skip"},
    {BLUE_REVERSE, "Blue Reverse"},
    {YELLOW_ZERO, "Yellow 0"},
    {YELLOW_ONE, "Yellow 1"},
    {YELLOW_TWO, "Yellow 2"},
    {YELLOW_THREE, "Yellow 3"},
    {YELLOW_FOUR, "Yellow 4"},
    {YELLOW_FIVE, "Yellow 5"},
    {YELLOW_SIX, "Yellow 6"},
    {YELLOW_SEVEN, "Yellow 7"},
    {YELLOW_EIGHT, "Yellow 8"},
    {YELLOW_NINE, "Yellow 9"},
    {YELLOW_TEN, "Yellow 10"},
    {YELLOW_DRAW_2, "Yellow Draw 2"},
    {YELLOW_SKIP, "Yellow Skip"},
    {YELLOW_REVERSE, "Yellow Reverse"},
    {DRAW_ANY, "Draw Any"},
    {DRAW_FOUR, "Draw 4"},
};

void gameReset()
{
    //int gameInventory[15] = {4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
    //int colorInventory[5] = {25, 25, 25, 25};

    gameInventory[0] = 4;
    for (int x = 1; x < 13; x++) {
        gameInventory[x] = 8;
    }
    
    for (int x = 0; x < 4; x++) {
        colorInventory[x] = 25;
    }
    wildInventory = 8;
}

void giveCard(int playerNumber, int numberOfGives = 1)
{
    int currentGives = 0;

    while (currentGives != numberOfGives) {
        int random_color = rand() % 5, random_inv = rand() % 13;
        int name_of_card = -1;

        switch (random_color) {
            case RED:
                if (colorInventory[RED] > 0 && gameInventory[random_inv] > 0) {
                    colorInventory[RED]--;
                    gameInventory[random_inv]--;

                    name_of_card = random_inv;
                    //cout << card_converter[random_inv] << endl;
                }
                break;

            case GREEN:
                if (colorInventory[GREEN] > 0 && gameInventory[random_inv] > 0) {
                    colorInventory[GREEN]--;
                    gameInventory[random_inv]--;

                    name_of_card = random_inv + 14;
                    //cout << card_converter[random_inv + 14] << endl;
                }
                break;
        
            case BLUE:
                if (colorInventory[BLUE] > 0 && gameInventory[random_inv] > 0) {
                    colorInventory[BLUE]--;
                    gameInventory[random_inv]--;

                    name_of_card = random_inv + 28;
                    //cout << card_converter[random_inv + 28] << endl;
                }
                break;

            case YELLOW:
                if (colorInventory[YELLOW] > 0 && gameInventory[random_inv] > 0) {
                    colorInventory[YELLOW]--;
                    gameInventory[random_inv]--;

                    name_of_card = random_inv + 42;
                    //cout << card_converter[random_inv + 42] << endl;
                }
                break;
            case 4:
                if (wildInventory > 0) {
                    wildInventory--;

                    random_inv = rand() % 2;
                    name_of_card = random_inv + 56;
                    //cout << card_converter[random_inv + 56] << endl;
                }
                break;
        }

        if (name_of_card == -1) {
            continue;
        }

        if (playerNumber == 0) {
            playerInventory.push_back(name_of_card);
        }
        else {
            aiInventory.push_back(name_of_card);
        }

        currentGives++;
    }
}

void place_card(string input)
{
    string card_name;
    for (auto x = card_converter.begin(); x != card_converter.end(); x++) {
        card_name = x->second;

        if (card_name[0] == input[0]) {
            transform(card_name.begin(), card_name.end(), card_name.begin(), ::toupper);

            if (card_name == input) {
                cout << "they match!" << endl;
            }
        }
    }
}

void yourTurn()
{
    cout << "It is your turn!" << endl;

    cout << "==============" << endl;
    cout << "You have the following cards: \n";
    for (int x = 0; x < playerInventory.size(); x++) {
        cout << card_converter[playerInventory[x]] << endl;
    }
    cout << "==============" << endl;

    string input;
    cout << "Please type a valid move (ex. Red 2 or Draw 2)" << endl;
    cin >> input;

    place_card(input);
}

void botTurn()
{
    cout << "It is the bot's turn..." << endl;
}

int main()
{
    //Initial Setup Phase
    srand((unsigned) time(NULL));
    
    //int numberOfPlayers = 0;
    //cout << "How many players [1-10]?" << endl;
    //cin >> numberOfPlayers; 
    cout << "Lets play a game of Uno!!!" << endl;
    cout << endl;

    gameReset();

    //Inital Start
    giveCard(0, 10);
    giveCard(1, 10);
    yourTurn();

    /*
    while (true) {
        yourTurn();
    }
    */

    //actualy game


    return 0;
}