#include "parser.h"
#include "OrthographicCamera.h"
#include "color.h"
#include "sphere.h"



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
    film film(ro.filmX_res, ro.filmY_res, ro.filmType, ro.filmFilename, ro.filmImgtype);



    //camera cam(ro.cameraType, aspect_ratio, viewport_height, viewport_width, focal_length, origin, horizontal, vertical, lower_left_corner, film);
    OrthographicCamera cam(aspect_ratio, viewport_height, viewport_width, focal_length);
    std::cout << "Renderizando imagem" << std::endl;
    std::string filename = film.getFilename() +"."+film.getImgType();
    std::fstream fs (filename, std::fstream::out);

    //criando esferas
    std::vector<Primitive*> shapes;
    auto *s1 = new Sphere(point3(1,-1,-1),1,color(0,0,255));
    auto *s2 = new Sphere(point3(2,4,-6),2,color(255,0,0));
    auto *s3 = new Sphere(point3(1,1,-10), 3,color(0,255,0));
    shapes.push_back(s1);
    shapes.push_back(s2);
    shapes.push_back(s3);
    
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
            //color pixel_color = ray_color(r);

            color pixel_color = ray_color(r, shapes, ro.backgroundTr/255,ro.backgroundTl/255,ro.backgroundBr/255,ro.backgroundBl/255);
            write_color(fs, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";


}