//
// Created by Cam on 19/04/2023.
//

#ifndef VECTOR_EDITOR_PIXEL_H
#define VECTOR_EDITOR_PIXEL_H

struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;

Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);

void pixel_point(Point* shape, Pixel** pixel, int* nb_pixels);
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);
#endif //VECTOR_EDITOR_PIXEL_H
