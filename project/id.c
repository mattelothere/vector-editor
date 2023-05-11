#include "id.h"

unsigned int global_id = 0;     // defining a global variable "global_id", which is incremented each time we add a new
                                // object(layer or shape) to the program. It is initialized to 0.

unsigned int get_next_id(){     // takes the current value of global_id, increments it by 1, and returns i. The value
    global_id++;                // of global_id is changed at the end of the execution.
    return global_id;
}