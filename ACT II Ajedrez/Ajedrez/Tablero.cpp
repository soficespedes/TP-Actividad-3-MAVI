#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;

//variables
Texture texture_black;
Texture texture_white;
Sprite sprite_black;
Sprite sprite_white;

const int tama�o_casilla = 100; //tama�o de cada casilla
const int tama�o_tablero = 8; //tama�o del tablero (8x8)

int main() {

    //cargamos las texturas
    texture_black.loadFromFile("chessb.png");
    texture_white.loadFromFile("chessw.png");

    //configuramos los sprites
    sprite_black.setTexture(texture_black);
    sprite_white.setTexture(texture_white);

    //escalamos los sprites
    sprite_black.setScale(tama�o_casilla / (float)texture_black.getSize().x,
        tama�o_casilla / (float)texture_black.getSize().y);
    sprite_white.setScale(tama�o_casilla / (float)texture_white.getSize().x,
        tama�o_casilla / (float)texture_white.getSize().y);

    //creamos la ventana
    RenderWindow App(VideoMode(800, 800, 32), "Tablero de Ajedrez");

    //loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }
        //limpiamos la ventana
        App.clear();

        //dibujamos el tablero 
        for (int fila = 0; fila < tama�o_tablero; ++fila) {
            for (int columna = 0; columna < tama�o_tablero; ++columna) {
                //posicionamos las casillas
                Vector2f posicion(columna * tama�o_casilla, fila * tama�o_casilla);
                
                //alternamos entre las im�genes
                if ((fila + columna) % 2 == 0) {
                    sprite_white.setPosition(posicion);
                   App.draw(sprite_white); //casilla blanca
                } else {
                    sprite_black.setPosition(posicion);
                    App.draw(sprite_black); //casilla negra
                }
            }
        }

        //mostramos la ventana
        App.display(); 
    }

    return 0;
}

