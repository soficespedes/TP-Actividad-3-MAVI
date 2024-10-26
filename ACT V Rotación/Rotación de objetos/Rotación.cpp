#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;

//variables
Texture texture;
Sprite sprite;

//punto de entrada de la aplicación
int main() {

    //cargamos la textura y se la colocamos al sprite
    texture.loadFromFile("cuad_yellow.png");
    sprite.setTexture(texture);
    
    //creamos la ventana
    RenderWindow App(VideoMode(900, 700, 32), "Rotar un sprite");

    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2); //establecemos el origen en el centro
    sprite.setPosition(App.getSize().x / 2, App.getSize().y / 2); //posicionamos el sprite en el centro de la ventana

    //loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

        //rotamos el sprite
        sprite.rotate(1.0f); //a 1 grado por cuadro

        //limpiamos la ventada
       App.clear();

        //dibujamos la escena
        App.draw(sprite);

        //mostramos el contenido de la ventana
       App.display();
    }

    return 0;
}
