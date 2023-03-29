#include "def.h"

 uint8_t Board_g [9] = {' '} ;
 uint8_t sympol_of_player_1 ;
 uint8_t sympol_of_player_2 ;
 uint8_t gameState = -1;
 bool alternate = true;


int main(void)
{
    //Test Case : X player winning 3 times
    //All Rows
    uint8_t testBoard1 [9] = {'X','X','X','O','X',' ',' ', 'O','O' };
    uint8_t testBoard2 [9] = {'O','X',' ',' ', 'O','O','X','X','X'};
    uint8_t testBoard3 [9] = {'X','O','O','X','X','X',' ', 'O','X' };
    uint8_t testGameState = -1;
    printf("All rows tests. \n");
    getGameState(testBoard1, &testGameState);
    printf("%d -> which means winning\n", testGameState);
    getGameState(testBoard2, &testGameState);
    printf("%d -> which means winning\n", testGameState);
    getGameState(testBoard3, &testGameState);
    printf("%d -> which means winning\n", testGameState);

    //All Columns
    printf("All columns tests. \n");
    uint8_t testBoard4 [9] = {'X','O','O','X','O',' O', 'X','O','X' };
    uint8_t testBoard5 [9] = {'O','O',' X',' ', 'O','X','O',' ','X'};
    uint8_t testBoard6 [9] = {'O','X','O','O','X','O',' ', 'X','X' };
    getGameState(testBoard4, &testGameState);
    printf("%d -> which means winning\n", testGameState);
    getGameState(testBoard5, &testGameState);
    printf("%d -> which means winning\n", testGameState);
    getGameState(testBoard6, &testGameState);
    printf("%d -> which means winning\n", testGameState);

    //Diagnals tests
    printf("Diagonal tests. \n");
    uint8_t testBoard7 [9] = {'X','O','O',' ','X',' O', 'X','O','X' };
    uint8_t testBoard8 [9] = {'O','O',' X',' ', 'X','O','X',' ','O'};

    getGameState(testBoard7, &testGameState);
    printf("%d -> which means winning\n", testGameState);
    getGameState(testBoard8, &testGameState);
    printf("%d -> which means winning\n", testGameState);


    //Draw tests
    printf("Draw tests. \n");
    uint8_t testBoard9 [9] = {'X','O','O','O','X',' X', 'X','X','O' };
    uint8_t testBoard10 [9] = {'X','O',' X','O', 'X','X','O','X','O'};
    uint8_t testBoard11 [9] = {'O','X','O','X','O','X','X', 'O','X' };
    getGameState(testBoard9, &testGameState);
    printf("%d -> which means draw\n", testGameState);
    getGameState(testBoard10, &testGameState);
    printf("%d -> which means draw\n", testGameState);
    getGameState(testBoard11, &testGameState);
    printf("%d -> which means draw \n", testGameState);



   while (getPlayerSymbol(1,&sympol_of_player_1) )
   {
       // do nothing
   }


   while (getPlayerSymbol(2, &sympol_of_player_2))
   {
       // do nothing
   }

   drawBoard(Board_g);
   do {
        if(alternate )
        {
            alternate = false;
            loadAndUpdate(1);
            drawBoard(Board_g);

        }

        else
        {
            alternate = true;
            loadAndUpdate(2);
            drawBoard(Board_g);
        }

        getGameState(Board_g, &gameState);

       }
    while (gameState == 2);

    switch (gameState)
    {
        case 1 : printf("Draw !! \n");
        break;
        case 0 : printf("You won, game has ended \n");
        break;
    }

return 0;
}
