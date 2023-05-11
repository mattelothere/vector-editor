#ifndef STRUCTURE_H
#define STRUCTURE_H


                /* ----------------------------- *
                 * Definition of the new structs *
                 * ----------------------------- */

typedef struct point {
    int pos_x;
    int pos_y;
}Point;

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

typedef struct square {
    Point *p;
    int length;

}Square;

typedef struct rectangle {
    Point *p;
    int length;
    int width;
}Rectangle;

typedef struct circle {
    Point *p;
    int radius;
}Circle;

typedef struct polygon {
    int n;
    Point ** points;
}Polygon;



        /* --------------------------------------------------------------- *
         * Prototypes of the functions responsible for creating the shapes *
         * --------------------------------------------------------------- */

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif
