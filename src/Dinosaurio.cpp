#include <SFML/Graphics.hpp>
#include"../include/Dinosaurio.hpp"

sf::Texture texture1;
    if (!texture1.loadFromFile("./assets/dinosaurio/dinosaurio1.png")){
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sprite1.setPosition(150, 250);
        bool saltando = false;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Verificar si se presiona la tecla de salto (por ejemplo, tecla Arriba)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !saltando){
            // Guardar la posición actual antes de saltar
            sf::Vector2f posicionActual = sprite1.getPosition();
            sprite1.move(0, -100); // Mover hacia arriba
            saltando = true;       // Activar el estado de salto
        }
        // Lógica para finalizar el salto
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && saltando)  {
            // Restaurar la posición inicial después del salto
            sprite1.setPosition(posicionInicial);
            saltando = false; // Desactivar el estado de salto una vez que se suelta la tecla
        }
        // Manejo de movimiento lateral (izquierda y derecha)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite1.move(-velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite1.move(velocidad, 0);
        }
        // Manejo de movimiento vertical continuo (abajo)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite1.move(0, velocidad);
        }
         window.draw(sprite1);
         }

    return 0;

