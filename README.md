# 🧊 Escultor 3D (Parte 2)

Um sistema em **C++** focado em modelagem tridimensional através da manipulação de blocos chamados **Voxels**. Este projeto interpreta um arquivo de texto com instruções para gerar esculturas 3D exportáveis (geralmente no formato `.OFF` ou similar).

---

## 🚀 Tecnologias Utilizadas

* **C++** (Linguagem principal)
* **[Qt Creator / QMake](https://www.qt.io/)** (Ambiente de desenvolvimento e sistema de build - *Qt 6.9.0 MinGW 64-bit*)
* **Orientação a Objetos** (Polimorfismo, Herança e Classes Abstratas)

---

## 🧩 Como Funciona

O projeto utiliza uma classe principal chamada `Sculptor` que aloca dinamicamente uma matriz 3D. Através da leitura de um arquivo de texto pelo `Interpretador`, o sistema identifica quais figuras geométricas devem ser desenhadas ou apagadas.

### Formas Geométricas Suportadas:
Todas as formas herdam da classe abstrata `FiguraGeometrica` e possuem o método `draw(Sculptor &t)`.
* **Voxels (Pontos):** `PutVoxel` (Desenha) / `CutVoxel` (Apaga)
* **Caixas (Cúbicas):** `PutBox` (Desenha) / `CutBox` (Apaga)
* **Esferas:** `PutSphere` (Desenha) / `CutSphere` (Apaga)
* **Elipsoides:** `PutEllipsoid` (Desenha) / `CutEllipsoid` (Apaga)

---

## 📁 Estrutura do Projeto

* **`Voxel.h`**: Estrutura que define um Voxel (possui cor `r, g, b`, transparência `a` e um booleano `isOn` para saber se está ativo).
* **`Sculptor.cpp / .h`**: Gerencia a matriz 3D, as cores atuais e a exportação do modelo final.
* **`FiguraGeometrica.cpp / .h`**: Classe abstrata base para todas as formas.
* **`Put* / Cut*`**: Classes concretas que implementam a lógica para adicionar ou remover suas respectivas formas da escultura.
* **`Interpretador.cpp`**: Responsável por ler o arquivo de script e empilhar as formas que serão desenhadas.
* **`PA-parte2.pro`**: Arquivo de configuração do projeto para o Qt Creator.
* **`main.cpp`**: Ponto de entrada que une a interpretação do arquivo de texto e a execução dos desenhos.
