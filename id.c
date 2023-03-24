#include "id.h"

unsigned int global_id = 0;
unsigned int get_next_id(){
    global_id++;
    return global_id;
}