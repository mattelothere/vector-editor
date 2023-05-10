#ifndef MENU_H
#define MENU_H
#include "shapes.h"
char* main_menu_prompt();
void print_menu(char* menuPrompt);
int isInputValid(char* acceptedInput[], int n_acceptedInputs, char* userInput);

void showHelp();
int add_a_shape(Shape** allShapesList, int nShapes);
void display_all_shapes(Shape** allShapesList, int nShapes);

#endif
