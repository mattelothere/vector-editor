//
// Created by matte on 10/05/2023.
//
#include "command.h"
#include "area.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void print_help(){
    printf("Here are the available commands:\n");
    printf("- clear: Clears the drawing area.\n");
    printf("- exit: Closes the program.\n");
    printf("- point x y: Adds a point shape at coordinates (x, y).\n");
    printf("- line x1 y1 x2 y2: Adds a line shape from (x1, y1) to (x2, y2).\n");
    printf("- circle x y r: Adds a circle shape with center (x, y) and radius r.\n");
    printf("- square x y side: Adds a square shape with top-left corner (x, y) and side length.\n");
    printf("- rectangle x y width height: Adds a rectangle shape with top-left corner (x, y), width, and height.\n");
    printf("- polygon x1 y1 x2 y2 ... xn yn: Adds a polygon shape with vertices (x1, y1), (x2, y2), ..., (xn, yn).\n"
           "The last point should be the same as the first to close the polygon.\n");
    printf("- plot: Displays the drawing area with pixels.\n");
    printf("- list: Lists all shapes in the drawing area.\n");
    printf("- delete id: Deletes the shape with the specified ID.\n");
    printf("- erase: Erases the entire drawing area.\n");
    printf("- help: Displays this help message.\n");
    printf("\nPlease enter a command or type 'help' to see this list again.\n");

}

Command* create_command(){
    Command* command = (Command*) malloc(sizeof(Command));
    command->str_size = 0;
    command->int_size =0;
    return command;
}

void add_str_param(Command* cmd, char* p){
    int i = 0;
    while (p[i] != '\0'){
        cmd->str_params[cmd->str_size][i] = p[i];
    }
    cmd->str_size++;

}

void add_int_param(Command* cmd, int p){
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command* cmd){
    free(cmd);  // TODO : check if this is enough to free up the memory
}

/*
 * Returns 1 if a command has been executed with no errors
 * 0 in some other cases to stop the program's execution
 */
