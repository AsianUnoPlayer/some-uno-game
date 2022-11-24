#ifndef UNO_H
#define UNO_H
#include <vector>
/*
Uno deck has 108 cards.
0 by itself. Two of 1-9 cards of each color. [76]
Two of each Action card: Draw 2, Skip, Reverse [24]
Four of Wild Cards: Change color & Draw 4 [8]
*/

class uno
{
   uno();

// Functions of the uno game
   int current_cardNumber();
   int current_cardValue();
   void give_card(int playerNumber, int amount);

//Uno game database
   void startUno();
   void reset_game();
   bool is_valid();

   int cardValue, cardNumber, deckOfNumbers, deckOfAction,
   deckOfWild, count;
   std::vector<int> playerInventory;

   //Deck Of blah: Number[0], Action[1], Wild[2]
   int deckOfRed[3];
   int deckOfGreen[3];
   int deckOfBlue[3];
   int deckOfYellow[3];
};

#endif