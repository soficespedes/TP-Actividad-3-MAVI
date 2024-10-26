#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;

//variables
Texture texture_wall;
Sprite sprite_wall;

//punto de entrada a la aplicacion//
int main() {

	//cargamos la textura del archivo
	texture_wall.loadFromFile("fondo.jpg");
	//cargamos el material del sprite
	sprite_wall.setTexture(texture_wall);
	//movemos el sprite
	sprite_wall.setPosition(0, 0);

	//creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32),
		"Fondo de nuestro videojuego");

	//loop principal
	while (App.isOpen()) {
		// Procesar eventos
		Event event;
		while (App.pollEvent(event)) {
			if (event.type == Event::Closed)
				App.close();
		}
		//limpiamos la ventana
		App.clear();

		//dibujamos la escena
		App.draw(sprite_wall);

		//mostramos la ventana
		App.display();
	}
	return 0;
}
