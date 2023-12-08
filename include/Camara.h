#ifndef CAMARA_H
#define CAMARA_H

#include <SFML/Graphics.hpp>

class Camara
{
    private:
        sf::View * vistaPointer;
        int movimientoVoluntario;
    public:
        Camara();
         sf::View * getVistaPointer() { return vistaPointer; }
        int getMovimientoVoluntario() { return movimientoVoluntario; };
        void setMovimientoVoluntario(int value);
        void reiniciarMovimientoVoluntario();
        void moverCamara(float personajeVelocidad, sf::RenderWindow * ventana);
};

#endif // CAMARA_H
