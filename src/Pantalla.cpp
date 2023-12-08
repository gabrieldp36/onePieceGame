#include "Pantalla.h"

Pantalla::Pantalla()
{
    // Pantalla inicio
    sf::Texture * pantallaInicio = new sf::Texture;
    pantallaInicio->loadFromFile("sprites/pantallaInicio.png");
    this->spriteInicio = new sf::Sprite(*pantallaInicio);
    this->spriteInicio->setPosition(0,-20);

    // Fondo del juego.
    sf::Texture * fondo = new sf::Texture();
    fondo->loadFromFile("sprites/fondo.png");
    this->spriteFondo = new sf::Sprite(*fondo);
    this->spriteFondo->setPosition(-1055,0);

    // Pantalla Derrota
    sf::Texture * pantallaDerrotaTextura = new sf::Texture;
    pantallaDerrotaTextura->loadFromFile("sprites/pantallaDerrota.png");
    this->spriteDerrota = new sf::Sprite(*pantallaDerrotaTextura);
    this->spriteDerrota->setPosition(0,0);

    // Pantalla Final
    sf::Texture * pantallaFinalTextura = new sf::Texture;
    pantallaFinalTextura->loadFromFile("sprites/pantallaFinal.png");
    this->spriteFinal = new sf::Sprite(*pantallaFinalTextura);
    this->spriteFinal->setPosition(0,0);

}

