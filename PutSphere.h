#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"

class PutSphere: public FiguraGeometrica {
private:
    int centro_x, centro_y, centro_z, raio;
    float r, g, b, a;

public:
    PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a);
    ~PutSphere();
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
