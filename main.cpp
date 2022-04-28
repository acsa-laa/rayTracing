#include <iostream>
#include <fstream>
#include <string>
#include "color.hpp"
#include "film.h"
#include "ray.hpp"



int main() {

    film f(256, 256);
    f.render(16.0 / 9.0);

}