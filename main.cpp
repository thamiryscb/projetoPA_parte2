#include <iostream>
#include <vector>
#include "Interpretador.h"
#include "Sculptor.h"
#include "FiguraGeometrica.h"

using namespace std;

int main() {
    Interpretador interpretador;
    vector<FiguraGeometrica*> figuras = interpretador.parse("martelo.txt");

    if (figuras.empty()) {
        cout << "Verifique o arquivo, erro ao carregar a figura" << endl;
        return 1;
    }

    // escultor criado com as dimensões do arquivo
    Sculptor s(interpretador.get_x(), interpretador.get_y(), interpretador.get_z());

    // Desenha as figuras
    for (size_t i = 0; i < figuras.size(); i++) {
        figuras[i]->draw(s);
    }


    s.writeOFF("saida.off");
    cout << "Arquivo off gerado" << endl;

    // Libera a memória alocada
    for (size_t i = 0; i < figuras.size(); i++) {
        delete figuras[i];
    }

    return 0;
}
