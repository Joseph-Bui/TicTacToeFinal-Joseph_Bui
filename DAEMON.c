#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void checkForSignal()
{
    while (1) 
    {
        
        //Check for the start variable from the esp32
        char* start = getenv("START");

        if (start != NULL) 
        {

            //initiate the tic tac toe game
            //if the variable is recognized
            system("./tictactoe");

            //clear the start variable
            setenv("START", "", 1);

        } 
        
        else 
        {

            //Check again every few seconds
            sleep(60);

        }
    }
}

int main()
{

    // ignore any termination signals
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    //call the daemon function
    checkForSignal();

    return 0;

}