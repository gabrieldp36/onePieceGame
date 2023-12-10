#ifndef SONIDO_H
#define SONIDO_H

#include <SFML/Audio.hpp>

class Sonido
{
    private:
    // Musica de fondo.
    sf::Sound * musicaFondo;
    // Sonido moneda.
    sf::SoundBuffer  bufferMoneda;
    sf::Sound sonidoMoneda;
    // Sonido vida extra.
    sf::SoundBuffer  bufferVidaExtra;
    sf::Sound sonidoVidaExtra;
    // Sonido muerte 1.
    sf::SoundBuffer  bufferMuerte1;
    sf::Sound sonidoMuerte1;
    // Sonido muerte 2.
    sf::SoundBuffer  bufferMuerte2;
    sf::Sound sonidoMuerte2;
    // Sonido final.
    sf::SoundBuffer  bufferFinalFx;
    sf::Sound sonidoFinalFx;
    // Musica final.
    sf::SoundBuffer  bufferMusicaFinal;
    sf::Sound musicaFinal;

    public:
        Sonido();
        void reproducirMusicaFondo();
        void pararMusicaFondo();
        void pausarMusicaFondo();
        void reanudarMusicaFondo();
        int estadoMusicaFondo();
        void reproducirSonidoMoneda();
        void reproducirSonidoVidaExra();
        void reproducirSonidoMuerte1();
        void reproducirSonidoMuerte2();
        void reproducirSonidoFinalFx();
        void reproducirMusicaFinal();
        void pararMusicaFinal();
};

#endif // SONIDO_H
