#include "def.h"

 extern uint8_t Board_g [9];
 extern uint8_t sympol_of_player_1 ;
 extern uint8_t sympol_of_player_2 ;

void drawBoard(uint8_t *board)
{
    printf("-------------------------\n");
    printf("|   %c   |   %c   |   %c   |\n", board[0], board[1], board[2]);
    printf("-------------------------\n");
    printf("|   %c   |   %c   |   %c   |\n", board[3], board[4], board[5]);
    printf("-------------------------\n");
    printf("|   %c   |   %c   |   %c   |\n", board[6], board[7], board[8]);
    printf("-------------------------\n");
    return;
}



void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    board[position] = value;
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)

{
    static uint8_t chosen_player_num;
    static uint8_t chosen_char;
    static bool chosen_flag = false;

    if (playerNumber !=1 && playerNumber != 2)
    {
        printf("wrong player number. \n");
        return 1;

    }
    if(! chosen_flag)
    {
        printf("Player %u : Please choose X or O ?\n", playerNumber);
        scanf(" %c", symbol);
        if(*symbol != 'X' && *symbol != 'O')
        {
            printf("Invalid input. \n");
            return 1;
        }
        else
        {
            printf("Valid input and not chosen before\n");
            printf("The input symbol is valid --> Saving for next inputs. \n");
            chosen_flag = true;
            chosen_char = *symbol;
            chosen_player_num = playerNumber;
            return 0;
        }
    }
    else
    {
        printf("Player %u : Please choose X or O ?\n", playerNumber);
        scanf(" %c", symbol);

        if(playerNumber != chosen_player_num && *symbol != chosen_char && (*symbol == 'X' || *symbol == 'O'))
        {

            printf("The input symbol is valid --> Saving for next inputs. \n");
            return 0;

        }
        else
        {
            printf("spmething wrong with player number or chosen sympol\n");
            return 1;
        }
    }
}



void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t position;
    printf("Please enter position for next move..\n");
    scanf(" %d", &position);

    if(playerNumber == 1)
    {
        Board_g[position-1] = sympol_of_player_1;
    }
    else
    {
        Board_g[position-1] = sympol_of_player_2;
    }
}

void getGameState(uint8_t *board, uint8_t *gameState)
{

    if( (board[0] == board[1] && board[1] == board[2] && board[2] != 0) ||
        (board[3] == board[4] && board[4] == board[5] && board[5] != 0) ||
        (board[6] == board[7] && board[7] == board[8] && board[8] != 0) ||
        (board[0] == board[3] && board[3] == board[6] && board[6] != 0) ||
        (board[1] == board[4] && board[4] == board[7] && board[7] != 0) ||
        (board[2] == board[5] && board[5] == board[8] && board[8] != 0) ||
        ((board[8] != 0) && (board[0] == board[4]) && (board[4] == board[8]) ) ||
        ((board[6] != 0) && (board[2] == board[4]) && (board[4] == board[6]) ) ){

        *gameState = 0;
        return;
    }


    for(int i=0; i<9; i++)
    {
        if(board[i] == 0)
        {
            *gameState = 2;
            return;
        }
    }

    *gameState = 1;
    return;


}
