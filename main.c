#include <stdio.h>
#include "menu.h"
#include "shapes.h"
#include "structure.h"
int main(){

    char* input_user;

    printf("Welcome to Vector-Editor \n");
    input_user = menu_prompt();
    Point * p1 = create_point (88, 15);
    Point * p2 = create_point (21, 44);
    Line * l = create_line (p1 ,p2);
    print_line (l);
    delete_line(l);
    delete_point(p1);
    delete_point(p2);


    return 0;
}