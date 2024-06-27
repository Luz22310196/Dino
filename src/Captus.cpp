#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 700), "SFML Image");
    sf::RectangleShape shape(sf::Vector2f(800, 700));
    shape.setFillColor(sf::Color::White);

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/captus/captus1.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 350);

    // Bucle principal
    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Cerrar la ventana si se recibe el evento de cerrar
                window.close();
            }
        }

        // Limpiar la ventana
        window.clear();

        window.draw(shape);
        // Dibujar el sprite en la ventana

        sprite.move(sf::Vector2f(0.1, 0));
        window.draw(sprite);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}
