#!/bin/bash

# Infinitely loop through the process until game is completed
while true; do

    #Randomly choose a vertical position on the board
    verticalPosition=$((RANDOM % 3 + 1))

    #Randomly choose a horizontal positon on the board
    horizontalPosition=$((RANDOM % 3 + 1))
    

    #Call the make move function from the tic tac toe program
    makeMove $horizontalPosition $verticalPosition

done