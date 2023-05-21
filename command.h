//
// Created by matte on 10/05/2023.
//

#ifndef VECTOR_EDITOR_COMMAND_H
#define VECTOR_EDITOR_COMMAND_H

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 60

#include "area.h"

struct command {
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
};
typedef struct command Command;

Command* create_command();
void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd, Area* area, int* nb_pixel);    // diff from instructions Added area param
void read_from_stdin(Command* cmd);


#endif //VECTOR_EDITOR_COMMAND_H
