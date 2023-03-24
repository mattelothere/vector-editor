#include <stdio.h>
#include "menu.h"

char* menu_prompt(){
    char* input_user;

    printf("Enter help for help\n");
    scanf("%s", input_user);

    return input_user;
}