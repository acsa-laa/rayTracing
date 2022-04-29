#ifndef _FILM_H_
#define _FILM_H_

class Film
{
 private:
  int height;
  int width;
  Point3 origin;
  Point3 lower_left_corner;
  vec3 horizontal, vertical;
  vec3 u, v, w;
 public:
  Film(int _h, int _w) : height(_h),width(_w){}
}

#endif // _FILM_H_
