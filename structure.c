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
    line->p1 = p1;
    line->p2 = p2;
    return line;
}
void delete_line(Line * line){
    free(line);
}
void print_line(Line * line){
    printf("LINE %d %d %d %d", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}

Square *create_square(Point * point, int length){
    Square *square = (Square *) malloc(sizeof (Square));
    square->p = point;
    square->lenght = length;
    return square;
}
void delete_square(Square * square){
    free(square);
}
void print_square(Square * square) {
    printf("SQUARE %d %d %d", square->p->pos_x, square->p->pos_y, square->lenght);
}

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *rectangle = (Rectangle *) malloc(sizeof (Rectangle));
    rectangle->p = point;
    rectangle->lenght = height;
    rectangle->width = width;
    return rectangle;
}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}
void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE x =%d y =%d Height: %d Width: %d\n", rectangle->p->pos_x, rectangle->p->pos_y, rectangle->lenght, rectangle->width);
}


Circle *create_circle(Point * center, int radius){
    Circle *circle = (Circle *) malloc(sizeof (Circle));
    circle->p = center;
    circle->radius = radius;
}
void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    printf("CIRCLE x = %d y = %d radius = %d\n", circle->p->pos_x, circle->p->pos_y, circle->radius);
}


Polygon *create_polygon(int n){
    Polygon * polygon = (Polygon *) malloc(sizeof (Polygon));
    polygon->n = n;


}
void delete_polygon(Polygon * polygon){
    free(polygon);
}
void print_polygon(Polygon * polygon){
    printf("POLYGON");
}
