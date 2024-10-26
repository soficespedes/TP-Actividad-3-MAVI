#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

//variables
Texture texture_platform;
Sprite platform1, platform2, platform3, platform4, platform5, platform6;
Sprite horizontalPlatform;

//punto de entrada de la aplicación
int main() {
    
    //cargamos la textura
	texture_platform.loadFromFile("plataforma.jpg");
    //colocamos la textura a cada sprite
    platform1.setTexture(texture_platform);
    platform2.setTexture(texture_platform);
    platform3.setTexture(texture_platform);
    platform4.setTexture(texture_platform);
    platform5.setTexture(texture_platform);
    platform6.setTexture(texture_platform);
    horizontalPlatform.setTexture(texture_platform);

    //modificamos los sprites
    float height1 = 100, height2 = 150, height3 = 200, height4 = 250, height5 = 300, height6 = 350; //altura de cada plataforma
    float barWidth = 40.0f; //ancho de cada plataforma
    float gap = 20.0f; //espacio entre plataformas

    //creamos la ventana
    RenderWindow App(VideoMode(800, 600, 32), "Plataforma");

    //configuramos cada plataforma vertical
        platform1.setScale(barWidth / texture_platform.getSize().x, height1 / texture_platform.getSize().y);
        platform1.setPosition(0 * (barWidth + gap), 600 - height1); 

        platform2.setScale(barWidth / texture_platform.getSize().x, height2 / texture_platform.getSize().y);
        platform2.setPosition(1 * (barWidth + gap), 600 - height2);

        platform3.setScale(barWidth / texture_platform.getSize().x, height3 / texture_platform.getSize().y);
        platform3.setPosition(2 * (barWidth + gap), 600 - height3);

        platform4.setScale(barWidth / texture_platform.getSize().x, height4 / texture_platform.getSize().y);
        platform4.setPosition(3 * (barWidth + gap), 600 - height4);

        platform5.setScale(barWidth / texture_platform.getSize().x, height5 / texture_platform.getSize().y);
        platform5.setPosition(4 * (barWidth + gap), 600 - height5);

        platform6.setScale(barWidth / texture_platform.getSize().x, height6 / texture_platform.getSize().y);
        platform6.setPosition(5 * (barWidth + gap), 600 - height6);

    //configuramos la plataforma horizontal
        horizontalPlatform.setScale(600.0f / texture_platform.getSize().x, 25.0f / texture_platform.getSize().y);
        horizontalPlatform.setPosition(350.0f, 200.0f);

        //loop principal
        while (App.isOpen()) {
            Event event;
            while (App.pollEvent(event)) {
                if (event.type == Event::Closed)
                    App.close();
            }

            //limpiamos la ventana
            App.clear();

            //dibujamos las plataformas
            App.draw(platform1);
            App.draw(platform2);
            App.draw(platform3);
            App.draw(platform4);
            App.draw(platform5);
            App.draw(platform6);
            App.draw(horizontalPlatform);

            //mostramos la ventana
            App.display();
        }

        return 0;
    }