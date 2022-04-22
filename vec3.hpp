#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>
#include <stdlib.h>

enum {RED, GREEN, BLUE};

class vec3 {

 public:

	float c[3];

	vec3() {}
	vec3(float c0, float c1, float c2) : c{c0,c1,c2} {}

	float x() const { 
		return c[0]; 
	}
	float y() const { 
		return c[1]; 
	}
	float z() const { 
		return c[2]; 
	}
	
	float operator[](int i) const { 
		return c[i]; 
	}
	float& operator[](int i) { 
		return c[i]; 
	}

	float length() const{ 
		return sqrt(c[0]*c[0] + c[1]*c[1] + c[2]*c[2]); 
	}
};

//=== Operators
vec3 operator+(const vec3 &v1, const vec3 &v2){ 
	return vec3(v1.c[0] + v2.c[0], v1.c[1] + v2.c[1], v1.c[2] + v2.c[2]); 
}

vec3 operator-(const vec3 &v1, const vec3 &v2){ 
	return vec3(v1.c[0] - v2.c[0], v1.c[1] - v2.c[1], v1.c[2] - v2.c[2]); 
}

vec3 operator/(const vec3 &v1, float x){ 
	return vec3(v1.c[0] / x, 
	v1.c[1] / x, v1.c[2] / x); 
}

vec3 operator*(float x, const vec3 &v1){ 
	return vec3(v1.c[0] * x, v1.c[1] * x, v1.c[2] * x); 
}

//=== Operations
float dot(const vec3 &v1, const vec3 &v2){ 
	return v1.c[0] * v2.c[0] + v1.c[1] * v2.c[1] + v1.c[2] * v2.c[2]; 
}

vec3 unit_vector(vec3 v){ 
	return (v / v.length()); 
}

#endif
