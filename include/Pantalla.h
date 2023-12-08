#ifndef PANTALLA_H
#define PANTALLA_H

#include <SFML/Graphics.hpp>

class Pantalla
{
    private:
        sf::Sprite * spriteInicio;
        sf::Sprite * spriteFondo;
        sf::Sprite * spriteDerrota;
        sf::Sprite * spriteFinal;

    public:
        Pantalla();
        sf::Sprite * getSpriteInicio() { return this->spriteInicio; }
        sf::Sprite * getSpriteFondo() { return this->spriteFondo; }
        sf::Sprite * getSpriteDerrota() { return this->spriteDerrota; }
        sf::Sprite * getSpriteFinal() { return this->spriteFinal; }
};

#endif // PANTALLA_H
