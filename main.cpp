#include "parser.h"
#include "OrthographicCamera.h"
#include "color.h"
#include "sphere.h"
#include "PerspectiveCamera.h"
#include "flatIntegrator.h"

int main(int argc, char *argv[]) {

    // Camera
    struct RunningOptions ro = Parser::parse();
    Integrator *integrator;
    if (std::strcmp(ro.integratorType.c_str(), "flat") == 0) {
        integrator = new FlatIntegrator();
    } else if (std::strcmp(ro.integratorType.c_str(), "depth") == 0) {
        integrator = new DepthMapIntegrator();
    } else if (std::strcmp(ro.integratorType.c_str(), "normal") == 0) {
        integrator = new NormalIntegrator();
    } else {
        std::cout << "Integrator type not supported" << std::endl;
        integrator = new FlatIntegrator();
    }
    film film(ro);

    const auto aspect_ratio = film.getImageWidth() / film.getImageHeight();

    auto viewport_height = 5.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = -1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

    camera *cam = nullptr;
    if (std::strcmp(ro.cameraType.c_str(), "perspective") == 0) {
        cam = new PerspectiveCamera(aspect_ratio, viewport_height, viewport_width, focal_length);
    } else if (std::strcmp(ro.cameraType.c_str(), "orthographic") == 0) {
        cam = new OrthographicCamera(aspect_ratio, viewport_height, viewport_width, focal_length);
    } else {
        std::cout << "Invalid camera setting. Aborting" << std::endl;
        return -2;
    }
    std::cout << "Renderizando imagem" << std::endl;
    std::string filename = film.getFilename() + "." + film.getImgType();
    std::fstream fs(filename, std::fstream::out);
    if (!fs) {
        std::cout << "Error loading file\n";
        return -3;
    }
    fs << "P3\n" << film.getImageWidth() << " " << film.getImageHeight() << "\n255\n";
    for (int j = film.getImageHeight() - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < film.getImageWidth(); ++i) {
            auto u = double(i) / (film.getImageWidth() - 1);
            auto v = double(j) / (film.getImageHeight() - 1);
            ray r = cam->generateRay(u, v);
            color pixel_color = integrator->ray_color(r, ro);
            write_color(fs, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
    fs.close();
    return 0;
}