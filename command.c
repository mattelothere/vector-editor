//
// Created by matte on 10/05/2023.
//
#include "command.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "area.h"

Command* create_command(){
    Command* command = (Command*) malloc(sizeof(Command));
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
 * Returns 1 if a shape has been created
 */
int read_exec_command(Command* cmd, Area* area){
    Shape* shp; // inti shp for all shape created in the if else
    if (strcmp(cmd->name, "clear") == 0) {  // print lots of \n to emulate $cls
        int HEIGHT = 70; // TODO : take the HEIGHT const from command.h
        for (int i = 0; i < HEIGHT; i++){
            printf("\n");
        }
    } else if (strcmp(cmd->name, "exit") == 0) {    // close the program
        // shot
    } else if (strcmp(cmd->name, "point") == 0) {
        add_shape_to_area(
                area,
                create_point_shape(cmd->int_params[0], cmd->int_params[1])
                );
        return 1;

    } else if (strcmp(cmd->name, "line") == 0) {
        add_shape_to_area(
                area,
                create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3])
                );
        return 1;

    } else if (strcmp(cmd->name, "circle") == 0) {
        add_shape_to_area(
                area,
                create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2])
        );
        return 1;
    } else if (strcmp(cmd->name, "square") == 0) {
        add_shape_to_area(
                area,
                create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2])

        );
        return 1;
    } else if (strcmp(cmd->name, "rectangle") == 0) {
        add_shape_to_area(
                area,
                create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3])
        );
        return 1;
    } else if (strcmp(cmd->name, "polygon") == 0) {
        add_shape_to_area(
                area,
                create_polygon_shape(cmd->int_params, cmd->int_size)
        );
        return 1;


    } else if (strcmp(cmd->name, "plot") == 0) {
        draw_area(area);    // todo : change parameters
        print_area(area);
    } else if (strcmp(cmd->name, "list") == 0) {
        for (int i = 0; i<area->nb_shape; i++){
            print_shape(area->shapes[i]);
        }
    } else if (strcmp(cmd->name, "delete") == 0) {
        int deleted_id;
        for (int i = 0; i<area->nb_shape; i++){
            if (area->shapes[i]->id == cmd->int_params[0]) {    // if asked_id == shape's id
                deleted_id = i;
            }
        }

        for (int j = deleted_id; j < area->nb_shape; j++){
            area->shapes[j] = area->shapes[j+1]; // shift all ptrs to the shapes
        }
        area->nb_shape -= 1;    // area now has n-1 shapes

    } else if (strcmp(cmd->name, "erase") == 0) {
        delete_area(area);
    } else if (strcmp(cmd->name, "help") == 0) {
        printf("Ouais c'est greg \n"); //todo relink to print_help function
    } else {
        printf("Retape la commande sagouin\n"); // todo : use a better language
    }
}

void read_from_stdin(Command* cmd){
    printf("type a line\n");
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
            cmd->str_params[cmd->str_size] = token;
            cmd->str_size ++;
        }
        else {  // token is an int
            int int_token = 0;
            sscanf(token, "%d", &int_token);    // cast the token to an int
            cmd->int_params[cmd->int_size] = int_token;
            cmd->int_size ++;
        }
        n_token++;
        token = strtok(NULL, " ");  // take the next token (look at strtok documentation)

    }while(token != NULL);
}
