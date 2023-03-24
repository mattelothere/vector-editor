#include <stdio.h>
#include "menu.h"
#include "shapes.h"
#include "structure.h"
int main(){

    char* input_user;

    printf("Welcome to Vector-Editor \n");
    //input_user = menu_prompt();
    Shape *f1 = create_line_shape (10, 15, 21, 25);
    print_shape (f1);



    return 0;
}