#include <stdio.h>
#include "structure.h"
#include "stdlib.h"

                        /*      ---------STRUCTURES---------    *
                         *  This file lists all shapes' structs *
                         *  and the functions associated to them.
                         *  For every shape, we first have the  *
                         *  "create" func, then the "delete",   *
                         *  and finally the "print" func.       *
                         *      ----------------------------    */



/*
 * Point struct
 */

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




/*
 * Line struct, composed of two points
 */

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
    printf("LINE %d %d %d %d\n", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}




/*
 * Square struct, composed of a point (top left corner) and a length
 */

Square *create_square(Point * point, int length){
    Square *square = (Square *) malloc(sizeof (Square));
    square->p = point;
    square->length = length;
    return square;
}
void delete_square(Square * square){
    free(square);
}
void print_square(Square * square) {
    printf("SQUARE %d %d %d\n", square->p->pos_x, square->p->pos_y, square->length);
}




/*
 * Rect struct, represented by a point (top_left corner, width and height)
 */

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *rectangle = (Rectangle *) malloc(sizeof (Rectangle));
    rectangle->p = point;
    rectangle->height = height;
    rectangle->width = width;
    return rectangle;
}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}
void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE x=%d y=%d h:%d w:%d\n", rectangle->p->pos_x, rectangle->p->pos_y, rectangle->height, rectangle->width);
}



/*
 * Circle struct, represented by a point (its center), and a radius
 */

Circle *create_circle(Point * center, int radius){
    Circle *circle = (Circle *) malloc(sizeof (Circle));
    circle->p = center;
    circle->radius = radius;
    return circle;
}
void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    printf("CIRCLE x=%d y=%d r:%d\n", circle->p->pos_x, circle->p->pos_y, circle->radius);
}




/*
 * Polygon struct, not finished
 */
//TODO : finish the implementation of a polygon
Polygon *create_polygon(int n){
    Polygon * polygon = (Polygon *) malloc(sizeof (Polygon));
    polygon->n = n;
    polygon->points = malloc(n/2 * sizeof (Point));
    return polygon;
}
void delete_polygon(Polygon * polygon){
    free(polygon);
}
void print_polygon(Polygon * polygon){
    printf("POLYGON: n=%d,", polygon->n);      //n is the number of "sommets"
    for(int i =0; i< polygon-> n /2; i++){
        printf("point %d x:%d y:%d\n",i+1, polygon->points[i]->pos_x , polygon->points[i]->pos_y);
    }
}
