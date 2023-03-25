#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


// TODO : maybe its better to define menu_prompt() as a void func, which changes the value of input_user using a ptr ?
// and returns nothing,
// because as of now, we have redundancy of the char* variable "input_user"

char* menu_prompt(){
    char* input_user = (char*) malloc(4*sizeof(char));     // init to error in order to be detectable

    printf("------ Welcome to Vector-Editor ------\n");

    // https://stackoverflow.com/questions/1752079/in-c-can-a-long-printf-statement-be-broken-up-into-multiple-lines
    // whitespace between two strings equals concatenation of strings
    printf(">Enter 'help' for help\n"
           ">Please select an action:\n"
           "\t|A- Add a shape\n"
           "\t|B- Display the list of shapes\n"
           "\t"
           "|(...)\n"
           "\n"
           "~> ");


    scanf("%s", input_user);    //TODO: isn't better to use fgets or gets, "because its more secure" or whatever?
    return input_user;
}