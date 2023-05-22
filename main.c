#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes
#include <string.h>
#include <stdlib.h>
#include "command.h"

void print_title(){
    printf("\n");
    printf("     __   __ _____ ____ _____ ____  ____  ___ _____  ___   ___  \n");
    printf("     \\ \\  / | |_  / /`   | |  | |_  | | \\ | |  | |  / / \\ | |_) \n");
    printf("      \\_\\/  |_|__ \\_\\_,  |_|  |_|__ |_|_/ |_|  |_|  \\_\\_/ |_| \\ \n");
    printf("\n");

    printf("Type a command to start, or 'help' to display the list of them all \n");
}

#define AREA_WIDTH 25
#define AREA_HEIGHT 25

int main(){

    print_title();


    BOOL running = 1;   // init running var to True, to enter the main loop
    Area* area = create_area(AREA_WIDTH, AREA_HEIGHT);
    clear_area(area);
    int nb_pixel = 0;
    while (running) {   // main program loop
        Command* myCommand = create_command();
        read_from_stdin(myCommand);
        running = read_exec_command(myCommand, area, &nb_pixel);    // fetch output of read_exec

    }

    return 0;
}

