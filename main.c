#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes
#include <string.h>
#include <stdlib.h>
#include "command.h"

int main(){

    /*
     * Put here the code that initializes stuff used in the future
     */

    /*
     * ↓ test zone, the remaining code is here only to test the func, is not "useful" ↓
     */

    BOOL running = 1;

    Area* area = create_area(10, 10);
    while (running) {
        Command* myCommand = create_command();
        read_from_stdin(myCommand);
        running = read_exec_command(myCommand, area);
    }

    printf("MAIN.C END REACHED : Bye !");
    return 0;
}