#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

#define MAX_INPUT_LENGTH 256    // this is the maximum length the user's input can measure

/*
 * The purpose of this file is to list all the code useful to the display of the menu,
 * and the user interaction with it.
 */




void print_menu(){
    printf(">Enter 'help' for help\n"
           ">Please select an action:\n"
           "\t|A- Add a shape\n"
           "\t|B- Display the list of shapes\n"
           "~>");
}

int isInputValid(char* acceptedInput[], int n_acceptedInputs, char* userInput){
    // takes the input given by the user, and returns 1 if it is part of the accepted Inputs, 0 otherwise
    int is_valid = 0;

    // compare every string of the array of strings acceptedInputs and see if userInput
    for(int i=0; i<n_acceptedInputs; i++){
        if (strcmp(acceptedInput[i], userInput) == 0)   // == 0 means the two strings are the same
            is_valid = 1;
    }
    return is_valid;
}


char* menu_prompt(){

    // whitespace between two strings equals concatenation of strings : https://stackoverflow.com/questions/1752079
    printf("------ Welcome to Vector-Editor ------\n");

    char* userInput = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));
    // userInput prompt loop
    int badInput = 0;   // by default the input is not wrong
    do {
        print_menu();
        fgets(userInput, MAX_INPUT_LENGTH + 1, stdin);     //fgets reads (size - 1) characters
        // remove ending \n
        int len = strlen(userInput);
        if (len < MAX_INPUT_LENGTH){    // if the f-got string has length < max_size, then the last '\n' char has been
            userInput[len-1] = '\0';   // taken into account, meaning we have to remove it (index len-1)
        }
        else{
            fflush(stdin);          // in contrary, we have to clear what is left in the buffer and re-ask the input
            badInput = 1;
        }
    } while (badInput);

    printf("Your choice is: %s\n", userInput);
    return userInput;
}