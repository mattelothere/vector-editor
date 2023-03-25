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
    Shape* myPoint = create_point_shape(1, 2);
    print_shape(myPoint);


    Shape* myLine = create_line_shape(2, 5, 3, 7);
    print_shape(myLine);

    Shape* mySquare = create_square_shape(11, 13, 3);
    print_shape(mySquare);

    Shape* myRectangle = create_rectangle_shape(2,3, 2, 5);
    print_shape(myRectangle);

    Shape* myCircle = create_circle_shape(2, 0, 3);
    print_shape(myCircle);

    int ls[] = {1,2,3,5,6,4};
    Shape* myPolygon = create_polygon_shape(ls, 3);
    print_shape(myPolygon);


    return 0;
}