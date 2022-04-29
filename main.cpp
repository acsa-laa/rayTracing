#include <iostream>
#include <fstream>
#include <string>
#include "color.h"
#include "film.h"
#include "ray.h"



int main() {

    film f(256, 256);
    f.render(16.0 / 9.0);

}