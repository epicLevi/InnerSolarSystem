#ifndef Sphere_h
#define Sphere_h

#include "Drawable.h"

class Sphere : public Drawable {
public:
    Sphere(Math3D*);
    void draw();
};

#endif // Sphere_h
