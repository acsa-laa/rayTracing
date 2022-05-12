#include "film.h"
#include "vec3.h"
#include "camera.h"
#include "parser.h"
#include "color.h"
#include "OrthographicCamera.h"


int main(int argc, char* argv[]) {

    // Film

    auto aspect_ratio = 16.0 / 9.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;



    //const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    //film film(image_width, image_height);

    struct RunningOptions ro = Parser::parse();
    //RunningOptions ro = Parser::parse(argc, argv);
    film film(std::stoi(ro.filmX_res), std::stoi(ro.filmY_res), ro.filmType, ro.filmFilename, ro.filmImgtype);



    //camera cam(ro.cameraType, aspect_ratio, viewport_height, viewport_width, focal_length, origin, horizontal, vertical, lower_left_corner, film);
    OrthographicCamera cam(aspect_ratio, viewport_height, viewport_width, focal_length);
    std::cout << "Renderizando imagem" << std::endl;
    std::string filename = film.getFilename() +"."+film.getImgType();
    std::fstream fs (filename, std::fstream::out);
    
    if (!fs)
        std::cout << "Error loading file\n";
    fs << "P3\n" << film.getImageHeight() << " " << film.getImageHeight()<< "\n255\n";
    for (int j = film.getImageHeight()-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < film.getImageWidth(); ++i) {
            auto u = double(i) / (film.getImageWidth()-1);
            auto v = double(j) / (film.getImageHeight()-1);
            ray r = cam.generateRay(u, v);
            //color pixel_color = ray::ray_color(r, tr, tl, br, bl);
            color pixel_color = ray::ray_color(r);
            write_color(fs, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";


}