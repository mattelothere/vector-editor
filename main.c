#include <stdio.h>
#include "menu.h"
#include "shapes.h"
#include "structure.h"
int main(){

    char* input_user;

    printf("Welcome to Vector-Editor \n");
    //input_user = menu_prompt();
    Point * p = create_point(8, 54);
    Circle * c = create_circle(p, 8);
    print_circle(c);
    delete_circle(c);



    return 0;
}