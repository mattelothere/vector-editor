#ifndef MENU_H
#define MENU_H

char* main_menu_prompt();
void print_menu(char* menuPrompt);
int isInputValid(char* acceptedInput[], int n_acceptedInputs, char* userInput);


#endif
