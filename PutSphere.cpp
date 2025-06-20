#include "PutSphere.h"
#include "Sculptor.h"

PutSphere::PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a) {
    this->centro_x = x;
    this->centro_y = y;
    this->centro_z = z;
    this->raio = raio;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutSphere::~PutSphere() {}

void PutSphere::draw(Sculptor &s) {
    s.setColor(r, g, b, a);
    for(int i=centro_x-raio; i<=centro_x+raio; i++){
        for(int j=centro_y-raio; j<=centro_y+raio; j++){
            for(int k=centro_z-raio; k<=centro_z+raio; k++){
                int x_esfera = i - centro_x;
                int y_esfera = j - centro_y;
                int z_esfera = k - centro_z;

                if (x_esfera*x_esfera + y_esfera*y_esfera + z_esfera*z_esfera <= raio*raio && i>=0 && j>=0 && k>=0){
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
}
