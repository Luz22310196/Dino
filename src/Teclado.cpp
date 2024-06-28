#include <SFML/Graphics.hpp>

double velocidad = 0.1;
int main()
{
    sf::Vector2f posicionInicial(150, 250);

    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML Image");
    sf::RectangleShape shape(sf::Vector2f(800, 700));
    shape.setFillColor(sf::Color::White);

    // Cargar la imagen desde un archivo
    sf::Texture texture1, texture2, texture3, texture4;
    if (!texture1.loadFromFile("./assets/dinosaurio/dinosaurio1.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    if (!texture2.loadFromFile("./assets/mapa/mapa.png"))
    {
        return -1;
    }
    if (!texture3.loadFromFile("./assets/captus/captus1.png"))
    {
        return -1;
    }
    if (!texture4.loadFromFile("./assets/nube/nube.png"))
    {
        return -1;
    }
    // Crear un sprite signarle la textura y las coordenadas
    sf::Sprite sprite1, sprite2, sprite3, sprite4;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite3.setTexture(texture3);
    sprite4.setTexture(texture4);

    sprite1.setPosition(150, 250);
    sprite2.setPosition(0, 350);
    sprite3.setPosition(350, 250);
    sprite4.setPosition(100, 50);

    bool saltando = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Verificar si se presiona la tecla de salto (por ejemplo, tecla Arriba)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !saltando)
        {
            // Guardar la posición actual antes de saltar
            sf::Vector2f posicionActual = sprite1.getPosition();

            sprite1.move(0, -100); // Mover hacia arriba
            saltando = true;       // Activar el estado de salto
        }

        // Lógica para finalizar el salto
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && saltando)
        {
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

        window.clear();
        window.draw(shape);

        // Dibujar los sprites en la ventana
        sprite2.move(sf::Vector2f(-0.01, 0));
        window.draw(sprite2);
        window.draw(sprite1);
        sprite3.move(sf::Vector2f(-0.01, 0));
        window.draw(sprite3);
        sprite4.move(sf::Vector2f(-0.01, 0));
        window.draw(sprite4);
        window.display();
    }

    return 0;
}