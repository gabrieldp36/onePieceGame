#ifndef LUFFY_H
#define LUFFY_H

#include <SFML/Graphics.hpp>
#include "EstadosLuffy.h"

class Luffy
{
    private:
        sf::Sprite * spriteLuffy;
        sf::Sprite * spriteVidaLuffy2;
        sf::Sprite * spriteVidaLuffy1;
        sf::Sprite * marcadorMoneda0;
        sf::Sprite * marcadorMoneda1;
        sf::Sprite * marcadorMoneda2;
        sf::Sprite * marcadorMoneda3;
        sf::Sprite * marcadorMoneda4;
        sf::Sprite * marcadorMoneda5;
        sf::Sprite * marcadorMoneda6;
        sf::Sprite * marcadorMoneda7;
        sf::Sprite * marcadorMoneda8;
        sf::Sprite * marcadorMoneda9;
        EstadosPersonaje estado;
        bool recogioVidaExtra ;
        int vidas;
        int velocityX;
        int velocidadSalto;
        int monedas;

    public:
        Luffy();
        sf::Sprite * getSpriteLuffy() { return this->spriteLuffy; }
        sf::Sprite * getSpriteVidaLuffy2() { return this->spriteVidaLuffy2; }
        sf::Sprite * getSpriteVidaLuffy1() { return this->spriteVidaLuffy1; }
        sf::Sprite * getSpMarcadorMonedas0() { return this->marcadorMoneda0; }
        sf::Sprite * getSpMarcadorMonedas1() { return this->marcadorMoneda1; }
        sf::Sprite * getSpMarcadorMonedas2() { return this->marcadorMoneda2; }
        sf::Sprite * getSpMarcadorMonedas3() { return this->marcadorMoneda3; }
        sf::Sprite * getSpMarcadorMonedas4() { return this->marcadorMoneda4; }
        sf::Sprite * getSpMarcadorMonedas5() { return this->marcadorMoneda5; }
        sf::Sprite * getSpMarcadorMonedas6() { return this->marcadorMoneda6; }
        sf::Sprite * getSpMarcadorMonedas7() { return this->marcadorMoneda7; }
        sf::Sprite * getSpMarcadorMonedas8() { return this->marcadorMoneda8; }
        sf::Sprite * getSpMarcadorMonedas9() { return this->marcadorMoneda9; }
        int getVelocityX() { return this->velocityX; }
        int getVidas() { return this->vidas; }
        int restarVida();
        void sumarVida();
        int setVida(int value) { this->vidas = value; }
        int getMonedas() { return this->monedas; }
        int setMonedas(int value) { this->monedas = value; }
        int sumarMonedas();
        int getVelocidadSalto() { return this->velocidadSalto; }
        bool getRecogioVidaExtra() { return this->recogioVidaExtra; }
        void setRecogioVidaExtra(bool value) { this->recogioVidaExtra = value; }
        EstadosPersonaje getEstado() { return this->estado; }
        const sf::Vector2f& obtenerPosicion();
        void quieto(float x, float y);
        void cmd();
        void update();
};

#endif // LUFFY_H
