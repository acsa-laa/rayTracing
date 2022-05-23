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
    std::string type;
    std::string filename;
    std::string img_type;
public:
    film(int imageWidth, int imageHeight, const std::string &type, const std::string &filename,
         const std::string &imgType) : image_width(imageWidth), image_height(imageHeight), type(type),
                                       filename(filename), img_type(imgType) {}

public:
    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        film::type = type;
    }

    const std::string &getFilename() const {
        return filename;
    }

    void setFilename(const std::string &filename) {
        film::filename = filename;
    }

    const std::string &getImgType() const {
        return img_type;
    }

    void setImgType(const std::string &imgType) {
        img_type = imgType;
    }

public:

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