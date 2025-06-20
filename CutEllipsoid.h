#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.h"

class CutEllipsoid: public FiguraGeometrica {
private:
    int centro_x, centro_y, centro_z, raio_x, raio_y, raio_z;

public:
    CutEllipsoid(int x, int y, int z, int raio_x, int raio_y, int raio_z);
    ~CutEllipsoid();
    void draw(Sculptor &s);
};
#endif // CUTELLIPSOID_H
