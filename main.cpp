#include "parser.h"
#include "OrthographicCamera.h"
#include "color.h"
#include "sphere.h"
#include "PerspectiveCamera.h"


int main(int argc, char* argv[]) {

    // Camera

    struct RunningOptions ro = Parser::parse();

    const int image_width = ro.filmX_res;
    const int image_height = ro.filmY_res;
    const auto aspect_ratio = image_width/image_height;

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = -1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    film film(ro.filmX_res, ro.filmY_res, ro.filmType, ro.filmFilename, ro.filmImgtype);



    //camera cam(ro.cameraType, aspect_ratio, viewport_height, viewport_width, focal_length, origin, horizontal, vertical, lower_left_corner, film);
    PerspectiveCamera cam(aspect_ratio, viewport_height, viewport_width, focal_length);
    std::cout << "Renderizando imagem" << std::endl;
    std::string filename = film.getFilename() +"."+film.getImgType();
    std::fstream fs (filename, std::fstream::out);
    
    if (!fs)
        std::cout << "Error loading file\n";

    fs << "P3\n" << film.getImageWidth() << " " << film.getImageHeight() << "\n255\n";

    for (int j = film.getImageHeight()-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < film.getImageWidth(); ++i) {
            auto u = double(i) / (film.getImageWidth()-1);
            auto v = double(j) / (film.getImageHeight()-1);
            ray r = cam.generateRay(u, v);

            color pixel_color = ray_color(r, ro.objects, ro.backgroundTr/255,ro.backgroundTl/255,ro.backgroundBr/255,ro.backgroundBl/255);
            write_color(fs, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";


}