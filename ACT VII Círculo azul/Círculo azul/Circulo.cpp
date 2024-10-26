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
	texture.loadFromFile("circ_azul.png");
	sprite.setTexture(texture);

    //creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Círculo azul");
  
    //configuramos el sprite para que aparezca en el centro de la ventana
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2); //establecemos el origen en el centro
    sprite.setPosition(App.getSize().x / 2, App.getSize().y / 2); //posicionamos el sprite en el centro de la ventana

    //loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
               App.close();
        }
        //limpiamos la ventana
        App.clear();

        //dibujamos la escena
        App.draw(sprite);

        //msotramos el contenido de la ventana
        App.display();
    }

    return 0;
}
