#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(800,700), "cuadrado SFML!");

    sf::RectangleShape shape(sf::Vector2f(800,700));
    shape.setFillColor(sf::Color::White);  

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Verificar si se ha cerrado la ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        window.draw(shape);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}