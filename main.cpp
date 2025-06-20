#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Sculptor.h"
#include "FiguraGeometrica.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

using namespace std;

int main() {
    vector<FiguraGeometrica*> figuras;
    string s;
    int dimx = 0, dimy = 0, dimz = 0;
    float r = 0, g = 0, b = 0, a = 0;

    ifstream fin;
    fin.open("C:\\Users\\CLIENTE\\Documents\\PA-parte2\\build\\Desktop_Qt_6_9_0_MinGW_64_bit-Debug\\martelo.txt");

    if(!fin.is_open()){
        exit(0);
    };

    while(fin.good()){
        fin >> s;
        if(!fin.good()){
            break;
        }
        if (s=="dim") {
            fin >> dimx >> dimy >> dimz;

        } else if (s == "color") {
            fin >> r >> g >> b >> a;

        } else if (s == "putvoxel") {
            int x, y, z;
            fin >> x >> y >> z;
            figuras.push_back(new PutVoxel(x, y, z, r, g, b, a));

        } else if (s == "cutvoxel") {
            int x, y, z;
            fin >> x >> y >> z;
            figuras.push_back(new CutVoxel(x, y, z));

        } else if (s == "putbox") {
            int x0, x1, y0, y1, z0, z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

        } else if (s == "cutbox") {
            int x0, x1, y0, y1, z0, z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));

        } else if (s == "putsphere") {
            int x, y, z, raio;
            fin >> x >> y >> z >> raio;
            figuras.push_back(new PutSphere(x, y, z, raio, r, g, b, a));

        } else if (s == "cutsphere") {
            int x, y, z, raio;
            fin >> x >> y >> z >> raio;
            figuras.push_back(new CutSphere(x, y, z, raio));

        } else if (s == "putellipsoid") {
            int x, y, z, rx, ry, rz;
            fin >> x >> y >> z >> rx >> ry >> rz;
            figuras.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));

        } else if (s == "cutellipsoid") {
            int x, y, z, rx, ry, rz;
            fin >> x >> y >> z >> rx >> ry >> rz;
            figuras.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
        }
    }

    fin.close();

    Sculptor sculptor(dimx, dimy, dimz);

    for(auto i : figuras){
        i->draw(sculptor);
    }

    sculptor.writeOFF("saida.off");
    cout << "Arquivo off gerado" << endl;

    for(auto i : figuras){
        delete i;
    }


    return 0;
}
