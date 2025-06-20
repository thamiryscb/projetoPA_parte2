#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "FiguraGeometrica.h"

class Interpretador
{
    public:
        std::vector<FiguraGeometrica*> parse(std::string filename);
        int get_x();
        int get_y();
        int get_z();

    protected:
        int x, y, z;
        float r, g, b, a;
};

#endif // INTERPRETADOR_H
