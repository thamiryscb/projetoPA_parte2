#include "Interpretador.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<FiguraGeometrica*> Interpretador::parse(string Arquivo) {
    vector<FiguraGeometrica*> figuras;
    ifstream arquivo;
    string linha, comando;

    arquivo.open(Arquivo.c_str());
    if (!arquivo.is_open()) {
        cout << "Não foi possível abrir " << Arquivo << endl;
        return figuras;
    }

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        ss >> comando;

        if (comando == "dim") {
            ss >> x >> y >> z;

        } else if (comando == "color") {
            ss >> r >> g >> b >> a;

        } else if (comando == "putvoxel") {
            int x, y, z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));

        } else if (comando == "cutvoxel") {
            int x, y, z;
            ss >> x >> y >> z;
            figuras.push_back(new CutVoxel(x, y, z));

        } else if (comando == "putbox") {
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

        } else if (comando == "cutbox") {
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));

        } else if (comando == "putsphere") {
            int x, y, z, raio;
            ss >> x >> y >> z >> raio;
            figuras.push_back(new PutSphere(x, y, z, raio, r, g, b, a));

        } else if (comando == "cutsphere") {
            int x, y, z, raio;
            ss >> x >> y >> z >> raio;
            figuras.push_back(new CutSphere(x, y, z, raio));

        } else if (comando == "putellipsoid") {
            int x, y, z, rx, ry, rz;
            ss >> x >> y >> z >> rx >> ry >> rz;
            figuras.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));

        } else if (comando == "cutellipsoid") {
            int x, y, z, rx, ry, rz;
            ss >> x >> y >> z >> rx >> ry >> rz;
            figuras.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
        }
    }

    arquivo.close();
    return figuras;
}

int Interpretador::get_x() {
    return x;
}

int Interpretador::get_y() {
    return y;
}

int Interpretador::get_z() {
    return z;
}
