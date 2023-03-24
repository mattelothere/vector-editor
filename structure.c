#include <stdio.h>
#include "structure.h"
#include "stdlib.h"

Point *create_point(int px, int py){
    Point *point = (Point *) malloc(sizeof (Point));
    point-> pos_x = px;
    point-> pos_y = py;

    return point;
}
void delete_point(Point * point){
    free(point);
}
void print_point(Point * p){
    printf("POINT %d %d\n", p->pos_x , p->pos_y);
}

Line *create_line(Point * p1, Point * p2){
    Line *line = (Line *) malloc(sizeof (Line));
    line->p1->pos_x = p1->pos_x;
    line->p1->pos_y = p1->pos_y;
    line->p2->pos_x = p2->pos_x;
    line->p2->pos_y = p2->pos_y;
    return line;
}
void delete_line(Line * line){
    free(line);
}
void print_line(Line * line){
    printf("LINE %d %d %d %d", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}
