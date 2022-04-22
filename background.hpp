#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <vector>
#include "vec3.hpp"

using namespace std;

class Background
{
private:
	unsigned char*** p; // Pixel matrix
  int height;
  int width;

public:
  // Setters & getters
  int get_height() const {return height;}
  int get_width() const {return width;}
	Background(int height, int width, Color c=Color(0,0,0)) {
    this->height = height;
    this->width = width;
    p = new unsigned char**[height];
    for (int i=0; i < height; ++i) {
      p[i] = new unsigned char*[width];
      for (int j=0; j < width; ++j) {
        p[i][j] = new unsigned char[3];
        p[i][j][RED] = c[RED];
        p[i][j][GREEN] = c[GREEN];
        p[i][j][BLUE] = c[BLUE];
      }
    }
  }

  ~Background(){
    for (int i=0; i < height; ++i) {
      for (int j=0; j < width; ++j) {
        delete[] p[i][j];
      }
      delete[] p[i];
    }
  }
  
};

#endif // _BACKGROUND_H_