//
// Created by Cam on 19/04/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pixel.h"
#include "shapes.h"
#include "structure.h"

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

Pixel* create_pixel(int px, int py){
    Pixel* pix = (Pixel *) malloc(sizeof (Pixel));
    pix->py = py;
    pix->px = px;
    return pix;
}



void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_shape(Shape* shape, Pixel** pixel, int* nb_pixels){
    Point* pt = (Point*) shape->ptrShape;
    Pixel** pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}
//TODO
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
    int xa = line->p1->pos_x;
    int ya = line->p1->pos_y;
    int xb = line->p2->pos_x;
    int yb = line->p2->pos_y;
    int dx, dy, dmin, dmax, nb_segs;
    if(line->p1->pos_x > line->p2->pos_x){
        xa = line->p2->pos_x;
        ya = line->p2->pos_y;
        xb = line->p1->pos_x;
        yb = line->p1->pos_y;
    }
    dx = xb - xa;
    dy = yb - ya;
    dmin = MIN(dx, abs(dy));
    dmax = MAX(dx, abs(dy));
    nb_segs = dmin+1;

}