//
// Created by matte on 10/05/2023.
//
#include "command.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

}

int read_exec_command(Command* cmd){

}

void read_from_stdin(Command* cmd){
    printf("type a line\n");
    char usr_input[100];
    fgets(usr_input, 100, stdin);

    char separator[] = " ";
    char* token;

    token = strtok(usr_input, separator);
    strcpy(cmd->name, token);   // first token is the name of the command
    do{
        printf("%s\n", token);
        token = strtok(NULL, separator);

        // TODO : check if sscanf(%d, ...) returns >0 => the token is an int => put it in int_params
        // using the prev coded func
        //        if (){
//            is_an_int = sscanf(...)
//        }


    }while(token != NULL);




}