#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

//variables
Texture texture_red, texture_yellow, texture_grey, texture_blue;
Sprite sprite_red, sprite_yellow, sprite_grey, sprite_blue;
const int tamaño_cuadrado = 300;
float escalaX; float escalaY; float height_red, width_red; float height_yellow, width_yellow;
float height_blue, width_blue; float height_grey, width_grey;

int main() {

	//cargamos las texturas y se las colocamos a los sprites
	texture_red.loadFromFile("cuad_red.png");
	texture_yellow.loadFromFile("cuad_yellow.png");
	texture_grey.loadFromFile("cuad_grey.png");
	texture_blue.loadFromFile("cuad_blue.png");

	sprite_red.setTexture(texture_red);
	sprite_yellow.setTexture(texture_yellow);
	sprite_grey.setTexture(texture_grey);
	sprite_blue.setTexture(texture_blue);

	//posicionamos y escalamos los sprites
	sprite_red.setPosition(0, 0);
	sprite_yellow.setPosition(0, 256);
	sprite_blue.setPosition(256, 0);
	sprite_grey.setPosition(256, 256);

	//obtenemos las dimensiones del sprite a comparar
	float height_red = (float)texture_red.getSize().y;
	float width_red = (float)texture_red.getSize().x;

	//escalamos los otros sprites en base a las dimensiones del sprite rojo
	float escalaX = width_red / (float)texture_yellow.getSize().x;
	float escalaY = height_red / (float)texture_yellow.getSize().y;
	sprite_yellow.setScale(escalaX, escalaY);

	escalaX = width_red / (float)texture_blue.getSize().x;
	escalaY = height_red / (float)texture_blue.getSize().y;
	sprite_blue.setScale(escalaX, escalaY);

	escalaX = width_red / (float)texture_grey.getSize().x;
	escalaY = height_red / (float)texture_grey.getSize().y;
	sprite_grey.setScale(escalaX, escalaY);

	RenderWindow App(VideoMode(512, 512, 32), "Cuadrados");
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
	App.draw(sprite_red); 
	App.draw(sprite_yellow); 
	App.draw(sprite_grey);
	App.draw(sprite_blue);

	//mostramos la ventana 
		App.display(); 
	} 
	return 0; 
}
