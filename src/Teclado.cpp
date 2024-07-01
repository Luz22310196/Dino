#include <SFML/Graphics.hpp>
#include <iostream>

double velocidad = 0.1;

int main() {
    sf::Vector2f posicionInicial(150, 235);
    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML Image");
    sf::RectangleShape shape(sf::Vector2f(800, 700));
    shape.setFillColor(sf::Color::White);

    sf::Texture texture1, texture2, texture3, texture4, textureColision;
    if (!texture1.loadFromFile("./assets/dinosaurio/dinosaurio1.png")) {
        return -1;
    }
    if (!texture2.loadFromFile("./assets/mapa/mapa.png")) {
        return -1;
    }
    if (!texture3.loadFromFile("./assets/cactus/cactus1.png")) {
        return -1;
    }
    if (!texture4.loadFromFile("./assets/nube/nube.png")) {
        return -1;
    }
    if (!textureColision.loadFromFile("./assets/gameover.png")) {
        return -1;
    }

    sf::Sprite sprite1(texture1), sprite2(texture2), sprite3(texture3), sprite4(texture4), spriteColision(textureColision);

    sprite1.setPosition(posicionInicial);
    sprite1.setScale(1.7f, 1.7f);

    // Ajuste de posición inicial de sprite2, sprite3 y sprite4
    sprite2.setPosition(0, 350);
    sprite3.setPosition(sprite2.getPosition().x + sprite2.getLocalBounds().width - 1, 285);
    sprite4.setPosition(sprite3.getPosition().x + sprite3.getLocalBounds().width - 1, 5);

    bool saltando = false;
    bool colisionDetectada = false; // Bandera para controlar si se detectó la colisión
    bool juegoActivo = true; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !saltando)
            {
            sf::Vector2f posicionActual = sprite1.getPosition();
            sprite1.move(0, -100);
            saltando = true;       
            }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && saltando)
            {
            sprite1.setPosition(posicionInicial);
            saltando = false; 
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
            sprite1.move(-velocidad, 0);
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
            sprite1.move(velocidad, 0);
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
            sprite1.move(0, velocidad);
            }

        // Movimiento y repetición de los sprites de fondo
        sprite2.move(-0.5f, 0);
        sprite3.move(-0.5f, 0);
        sprite4.move(-0.5f, 0);

        // Repetir sprite2 en el eje X
        if (sprite2.getPosition().x + sprite2.getLocalBounds().width <= 0) {
            sprite2.setPosition(sprite4.getPosition().x + sprite4.getLocalBounds().width - 1, 350);
        }

        // Repetir sprite3 y sprite4 inmediatamente después de sprite2
        if (sprite3.getPosition().x + sprite3.getLocalBounds().width <= 0) {
            sprite3.setPosition(sprite2.getPosition().x + sprite2.getLocalBounds().width - 1, 285);
        }
        if (sprite4.getPosition().x + sprite4.getLocalBounds().width <= 0) {
            sprite4.setPosition(sprite3.getPosition().x + sprite3.getLocalBounds().width - 1, 5);
        }

        // Verificar colisión entre sprite1 y sprite3 solo si no está saltando
        if (!saltando && sprite1.getGlobalBounds().intersects(sprite3.getGlobalBounds())) {
            // Colisión detectada
            colisionDetectada = true;
            // Activar bandera de colisión detectada
        }
        // Si se detecta la colisión, detener el juego
        if (colisionDetectada) {
            juegoActivo = false;  // Establecer juegoActivo a false para salir del bucle principal
             // Otra opción sería mostrar un mensaje de juego perdido, etc.
        }

        // Dibujar todo en la ventana
        window.clear();
        window.draw(shape);
        window.draw(sprite3);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite4);

        // Si hay colisión detectada, mostrar spriteColision en la posición de la colisión
        if (colisionDetectada) {
            spriteColision.setPosition(sprite1.getPosition().x, sprite1.getPosition().y - 100); // Ajustar posición
            window.draw(spriteColision);
        }

        window.display();
    }

    return 0;
}
