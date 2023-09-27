#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
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
vector<string> playerInventory;

bool hasWinner = false;

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

void giveCard(int playerNumber)
{
    int random_color = rand() % 4, random_inv = rand() % 13;

    switch (random_color) {
        case RED:
            if (colorInventory[RED] != 0 && gameInventory[random_inv] != 0) {
                colorInventory[RED]--;
                gameInventory[random_inv]--;
            }
            break;

        case GREEN:
            if (colorInventory[GREEN] != 0 && gameInventory[random_inv] != 0) {
                colorInventory[GREEN]--;
                gameInventory[random_inv]--;
            }
            break;
        
        case BLUE:
            if (colorInventory[BLUE] != 0 && gameInventory[random_inv] != 0) {
                colorInventory[BLUE]--;
                gameInventory[random_inv]--;
            }
            break;

        case YELLOW:
            if (colorInventory[YELLOW] != 0 && gameInventory[random_inv] != 0) {
                colorInventory[YELLOW]--;
                gameInventory[random_inv]--;
            }
            break;
    }
}

void yourTurn()
{
    cout << "It is your turn!" << endl;
}

void botTurn()
{
    cout << "It is the bot's turn..." << endl;
}

int main()
{
    //Initial Setup Phase
    srand((unsigned) time(NULL));
    
    int numberOfPlayers = 0;
    cout << "How many players [1-10]?" << endl;
    cin >> numberOfPlayers; 
    cout << endl;

    gameReset();
    giveCard(0);

    return 0;
}