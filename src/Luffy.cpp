#include "Luffy.h"

Luffy::Luffy()
{
    // Lyffy sprite
    sf::Texture * luffyTextura = new sf::Texture;
    luffyTextura->loadFromFile("sprites/personaje.png");
    this->spriteLuffy = new sf::Sprite(*luffyTextura);
    this->spriteLuffy->setPosition(180, 352);
    // Vidas iniciales de luffy-
    sf::Texture * luffyVidas2 = new sf::Texture;
    luffyVidas2->loadFromFile("sprites/marcador2.png");
    this->spriteVidaLuffy2 = new sf::Sprite(*luffyVidas2);
    this->spriteVidaLuffy2->setPosition(20, 10);
    // Marcador 1 vida
    sf::Texture * luffyVidas1 = new sf::Texture;
    luffyVidas1->loadFromFile("sprites/marcador1.png");
    this->spriteVidaLuffy1 = new sf::Sprite(*luffyVidas1);
    this->spriteVidaLuffy1->setPosition(20, 10);
    // Marcador monedas que recolecta el personaje
    // Moneda x0
    sf::Texture * marcadorTextura0 = new sf::Texture;
    marcadorTextura0->loadFromFile("sprites/marcadorMonedas0.png");
    this->marcadorMoneda0 = new sf::Sprite(*marcadorTextura0);
    this->marcadorMoneda0->setPosition(140, 15);
    // Moneda x1
    sf::Texture * marcadorTextura1 = new sf::Texture;
    marcadorTextura1->loadFromFile("sprites/marcadorMonedas1.png");
    this->marcadorMoneda1 = new sf::Sprite(*marcadorTextura1);
    this->marcadorMoneda1->setPosition(140, 15);
    // Moneda x2
    sf::Texture * marcadorTextura2 = new sf::Texture;
    marcadorTextura2->loadFromFile("sprites/marcadorMonedas2.png");
    this->marcadorMoneda2 = new sf::Sprite(*marcadorTextura2);
    this->marcadorMoneda2->setPosition(140, 15);
    // Moneda x3
    sf::Texture * marcadorTextura3 = new sf::Texture;
    marcadorTextura3->loadFromFile("sprites/marcadorMonedas3.png");
    this->marcadorMoneda3 = new sf::Sprite(*marcadorTextura3);
    this->marcadorMoneda3->setPosition(140, 15);
    // Moneda x4
    sf::Texture * marcadorTextura4 = new sf::Texture;
    marcadorTextura4->loadFromFile("sprites/marcadorMonedas4.png");
    this->marcadorMoneda4 = new sf::Sprite(*marcadorTextura4);
    this->marcadorMoneda4->setPosition(140, 15);
    // Moneda x5
    sf::Texture * marcadorTextura5 = new sf::Texture;
    marcadorTextura5->loadFromFile("sprites/marcadorMonedas5.png");
    this->marcadorMoneda5 = new sf::Sprite(*marcadorTextura5);
    this->marcadorMoneda5->setPosition(140, 15);
    // Moneda x6
    sf::Texture * marcadorTextura6 = new sf::Texture;
    marcadorTextura6->loadFromFile("sprites/marcadorMonedas6.png");
    this->marcadorMoneda6 = new sf::Sprite(*marcadorTextura6);
    this->marcadorMoneda6->setPosition(140, 15);
    // Moneda x7
    sf::Texture * marcadorTextura7 = new sf::Texture;
    marcadorTextura7->loadFromFile("sprites/marcadorMonedas7.png");
    this->marcadorMoneda7 = new sf::Sprite(*marcadorTextura7);
    this->marcadorMoneda7->setPosition(140, 15);
    // Moneda x8
    sf::Texture * marcadorTextura8 = new sf::Texture;
    marcadorTextura8->loadFromFile("sprites/marcadorMonedas8.png");
    this->marcadorMoneda8 = new sf::Sprite(*marcadorTextura8);
    this->marcadorMoneda8->setPosition(140, 15);
    // Moneda x9
    sf::Texture * marcadorTextura9 = new sf::Texture;
    marcadorTextura9->loadFromFile("sprites/marcadorMonedas9.png");
    this->marcadorMoneda9 = new sf::Sprite(*marcadorTextura9);
    this->marcadorMoneda9->setPosition(140, 15);
    // Velocidad desplazamiento.
    this->velocityX = 7;
    // Velocidad Salto.
    this->velocidadSalto = 0;
    // Estado inicial.
    this->estado = QUIETO;
    // Vidas.
    this->vidas = 2;
    // Monedas.
    this->monedas = 0;
    // Vida extra.
    this->recogioVidaExtra = false;
}

void Luffy::cmd() {
    if(this->estado == QUIETO) {
        // Avanzando
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            this->estado = CAMINANDO_ADELANTE;
        }
        // Retrocediendo
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
            this->estado = CAMINANDO_ATRAS;
        }
        // Saltando
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
            // Aplicamos fuerza de salto.
            this->velocidadSalto =28;
            this->estado = SALTANDO;
        }
    // Direccionamos el salto.
    } else if ( this->estado == SALTANDO ) {
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
            if( this->spriteLuffy->getPosition().x <= 8500 )  {
                this->spriteLuffy->move(this->velocityX,0);
            }
        }
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
            if( this->spriteLuffy->getPosition().x >= 30 ) {
                this->spriteLuffy->move(this->velocityX*-1,0);
            }
        }
    }
}

void Luffy::update() {
    // Vamos reaccionando a los estados que puede adoptar el personaje.
    switch (this->estado) {
        case CAMINANDO_ADELANTE:
            if( this->spriteLuffy->getPosition().x <= 8690 ) {
                this->spriteLuffy->move(this->velocityX,0);
            }
             this->estado = QUIETO;
        break;
        case CAMINANDO_ATRAS:
             if( this->spriteLuffy->getPosition().x >= 30 ) {
                    this->spriteLuffy->move(this->velocityX*-1,0);
                }
                this->estado = QUIETO;
        break;
        case SALTANDO:
                if( this->spriteLuffy->getPosition().y <= 0 ) {
                   this->spriteLuffy->setPosition(this->spriteLuffy->getPosition().x, 0);
                }
        break;
    }
    // Gravedad del juego. Siempre afecta al personaje.
    this->velocidadSalto -= 2;
    this->spriteLuffy->move(0, -velocidadSalto);
}

 const sf::Vector2f& Luffy::obtenerPosicion() {
    return this->spriteLuffy->getPosition();
 }

 void Luffy::quieto(float x, float y) {
    this->estado = QUIETO;
    this->velocidadSalto = 0;
    this->spriteLuffy->setPosition(x,y);
 }

int Luffy::restarVida() {
    this->vidas--;
    return this->vidas;
 }

void Luffy::sumarVida() {
    this->vidas++;
 }

int Luffy::sumarMonedas() {
    this->monedas++;
    return this->monedas;
 }
