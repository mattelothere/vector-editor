//
// Created by Cam on 19/04/2023.
//

#ifndef VECTOR_EDITOR_PIXEL_H
#define VECTOR_EDITOR_PIXEL_H

#include "structure.h"
#include "shapes.h"
struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);
void pixel_circle(Circle* circle, Pixel** pixel, int*nb_pixels);
void pixel_square(Square* square, Pixel** pixel, int* nb_pixels);
void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Polygon* polygon, Pixel** pixel, int* nb_pixels);

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);

#endif