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
    pixel[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}


//TODO
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels) {
    int xa = line->p1->pos_x;
    int ya = line->p1->pos_y;
    int xb = line->p2->pos_x;
    int yb = line->p2->pos_y;
    int dx, dy, dmin, dmax, nb_segs, base, remaining;
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
    int *segments = (int*) malloc(base*sizeof(int));
    remaining = (dmax + 1) % (dmin +1 );
    int *cumuls = (int*)malloc(nb_segs*sizeof(int));
    cumuls[0] = 0;
    for (int i = 1; i < nb_segs; i++){
        cumuls[i] = ((i*remaining)%(dmin+1) < (i-1)*remaining)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }
    int k = *nb_pixels,j, X, Y;
    for (int i = 0; i < nb_segs-1; i++) {
        if (dy < 0) {
            if (dx > abs(dy)) {
                for (j = 0; j < segments[i]; j++) {
                    X += j;
                    pixel[k]->px = X;
                    pixel[k]->py = Y;
                    k++;
                }
                Y--;
            }
            else {
                for (j = 0; j < segments[i]; j++) {
                    Y-= j;
                    pixel[k]->px = X;
                    pixel[k]->py = Y;
                    k++;
                }
                X++;
            }
        }
        else {
            if (dx > dy) {
                for (j = 0; j < segments[i]; j++) {
                    X += j;
                    pixel[k]->px = X;
                    pixel[k]->py = Y;
                    k++;
                }
                Y++;
            }
            else {
                for (j = 0; j < segments[i]; j++) {
                    Y += j;
                    pixel[k]->px = X;
                    pixel[k]->py = Y;
                    k++;
                }
                X++;
            }
        }
    }
    *nb_pixels = k;
}

void pixel_circle(Circle* circle, Pixel** pixel, int*nb_pixels){
    int x = 0, k = 0;
    int y = circle->radius;
    int d = circle->radius-1;
    Pixel * px = NULL;
    while (y>=x) {
        px = create_pixel(circle->p->pos_x + x, circle->p->pos_y + y);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x + y, circle->p->pos_y + x);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x - x, circle->p->pos_y + y);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x - y, circle->p->pos_y + x);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x + x, circle->p->pos_y - y);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x + y, circle->p->pos_y - x);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x - x, circle->p->pos_y - y);
        pixel[k++] = px;
        px = create_pixel(circle->p->pos_x - y, circle->p->pos_y - x);
        pixel[k++] = px;
        if (d < 1) {
            x++;
            d += 2 * x + 1;
        } else {
            y--;
            x++;
            d += 2 * x - 2 * y + 2;
        }
    }
}

void pixel_square(Square* square, Pixel** pixel, int* nb_pixels){
    int k = 0;

    Shape* line_1 = create_line_shape(square->p->pos_x, square->p->pos_y, square->p->pos_x, square->p->pos_y + square->length);
    pixel_line(line_1->ptrShape, pixel, nb_pixels);
    Shape* line_2 = create_line_shape(square->p->pos_x, square->p->pos_y + square->length, square->p->pos_x + square->length, square->p->pos_y + square->length);
    pixel_line(line_2->ptrShape, pixel, nb_pixels);
    Shape* line_3 = create_line_shape(square->p->pos_x + square->length, square->p->pos_y, square->p->pos_x + square->length, square->p->pos_y + square->length);
    pixel_line(line_3->ptrShape, pixel, nb_pixels);
    Shape* line = create_line_shape(square->p->pos_x, square->p->pos_y, square->p->pos_x + square->length, square->p->pos_y);
    pixel_line(line->ptrShape, pixel, nb_pixels);
}

void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels){
    Shape* line_1 = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y, rectangle->p->pos_x, rectangle->p->pos_y + rectangle->length);
    pixel_line(line_1->ptrShape, pixel, nb_pixels);
    Shape* line_2 = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y + rectangle->length, rectangle->p->pos_x + rectangle->length, rectangle->p->pos_y + rectangle->length);
    pixel_line(line_2->ptrShape, pixel, nb_pixels);
    Shape* line_3 = create_line_shape(rectangle->p->pos_x + rectangle->length, rectangle->p->pos_y, rectangle->p->pos_x + rectangle->length, rectangle->p->pos_y + rectangle->length);
    pixel_line(line_3->ptrShape, pixel, nb_pixels);
    Shape* line = create_line_shape(rectangle->p->pos_x, rectangle->p->pos_y, rectangle->p->pos_x + rectangle->length, rectangle->p->pos_y);
    pixel_line(line->ptrShape, pixel, nb_pixels);
}

void pixel_polygon(Polygon* polygon, Pixel** pixel, int* nb_pixels){

    for(int i =0; i<polygon->n-1; i++){
        Shape* line = create_line_shape(polygon->points[i]->pos_x, polygon->points[i]->pos_y, polygon->points[i+1]->pos_x, polygon->points[i+1]->pos_y);
        pixel_line(line->ptrShape, pixel, nb_pixels);
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    switch (shape->shape_type) {
        case POINT:

    }
    Pixel** pixel = 0;
    return pixel;
}