#ifndef UNO_H
#define UNO_H
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
   void current_cardValue();
   void current_gameDeck();

//Uno game database
   void reset_game();

   int color, value, playerInventory, deckOfNumbers, deckOfAction,
   deckOfWild;

   int deckOfRed[27];
   int deckOfGreen[27];
   int deckOfBlue[27];
   int deckOfYellow[27];
};

#endif