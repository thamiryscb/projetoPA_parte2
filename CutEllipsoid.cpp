#include "CutEllipsoid.h"
#include "Sculptor.h"

CutEllipsoid::CutEllipsoid(int x, int y, int z, int raio_x, int raio_y, int raio_z) {
    this->centro_x = x;
    this->centro_y = y;
    this->centro_z = z;
    this->raio_x = raio_x;
    this->raio_y = raio_y;
    this->raio_z = raio_z;
}

CutEllipsoid::~CutEllipsoid() {}

void CutEllipsoid::draw(Sculptor &s) {
    for(int i = centro_x - raio_x; i <= centro_x + raio_x; i++) {
        for(int j = centro_y - raio_y; j <= centro_y + raio_y; j++) {
            for(int k = centro_z - raio_z; k <= centro_z + raio_z; k++) {

                int xc = i - centro_x;
                int yc = j - centro_y;
                int zc = k - centro_z;

                float var_x = (float)xc/raio_x;
                float var_y = (float)yc/raio_y;
                float var_z = (float)zc/raio_z;

                if (var_x *var_x + var_y*var_y + var_z*var_z <= 1 && i>=0 && j>=0 && k>=0){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
