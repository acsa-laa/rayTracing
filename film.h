//
// Created by marti on 28/04/2022.
//

#ifndef RAYTRACING_FILM_H
#define RAYTRACING_FILM_H

#include <fstream>

class film{
private:
    int image_width;
    int image_height;

public:
    film(int imageWidth, int imageHeight) : image_width(imageWidth), image_height(imageHeight) {}

    film() {}


    int getImageWidth() const {
        return image_width;
    }

    void setImageWidth(int imageWidth) {
        image_width = imageWidth;
    }

    int getImageHeight() const {
        return image_height;
    }

    void setImageHeight(int imageHeight) {
        image_height = imageHeight;
    }
};

#endif //RAYTRACING_FILM_H