int read_exec_command(Command* cmd, Area* area, int* nb_pixel){
    Shape* shp; // inti shp for all shape created in the if else
    BOOL access = 1; // variable that will allow to pass certain "if"
    if (strcmp(cmd->name, "clear\n") == 0) {  // print lots of \n to emulate $cls
        int HEIGHT = 70; // TODO : take the HEIGHT const from command.h
        clear_area(area);
        for (int i = 0; i < HEIGHT; i++){
            printf("\n");
        }
    } else if (strcmp(cmd->name, "exit\n") == 0) {
        // close the program
        printf("See ya !\n");
        return 0; // scan for 0 in main.c to exit the loop
    } else if (strcmp(cmd->name, "point") == 0 && (cmd->int_params[0] <= SCREEN_HEIGHT  &&  cmd->int_params[0] > 0) && (cmd->int_params[1] <= SCREEN_WIDTH  &&  cmd->int_params[1] > 0) && (cmd->int_size == 2)) {
        add_shape_to_area(
                area,
                create_point_shape(cmd->int_params[0], cmd->int_params[1])
        );
        return 1;
    } else if (strcmp(cmd->name, "line") == 0 && cmd->int_size == 4) {
        for (int i = 0; i< cmd->int_size; i += 2){
            if ( ((cmd->int_params[i] <= SCREEN_HEIGHT  &&  cmd->int_params[i] > 0) && (cmd->int_params[i+1] <= SCREEN_WIDTH  &&  cmd->int_params[i+1] > 0)) == 0 ) {
                access = 0;
            }
        }
        if(access) {
            add_shape_to_area(
                    area,
                    create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3])
            );
            return 1;
        } else{
            printf("Error type again");
        }
    } else if (strcmp(cmd->name, "circle") == 0 && (cmd->int_params[0] + cmd->int_params[2] <= SCREEN_HEIGHT  &&  cmd->int_params[0] > 0) &&
    (cmd->int_params[1] + cmd->int_params[2]<= SCREEN_WIDTH  &&  cmd->int_params[1] > 0) && (cmd->int_size == 3) ) {
        add_shape_to_area(
                area,
                create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2])
        );
        return 1;
    } else if (strcmp(cmd->name, "square") == 0 && (cmd->int_params[0] + cmd->int_params[2] <= SCREEN_HEIGHT  &&  cmd->int_params[0] > 0) &&
               (cmd->int_params[1] + cmd->int_params[2]<= SCREEN_WIDTH  &&  cmd->int_params[1] > 0) && (cmd->int_size == 3)) {
        add_shape_to_area(
                area,
                create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2])

        );
        return 1;
    } else if (strcmp(cmd->name, "rectangle") == 0 && (cmd->int_params[0] + cmd->int_params[2] <= SCREEN_HEIGHT  &&  cmd->int_params[0] > 0) &&
               (cmd->int_params[1] + cmd->int_params[3]<= SCREEN_WIDTH  &&  cmd->int_params[1] > 0) && (cmd->int_size == 4)) {
        add_shape_to_area(
                area,
                create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3])
        );
        return 1;
    } else if (strcmp(cmd->name, "polygon") == 0 && cmd->int_size%2 == 0 && (cmd->int_params[0] == cmd->int_params[cmd->int_size-2]) && (cmd->int_params[1] == cmd->int_params[cmd->int_size-1])) {
        for (int i = 0; i< cmd->int_size; i += 2){
            if ( ((cmd->int_params[i] <= SCREEN_HEIGHT  &&  cmd->int_params[i] > 0) && (cmd->int_params[i+1] <= SCREEN_WIDTH  &&  cmd->int_params[i+1] > 0)) == 0 ) {
                access = 0;
            }
        }
        if(access) {
            add_shape_to_area(
                    area,
                    create_polygon_shape(cmd->int_params, cmd->int_size)
            );
            return 1;
        }
    } else if (strcmp(cmd->name, "plot\n") == 0) {
        draw_area(area, nb_pixel);
        print_area(area);
    } else if (strcmp(cmd->name, "list\n") == 0 && area->nb_shape != 0) {
        for (int i = 0; i<area->nb_shape; i++){
            print_shape(area->shapes[i]);
        }
    } else if (strcmp(cmd->name, "delete") == 0) {
        int deleted_id = 0;
        for (int i = 0; i<area->nb_shape; i++){
            if (area->shapes[i]->id == cmd->int_params[0]) {    // if asked_id == shape's id
                deleted_id = i;
                for (int j = deleted_id; j < area->nb_shape; j++){
                    area->shapes[j] = area->shapes[j+1];
                }
                area->nb_shape -= 1;
            }
        // shift all ptrs to the shapes
        }
        // area now has n-1 shapes

    } else if (strcmp(cmd->name, "erase\n") == 0) {
        delete_area(area);
    } else if (strcmp(cmd->name, "help\n") == 0) {
        print_help();
    } else {
        printf("Error : couldn't interpret the command : %s"
               "Please try again, (type 'help' to list all commands)\n", cmd->name); 
    }
}





void read_from_stdin(Command* cmd){
    printf("---->\n");
    char usr_input[100];
    fgets(usr_input, 100, stdin);
    char separator[] = " ";
    char* token;
    int n_token = 0;
    token = strtok(usr_input, separator);
    do{
        int value;

        if (sscanf(token, "%d", &value) == 0 && n_token == 0) {     // token is not an int + no tokens taken yet
            strcpy(cmd->name, token);
        }
        else if (sscanf(token, "%d", &value) == 0 && n_token != 0) {    // token is not an int + token already parsed
            add_str_param(cmd, token);
        }
        else {  // token is an int
            int int_token = 0;
            sscanf(token, "%d", &int_token);    // cast the token to an int
            add_int_param(cmd, int_token);
        }
        n_token++;
        token = strtok(NULL, " ");  // take the next token (look at strtok documentation)

    }while(token != NULL);
}


