//
// Created by Cam on 03/05/2023.
//
#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>

#include "shapes.h"


#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

Pixel* create_pixel(int px, int py){
    Pixel * pixel = (Pixel*) malloc(sizeof(Pixel));
    pixel->px = px;
    pixel->py = py;
    return pixel;
}
void delete_pixel(Pixel* pixel){
    free(pixel);
}

//TODO: not tested
void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels)
{
    Point* pt = (Point*) shape->ptrShape;
    pixel[*nb_pixels] = create_pixel(pt->pos_x, pt->pos_y);
    (*nb_pixels)++;
}


//TODO
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels) {
    int xa = line->p1->pos_x;
    int ya = line->p1->pos_y;
    int xb = line->p2->pos_x;
    int yb = line->p2->pos_y;
    int dx, dy, dmin, dmax, nb_segs, base, remaining, X, Y, j;
    if (line->p1->pos_x > line->p2->pos_x) {
        xa = line->p2->pos_x;
        ya = line->p2->pos_y;
        xb = line->p1->pos_x;
        yb = line->p1->pos_y;
    }
    dx = xb - xa;
    dy = yb - ya;
    dmin = MIN(dx, abs(dy));
    dmax = MAX(dx, abs(dy));
    nb_segs = dmin + 1;
    base = ((dmax + 1) / (dmin +1));
    int *segments = (int*) malloc(nb_segs*sizeof(int));
    for(int i = 0; i< nb_segs; i++){
        segments[i] = base;
    }
    remaining = (dmax + 1) % (dmin +1 );
    int *cumuls = (int*)malloc(nb_segs*sizeof(int));
    cumuls[0] = 0;
    for (int i = 1; i < nb_segs; i++){
        cumuls[i] = ((i*remaining)%(dmin+1) < (i-1)*remaining)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }
    X = xa;
    Y = ya;
    for (int i = 0; i <= nb_segs-1; i++) {
        if (dy < 0) {
            if (dx > abs(dy)) {
                for (j = 0; j < segments[i]; j++) {
                    pixel[*nb_pixels] = create_pixel(X, Y);
                    X++;
                    (*nb_pixels)++;
                }
                Y--;
            }
            else {
                for (j = 0; j < segments[i]; j++){
                    pixel[*nb_pixels] = create_pixel(X, Y);
                    Y--;
                    (*nb_pixels)++;
                }
                X++;
            }
        }
        else {
            if (dx > dy) {
                for (j = 0; j < segments[i]; j++){
                    pixel[*nb_pixels] = create_pixel(X, Y);
                    X ++;
                    (*nb_pixels)++;
                }
                Y++;
            }
            else {
                for (j = 0; j < segments[i]; j++){
                    pixel[*nb_pixels] = create_pixel(X, Y);
                    Y ++;
                    (*nb_pixels)++;
                }
                X++;
            }
        }
    }
}

void pixel_circle(Circle* circle, Pixel** pixel, int*nb_pixels){
    int x = 0;
    int y = circle->radius;
    int d = circle->radius-1;
    Pixel *pix = NULL;
    while (y>=x) {
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x + x, circle->p->pos_y + y);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x + y, circle->p->pos_y + x);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x - x, circle->p->pos_y + y);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x - y, circle->p->pos_y + x);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x + x, circle->p->pos_y - y);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x + y, circle->p->pos_y - x);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x - x, circle->p->pos_y - y);
        (*nb_pixels)++;
        pixel[*nb_pixels] = create_pixel(circle->p->pos_x - y, circle->p->pos_y - x);
        (*nb_pixels)++;
        if (d >= 2*x) {
            d -= 2*x + 1;
            x++;
        }
        else if (d >= 2*(circle->radius-y)) {
            d += 2*y - 1;
            y --;
        }
        else {
            d += 2*(y - x - 1);
            y --;
            x ++;
        }
    }
}

void pixel_square(Square* square, Pixel** pixel, int* nb_pixels){
    int k = 0;

    Shape* line_1 = create_line_shape(square->p->pos_x, square->p->pos_y, square->p->pos_x, square->p->pos_y + square->length);
    pixel_line(line_1->ptrShape, pixel, nb_pixels);
    Shape* line_2 = create_line_shape(square->p->pos_x, square->p->pos_y + square->length, square->p->pos_x + square->length, square->p->pos_y + square->length);
    pixel_line(line_2->ptrShape, pixel, nb_pixels);
    Shape * line_3 = create_line_shape(square->p->pos_x + square->length, square->p->pos_y, square->p->pos_x + square->length, square->p->pos_y + square->length);
    pixel_line(line_3->ptrShape, pixel, nb_pixels);
    Shape* line = create_line_shape(square->p->pos_x, square->p->pos_y, square->p->pos_x + square->length, square->p->pos_y);
    pixel_line(line->ptrShape, pixel, nb_pixels);
}

void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels){
    Shape* line_1 = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y, rectangle->p->pos_x, rectangle->p->pos_y + rectangle->width);
    pixel_line(line_1->ptrShape, pixel, nb_pixels);
    Shape* line_2 = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y + rectangle->width, rectangle->p->pos_x + rectangle->height, rectangle->p->pos_y + rectangle->width);
    pixel_line(line_2->ptrShape, pixel, nb_pixels);
    Shape* line_3 = create_line_shape(rectangle->p->pos_x + rectangle->height, rectangle->p->pos_y, rectangle->p->pos_x + rectangle->height, rectangle->p->pos_y + rectangle->width);
    pixel_line(line_3->ptrShape, pixel, nb_pixels);
    Shape * line = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y, rectangle->p->pos_x + rectangle->height, rectangle->p->pos_y);
    pixel_line(line->ptrShape, pixel, nb_pixels);
}
void pixel_polygon(Polygon* polygon, Pixel** pixel, int* nb_pixels){

    for(int i =0; i<(polygon->n-1)/2; i++){
        Shape* line = create_line_shape(polygon->points[i]->pos_x, polygon->points[i]->pos_y, polygon->points[i+1]->pos_x, polygon->points[i+1]->pos_y);
        pixel_line(line->ptrShape, pixel, nb_pixels);
    }
}

Pixel** create_shape_to_pixel(Shape * shape,int* nb_pixels){
    Pixel** pixel = (Pixel**) malloc(400 * sizeof (Pixel*));
    *nb_pixels = 0;
    switch (shape->shape_type) {
        case POINT:
            pixel_point(shape, pixel, nb_pixels);
            break;
        case LINE:
            pixel_line(shape->ptrShape, pixel, nb_pixels);
            break;
        case SQUARE:
            pixel_square(shape->ptrShape, pixel, nb_pixels);
            break;
        case RECTANGLE:
            pixel_rectangle(shape->ptrShape, pixel, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle(shape->ptrShape, pixel, nb_pixels);
            break;
        case POLYGON:
            pixel_polygon(shape->ptrShape, pixel, nb_pixels);
            break;
    }

    return pixel;
}