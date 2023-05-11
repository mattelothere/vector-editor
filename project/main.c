#include <stdio.h>
#include "menu.h"       // for all functions related to the command-line menu
#include "shapes.h"     // Implementation of all the available shapes
#include <string.h>
#include <stdlib.h>

int main(){

    /*
     * Put here the code that initializes stuff used in the future
     */
    char* userInput = NULL;
    int looping = 1;
    Shape** LIST_OF_ALL_SHAPES = malloc(0*sizeof(Shape*));
    int LIST_SIZE = 0;


    printf("------ Welcome to Vector-Editor ------\n");
    do {
        userInput = main_menu_prompt();
        if (strcmp(userInput, "A") == 0){
            // call add a shape
//            printf("DEBUG: ADDING A SHAPE\n");
            add_a_shape(LIST_OF_ALL_SHAPES, LIST_SIZE);
            LIST_SIZE++;

        }else if (strcmp(userInput, "B") == 0){
            // call displayShapeList
//            printf("DEBUG: DISPLAY ALL SHAPES\n");
            display_all_shapes(LIST_OF_ALL_SHAPES, LIST_SIZE);

        }else if (strcmp(userInput, "Help") == 0 || strcmp(userInput, "help") == 0){
            // call show help
            showHelp();

        }else if (strcmp(userInput, "Quit") == 0){
            looping = 0;
        }
    } while (looping);


    /*
     * ↓ test zone, the remaining code is here only to test the func, is not "useful" ↓
     */
//    printf("START TEST ZONE\n");
//
//    Shape* p1 = create_point_shape(16, 1);
//
//
//
//    LIST_OF_ALL_SHAPES = realloc(LIST_OF_ALL_SHAPES, (LIST_SIZE+1)*sizeof(Shape*));
//    LIST_OF_ALL_SHAPES[LIST_SIZE] = p1;
//    LIST_SIZE++;
//
//    Shape* l1 = create_line_shape(16, 1, 17, 1);
//    LIST_OF_ALL_SHAPES[1] = l1;
//    LIST_SIZE++;
//
//    display_all_shapes(LIST_OF_ALL_SHAPES, LIST_SIZE);



    /*
     * Put here the code that cleans up everything
     */
    printf("MAIN.C END REACHED : Bye !");
    return 0;
}