#pragma once
#include"Mapa.hpp"
#include "Nube.hpp"
#include "Obstaculo.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include<list>

using namespace std;

class Mapa {
+List<Nube> nubes
+List<Cactus> cactus
+List<Pterosaurio> pterosaurios
+void generar()
+void actualizar()
}

class Mapa {
public:
    Mapa();
    ~Mapa();

private:
    std::vector<Nube*> nubes;
    std::vector<Obstaculo*> obstaculos;
};