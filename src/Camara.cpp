#include "Camara.h"

Camara::Camara()
{
        // Configuración inicial de la cámara.
        this->vistaPointer = new sf::View;
        this->vistaPointer->setSize(sf::Vector2f(1000.f, 600.f) );
        this->vistaPointer->setCenter({500,300});
        this->movimientoVoluntario = 0;
}

void Camara::moverCamara(float personajeVelocidad, sf::RenderWindow * ventana) {
        this->vistaPointer->move(personajeVelocidad, 0);
        ventana->setView(*this->vistaPointer);
}

void Camara::setMovimientoVoluntario(int value) {
    this->movimientoVoluntario += value;
}

void Camara::reiniciarMovimientoVoluntario() {
    this->movimientoVoluntario = 0;
}
