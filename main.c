#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes

//TODO : the next line's inclusion of "structure.h" may be unnecessary → check if its really the case
// #include "structure.h"  // Necessary for building the shapes

int main(){


    char* input_user;       // string storing the user input
    input_user = menu_prompt();
    printf("Your choice: %s\n", input_user);


    /*
     * ↓ test zone, the remaining code is here only to test the func, is not "useful" ↓
     */


    // creating all the shapes and printing them out to see how it works
    Shape *p1 = create_point_shape(10, 15);
    print_shape (p1);

    Shape *p2 = create_point_shape(8, 3);
    print_shape (p2);

    int* ls[] = {p1, p2};
    Shape* myPolygon = create_polygon_shape(ls, 2);
    print_shape(myPolygon);


    return 0;
}