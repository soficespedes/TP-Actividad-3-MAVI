#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;
//variables//
Texture texture_point1, texture_point2, texture_point3, texture_point4;
Sprite sprite_point1, sprite_point2, sprite_point3, sprite_point4;

//punto de entrada a la aplicacion//
int main() {

	//cargamos la textura del archivo
	texture_point1.loadFromFile("rcircle_1.png");
	texture_point2.loadFromFile("rcircle_1.png");
	texture_point3.loadFromFile("rcircle_1.png");
	texture_point4.loadFromFile("rcircle_1.png");

	//cargamos el material del sprite
	sprite_point1.setTexture(texture_point1);
	sprite_point2.setTexture(texture_point2);
	sprite_point3.setTexture(texture_point3);
	sprite_point4.setTexture(texture_point4);

	//movemos el sprite
	sprite_point1.setPosition(0, 0);
	sprite_point2.setPosition(0, 470);
	sprite_point3.setPosition(670, 0);
	sprite_point4.setPosition(670, 470);

	//creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32),
		"Ventana de aplicación");

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
		App.draw(sprite_point1);
		App.draw(sprite_point2);
		App.draw(sprite_point3);
		App.draw(sprite_point4);

		//mostramos la ventana
		App.display();
	}

	return 0;
}
