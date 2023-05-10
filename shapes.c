#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"
#include "structure.h"
#include "id.h"


                        /*              ----------SHAPES----------                  *
                         * Module composed of shapes.c and shapes.h files.          *
                         * This module will group the structured types of each shape*
                         * as well as the associated functions: creation, display   *
                         * and destruction                                          *
                         *              --------------------------                  */





/*
 * definition of the funcs creating the shapes
 */


// This function is only used in other functions and the user should not interact with it.
    // The idea is to create an empty shape of varying size (a rect takes more memory space than a point)
// and then modify the fields of this new empty shape accordingly with the parameters of the corresponding
// shapes' create_XXXXX_shape() func.
Shape *create_empty_shape(SHAPE_TYPE shape_type){
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py){
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}
Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *line = create_line(p1, p2);
    shp->ptrShape = line;
    return shp;
}
Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *square = create_square(p, length);
    shp->ptrShape = square;
    return shp;
}
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    return shp;
}
Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *circle = create_circle(p, radius);
    shp->ptrShape = circle;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
    if ((n%2 == 0) && (lst[0] == lst[n-2]) && (lst[1] == lst[n-1])) {   //check if the number of coordinates if pair, then if the polygon is closed
        Shape *shp = create_empty_shape(POLYGON);
        Polygon *polygon = create_polygon(n);
        for(int i = 0; i<n; i += 2){        // if we need to cancel the last point, increment n by 2
            Point *p = create_point(lst[i], lst[i+1]);
            polygon->points[i/2] = p;
        }
        shp->ptrShape = polygon;
        return shp;
    }
    return NULL;






/*
 * definition of the funcs for manipulating the shapes
 */


}
void delete_shape(Shape * shape){
    free(shape);
}


void print_shape(Shape * shape) {    // print the id then in function of the shape type it call the print needed

    printf("ID : %d | ", shape->id);
    switch (shape->shape_type) {
        case 0:
            print_point(shape->ptrShape);
            break;
        case 1:
            print_line(shape->ptrShape);
            break;
        case 2:
            print_square(shape->ptrShape);
            break;
        case 3:
            print_rectangle(shape->ptrShape);
            break;
        case 4:
            print_circle(shape->ptrShape);
            break;
        case 5:
            print_polygon(shape->ptrShape);
            break;
    }


}