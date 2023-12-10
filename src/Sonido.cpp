#include "Sonido.h"

Sonido::Sonido() {
        this->bufferMoneda.loadFromFile("sonidos/moneda.ogg");
        this->sonidoMoneda.setBuffer(this->bufferMoneda);
        this->bufferVidaExtra.loadFromFile("sonidos/sonidoVidaExtra.ogg");
        this->sonidoVidaExtra.setBuffer(this->bufferVidaExtra);
        this->bufferMuerte1.loadFromFile("sonidos/sonidoMuerte1.ogg");
        this->sonidoMuerte1.setBuffer(this->bufferMuerte1);
        this->bufferMuerte2.loadFromFile("sonidos/sonidoMuerte2.ogg");
        this->sonidoMuerte2.setBuffer(this->bufferMuerte2);
        this->sonidoMuerte2.setVolume(100);
        this->bufferFinalFx.loadFromFile("sonidos/sonidoFinal.ogg");
        this->sonidoFinalFx.setBuffer(this->bufferFinalFx);
        this->sonidoFinalFx.setVolume(100);
        this->bufferMusicaFinal.loadFromFile("sonidos/musicaFinal.ogg");
        this->musicaFinal.setBuffer(this->bufferMusicaFinal);
        this->musicaFinal.setLoop(true);
        this->musicaFinal.setVolume(70);
}

 void Sonido::reproducirMusicaFondo() {
        // Reproducimos la música de fondo.
        sf::SoundBuffer * buffer = new sf::SoundBuffer;
        buffer->loadFromFile("sonidos/fondo.ogg");
        this->musicaFondo = new sf::Sound;
        this->musicaFondo->setBuffer(*buffer);
        this->musicaFondo->setLoop(true);
        this->musicaFondo->setVolume(80);
        this->musicaFondo->play();
 }

 void Sonido::pausarMusicaFondo() {
    this->musicaFondo->pause();
 }

void Sonido::pararMusicaFondo() {
    this->musicaFondo->stop();
 }

void Sonido::reanudarMusicaFondo() {
    this->musicaFondo->play();
 }

int Sonido::estadoMusicaFondo() {
    return this->musicaFondo->getStatus();
 }

void Sonido::reproducirSonidoMoneda() {
    this->sonidoMoneda.play();
 }

void Sonido::reproducirSonidoVidaExra() {
    this->sonidoVidaExtra.play();
}

void Sonido::reproducirSonidoMuerte1() {
    this->sonidoMuerte1.play();
}

void Sonido::reproducirSonidoMuerte2() {
    this->sonidoMuerte2.play();
}

void Sonido::reproducirSonidoFinalFx() {
    this->sonidoFinalFx.play();
}

void Sonido::reproducirMusicaFinal() {
    this->musicaFinal.play();
}

void Sonido::pararMusicaFinal() {
    this->musicaFinal.stop();
}
