#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes
#include <string.h>

int main(){

    /*
     * Put here the code that initializes stuff used in the future
     */
    char* userInput = NULL;
    int looping = 1;

    do {
        userInput = main_menu_prompt();
        if (strcmp(userInput, "A") == 0){
            // call add a shape
            printf("DEBUG: ADDING A SHAPE\n");
        }else if (strcmp(userInput, "B") == 0){
            // call displayShapeList
            printf("DEBUG: DISPLAY ALL SHAPES\n");
        }else if (strcmp(userInput, "Help") == 0 || strcmp(userInput, "help") == 0){
            // call show help
            printf("DEBUG: SHOWING HELP\n");
        }else if (strcmp(userInput, "Quit") == 0){
            looping = 0;
        }
    } while (looping);


    /*
     * ↓ test zone, the remaining code is here only to test the func, is not "useful" ↓
     */




    /*
     * Put here the code that cleans up everything
     */
    printf("MAIN.C END REACHED : Bye !");
    return 0;
}