#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes
#include <string.h>
#include <stdlib.h>
#include "command.h"

void print_title(){
    printf("__________.__                              __________        .__                      .___      \n");
    printf("\\______   \\__| __________________   ____   \\______   \\_____  |  |   _____ _____     __| _/____  \n");
    printf(" |     ___/  |/ __ \\_  __ \\_  __ \\_/ __ \\   |     ___/\\__  \\ |  |  /     \\\\__  \\   / __ |/ __ \\ \n");
    printf(" |    |   |  \\  ___/|  | \\/|  | \\/\\  ___/   |    |     / __ \\|  |_|  Y Y  \\/ __ \\_/ /_/ \\  ___/ \n");
    printf(" |____|   |__|\\___  >__|   |__|    \\___  >  |____|    (____  /____/__|_|  (____  /\\____ |\\___  >\n");
    printf("                  \\/                   \\/                  \\/           \\/     \\/      \\/    \\/ \n");
    printf("Type a command to start, or 'help' to display the list of them all \n");
}

#define AREA_WIDTH 70
#define AREA_HEIGHT 25

int main(){

    print_title();

    BOOL running = 1;   // init running var to True, to enter the main loop
    Area* area = create_area(AREA_WIDTH, AREA_HEIGHT);
    int nb_pixel = 0;
    while (running) {   // main program loop
        Command* myCommand = create_command();
        read_from_stdin(myCommand);
        running = read_exec_command(myCommand, area, &nb_pixel);    // fetch output of read_exec
    }

    printf("MAIN.C END REACHED : Bye !");
    return 0;
}

