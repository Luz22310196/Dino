#pragma once
#include "Velocidad.hpp"
#include "Vida.hpp"
#include "Juego.hpp"
#include <SFML/Graphics.hpp>

    using namespace std:

class Dinosaurio{ 
    private:
    public: 
        int Velocidad;
        int Salto;
        int Vida;
        int Puntaje;
        void Correr(){}
        void Perdervida(){}
        void Ganarpuntos(){}
};

class Dinosaurio {
public:
    Dinosaurio();
    ~Dinosaurio();

private:
    Velocidad velocidad;
    Vida vida;
};