#ifndef SHAPES_H
#define SHAPES_H

#include "pixel.h"
/*              ----------SHAPES----------                  *
 * Module composed of shapes.c and shapes.h files.          *
 * This module will group the structured types of each shape*
 * as well as the associated functions: creation, display   *
 * and destruction                                          *
 *              --------------------------                  */



/*
 *  Definition of the structured types
 */

typedef enum {POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct shape {
    unsigned int id; // unique identifier of the shape
    SHAPE_TYPE shape_type; // type of the shape pointed
    void *ptrShape; // pointer to any shape
}Shape;





/*
 * prototypes of the funcs creating the shapes
 */

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int lst[], int n);


/*
 * prototypes of the funcs for manipulating the shapes
 */

void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif