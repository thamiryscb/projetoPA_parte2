#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.h"

class CutSphere: public FiguraGeometrica {
private:
    int centro_x, centro_y, centro_z, raio;

public:
    CutSphere(int x, int y, int z, int raio);
    ~CutSphere();
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
