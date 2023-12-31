#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Obstaculo
{
    private:
        sf::Sprite * spriteObstaculo;
        bool inicializado = false;

    public:
        Obstaculo();
        sf::Sprite * getSpriteObstaculo() { return this->spriteObstaculo; }
        void configurar(std::string recurso, int posicionX, int posicionY);
        const sf::Vector2f& obtenerPosicion();
        void setearPosicion(int posicionX, int posicionY);
};

#endif // OBSTACULO_H
