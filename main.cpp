#include "film.h"
#include "vec3.h"
#include "camera.h"
#include "parser.h"


int main(int argc, char* argv[]) {

    // Film

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    //film film(image_width, image_height);

    struct RunningOptions ro = Parser::parse();
    //RunningOptions ro = Parser::parse(argc, argv);
    film film(std::stoi(ro.filmX_res), std::stoi(ro.filmY_res), ro.filmType, ro.filmFilename, ro.filmImgtype);


    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    camera cam(ro.cameraType, aspect_ratio, viewport_height, viewport_width, focal_length, origin, horizontal, vertical, lower_left_corner, film);

    cam.render();


}