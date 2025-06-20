#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"

class PutEllipsoid: public FiguraGeometrica {
    private:
        int centro_x, centro_y, centro_z, raio_x, raio_y, raio_z;
        float r, g, b, a;

    public:
        PutEllipsoid(int x, int y, int z, int raio_x, int raio_y, int raio_z, float r, float g, float b, float a);
        ~PutEllipsoid();
        void draw(Sculptor &s);
};
#endif // PUTELLIPSOID_H
