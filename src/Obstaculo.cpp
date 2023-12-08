#include "Obstaculo.h"

Obstaculo::Obstaculo() {}

void Obstaculo::configurar(std::string recurso, int posicionX, int posicionY) {
    if(!this->inicializado) {
        sf::Texture * obstaculoTextura = new sf::Texture;
        obstaculoTextura->loadFromFile(recurso);
        this->spriteObstaculo = new sf::Sprite(*obstaculoTextura);
    }
    this->inicializado = true;
    this->spriteObstaculo->setPosition(posicionX, posicionY);
}

 const sf::Vector2f& Obstaculo::obtenerPosicion() {
    return this->spriteObstaculo->getPosition();
 }

 void Obstaculo::setearPosicion(int posicionX, int posicionY) {
    this->spriteObstaculo->setPosition(posicionX,posicionY);
 }
