#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

#define MAX_INPUT_LENGTH 256    // this is the maximum length the user's input can measure

/*
 * The purpose of this file is to list all the code useful to the display of the menu,
 * and the user interaction with it.
 */

#define first_menu ">Enter 'help' for help\n>Please select an action:\n\t|A- Add a shape\n\t|B- Display the list of shapes\n~>"


/*
 * Function reads the string stored at menu_prompt, and then printf it
 */
void print_menu(char* menuPrompt){
    printf("%s", menuPrompt);
}

char* acceptedInputs[] = {"A", "B", "Quit", "Help"};
int n_acceptedInputs = 4;




int isInputValid(char* acceptedInput[], int n_acceptedInput, char* userInput){
    // takes the input given by the user, and returns 1 if it is part of the accepted Inputs, 0 otherwise
    int is_valid = 0;

    // compare every string of the array of strings acceptedInputs and see if userInput
    int i = 0;
    while (i<n_acceptedInput && is_valid == 0){     // while there are more possibilities to check then
        if (strcmp(acceptedInput[i], userInput) == 0)   // == 0 means the two strings are the same
            is_valid = 1;
        i++;
    }
    return is_valid;
}





char* main_menu_prompt(){

    char* userInput = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));
    // userInput prompt loop
    int badInput = 0;   // by default the input is not wrong
    do {
        printf("\n");   // additional print for spacing and clarity
        print_menu(first_menu);
        fgets(userInput, MAX_INPUT_LENGTH + 1, stdin);     //fgets reads (size - 1) characters
        // remove ending \n
        int len = strlen(userInput);
        if (len < MAX_INPUT_LENGTH){    // if the f-got string has length < max_size, then the last '\n' char has been
            userInput[len-1] = '\0';   // taken into account, meaning we have to remove it (index len-1)
        }
        else{
            fflush(stdin);      // in contrary, we have to clear what is left in the buffer and re-ask the input
            badInput = 1;
        }

    } while (badInput);

    return userInput;
}

void showHelp(){
    printf("print 'Quit' to quit, 'help' to show this prompt\n"
           "else type in the first letter of the available choices\n");
    printf("\n");   // additional print for spacing and clarity
}

int add_a_shape(Shape** allShapesList, int nShapes){
    int validShape = 1;
    Shape* myShape = NULL;
    printf("What shape do u want to add\n");
    printf("P- point x y\n"
           "L- line x1 y1 x2 y2\n"
           "C- circle x y radius\n"
           "S- square x y length\n"
           "R- rectangle x y width height\n");
    char user_input;
    scanf("%c", &user_input);
    if (user_input == 'P'){
        int x, y;
        printf("Enter x:");
        scanf("%d", &x);
        printf("Enter y:");
        scanf("%d", &y);
        Shape* myShape = create_point_shape(x, y); //placeholder, will change later
    }else if(user_input == 'L'){
        int x, y;
        int x2, y2;
        printf("Enter x1:");
        scanf("%d", &x);
        printf("Enter y1:");
        scanf("%d", &y);
        printf("Enter x2:");
        scanf("%d", &x2);
        printf("Enter y2:");
        scanf("%d", &y2);
        Shape* myShape = create_line_shape(x, y, x2, y2);
    }else if(user_input == 'C'){
        int x, y, r;
        printf("Enter x");
        scanf("%d", &x);
        printf("Enter y");
        scanf("%d", &y);
        printf("Enter r(adius)");
        scanf("%d", &r);
        Shape* myShape = create_circle_shape(x, y, r);
    }else if(user_input == 'S'){
        int x, y, l;
        printf("Enter x");
        scanf("%d", &x);
        printf("Enter y");
        scanf("%d", &y);
        printf("Enter l(ength)");
        scanf("%d", &l);
        Shape* myShape = create_square_shape(x, y, l);
    }else if(user_input == 'R'){
        int x, y, w, h;
        printf("Enter x");
        scanf("%d", &x);
        printf("Enter y");
        scanf("%d", &y);
        printf("Enter w(idth)");
        scanf("%d", &w);
        printf("Enter h(eight)");
        scanf("%d", &h);
        Shape* myShape = create_rectangle_shape(x, y, w, h);
    }else{
        printf("The shape u want to add is not available\n");
        validShape = 0;
    }
    if (validShape == 1){
        allShapesList = realloc(allShapesList, (nShapes+1)*sizeof(Shape*));
        allShapesList[nShapes] = myShape;
        printf("\n");
        return 0;
    }else{
        return 1;
    }
}

void display_all_shapes(Shape** allShapes, int nShapes){
    int i = 0;
    while (i < nShapes){
        print_shape(allShapes[i]);
        i++;
    }
    if (i==0){
        printf("There are no shapes yet\n");
    }

}

