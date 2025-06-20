#include "CutSphere.h"
#include "Sculptor.h"

CutSphere::CutSphere(int x, int y, int z, int raio) {
    this->centro_x = x;
    this->centro_y = y;
    this->centro_z = z;
    this->raio = raio;
}

CutSphere::~CutSphere() {}

void CutSphere::draw(Sculptor &s) {
    for(int i=centro_x-raio; i<=centro_x+raio; i++){
        for(int j=centro_y-raio; j<=centro_y+raio; j++){
            for(int k=centro_z-raio; k<=centro_z+raio; k++){
                int x_esfera = i - centro_x;
                int y_esfera = j - centro_y;
                int z_esfera = k - centro_z;

                if (x_esfera*x_esfera + y_esfera*y_esfera + z_esfera*z_esfera <= raio*raio && i>=0 && j>=0 && k>=0){
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
