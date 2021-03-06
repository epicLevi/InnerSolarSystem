#include "Sphere.h"

Sphere::Sphere(Math3D* _model) {
    model = _model;
    loadIdentity(matrix.M);
}

void Sphere::draw() {
    float x, y, z, i, j;
    float r = 1;
    int nParal = 10, nMerid = 10;

    for (j = 0; j < M_PI; j += M_PI/(nParal+1)) {
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);

        y = (float) (r * cos(j));

        for (i = 0; i < 2*M_PI; i += M_PI/60) {
            x = (float) (r * cos(i) * sin(j));
            z = (float) (r * sin(i) * sin(j));
            Point point(x, y, z);
            updatePoint(&point);
            glVertex3f(point.x, point.y, point.z);
        }

        glEnd();
    }

    for (j = 0; j < M_PI; j += M_PI/nMerid) {
        glBegin(GL_LINE_LOOP);

        for (i = 0; i < 2*M_PI; i += M_PI/60){
            x = (float) (r * sin(i) * cos(j));
            y = (float) (r * cos(i));
            z = (float) (r * sin(j) * sin(i));
            Point point(x, y, z);
            updatePoint(&point);
            glVertex3f(point.x, point.y, point.z);
        }

        glEnd();
    }
}
