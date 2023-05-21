//
// Created by Cam on 19/04/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "area.h"
#include "pixel.h"

Area* create_area(unsigned int width, unsigned int height) {
    Area *area = (Area *) malloc(sizeof(Area));
    area->height = height;
    area->width = width;
    area->nb_shape = 0;
    area->mat = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        area->mat[i] = (int *) malloc(width * sizeof(int));
    for (int i = 0; i < SHAPE_MAX; i++) {
        area->shapes[i] = (Shape*) malloc(sizeof(Shape));
    }
    return area;
}

void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}


void clear_area(Area* area){
    for (int i = 0; i < (int) area->height; i++) {
        for (int j = 0; j < (int) area->width; j++) {
            area->mat[i][j] = 0; //each px of the matrix is initialized to 0
        }
    }
}



void erase_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        delete_shape(area->shapes[i]);
    }
}


void delete_area(Area* area){
    clear_area(area);
    erase_area(area);
}

void draw_area(Area* area, int* nb_pixels){     //TODO doesnt work
    Pixel ** L;
    for(int i = 0; i< area->nb_shape; i++){
        L = create_shape_to_pixel(area->shapes[i], nb_pixels);
        for (int j = 0; j< *nb_pixels; j++) {
            area->mat[L[j]->px-1][L[j]->py-1] = 1;
        }
    }
}

void print_area(Area* area){
    for (int i = 0; i< area->height; i++){
        printf("\n");
        for (int j = 0; j< area->width; j++) {
            switch (area->mat[i][j]) {
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("#");
                    break;
            }
        }
    }

}
