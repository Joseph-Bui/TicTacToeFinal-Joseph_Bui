#include <stdio.h>
#include <stdbool.h>

//Define constants for row, columns, and players
#define ROWS 3
#define COLUMNS 3
#define PLAYERS 2

//Store the player symbols into a char array
const char symbols[PLAYERS] = {'X', 'O'};

//function that prints the gameBoard
void printGameBoard(char gameBoard[ROWS][COLUMNS]) 
{

    //outter loop that prints the rows of the board
    for (int row = 0; row < ROWS; row++) 
    {

        //inner loop that prints the columns of the board
        for (int col = 0; col < COLUMNS; col++) 
        {
            printf("%c ", gameBoard[row][col]);

            //print the column dividers for the board
            if (col < COLUMNS - 1) 
            {
                printf("| ");
            }
        }
        
        printf("\n");

        //print the row dividers for the board
        if (row < ROWS - 1) 
        {
            printf("---------\n");
        }

    }
}//end printGameBoard


//function that checks the state of the board 
int checkForWinner(char gameBoard[ROWS][COLUMNS]) 
{
    //Check each row for a match
    for (int i = 0; i < ROWS; i++) 
    {
        //if statement that checks the individual row
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') 
        {
            return gameBoard[i][0];
        }
    }

    //Check for a match in each column
    for (int i = 0; i < COLUMNS; i++) 
    {

        //if statement that check the individual column
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') 
        {
            return gameBoard[0][i];
        }
    }

    //Check for a match in each diagonal
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') 
    {
        return gameBoard[0][0];
    }

    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') 
    {
        return gameBoard[0][2];
    }

    //Check board for a draw
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLUMNS; j++) 
        {
            if (gameBoard[i][j] == ' ')
            {
                //incomplete game
                return 0;
            }
        }
    }

    //A draw game
    return -1;
    
}//end checkForWinner

//function that places the character on the board if it is open
bool makeMove(char gameBoard[ROWS][COLUMNS], int row, int col, int player)
 {

    //if statement to check if position is empty
    if (gameBoard[row][col] != ' ') 
    {
        //if empty then return false    
        return false;
    }
    
    //if position is empty then place the character onto the board
    else
    {
        gameBoard[row][col] = symbols[player];
        return true;
    }
    
}//end makeMove

//main function
int main() 
{
    //create a new board
    char gameBoard[ROWS][COLUMNS];

    //fill in the new game board with empty spaces
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLUMNS; j++) 
        {
            gameBoard[i][j] = ' ';
        }
    }

    int player = 0;
    int result;

    //loop that will print the game board until there is a winner or a draw
    while (true) {

        //call the print game board function
        printGameBoard(gameBoard);

	    
        int row, col;

        //Ask for the player one move if it is X
        if(symbols[player] == 'X')
        {
            printf("It is player one's turn. Please enter a row and a column: ");
            scanf("%d %d", &row, &col);
        }

        //Ask for player 2 move if it is O
        if(symbols[player] == 'O')
        {
            printf("It is player two's turn. Please enter a row and a column: ");
            scanf("%d %d", &row, &col);
        }

        //If position is already filled, ask to make a move again
        if (!makeMove(gameBoard, row, col, player)) 
        {
            printf("Invalid move please try again\n");
            continue;
        }

        //Check if the game is finished
        result = checkForWinner(gameBoard);

        if (result != 0) 
        {
            break;
        }

        //Ask the next player to make a move
        player = (player + 1) % PLAYERS;
    }

    //Print the result of the board
    printGameBoard(gameBoard);

    if (result == -1)
    {
        printf("Draw!!! Ya'll suck!\n");
    } 

    else 
    {
        if(result == 'X')
        {
            printf("Player one wins!");
        }

        if(result == 'O')
        {
            printf("Player two wins!");
        }
    }

    return 0;
}

