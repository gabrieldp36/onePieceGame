#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sonido.h"
#include "Camara.h"
#include "Pantalla.h"
#include "Obstaculo.h"
#include "Luffy.h"
#include "EstadosJuego.h"
#include "EstadosLuffy.h"

class Game
{
    private:
        // Estado juego.
        EstadosJuego estadoJuego = EJECUTANDO;
        // Ventana.
        sf::RenderWindow * ventana;
        // Eventos
        sf::Event * evento;
        // Objeto cámara.
        Camara camara;
        bool corregirEjeX = false;
        // Pantallas del juego.
        Pantalla pantalla;
        // Personaje
        Luffy luffy;
        // Objeto Sonido.
        Sonido sonido;
        // Obstaculos
        Obstaculo obstaculoInicio;
        Obstaculo arbol1;
        Obstaculo obsIntermedio1;
        Obstaculo obsIntermedio2;
        Obstaculo obsIntermedio3;
        Obstaculo obsIntermedio4;
        Obstaculo obsIntermedio5;
        Obstaculo obsIntermedio6;
        Obstaculo obsIntermedio7;
        Obstaculo obsIntermedio8;
        Obstaculo obsIntermedio9;
        Obstaculo obsIntermedio10;
        Obstaculo obsIntermedio11;
        Obstaculo obsIntermedio12;
        Obstaculo obsIntermedio13;
        Obstaculo obsIntermedio14;
        Obstaculo obsIntermedio15;
        Obstaculo obsIntermedio16;
        Obstaculo obsIntermedio17;
        Obstaculo obsIntermedio18;
        Obstaculo obsIntermedio19;
        Obstaculo obsIntermedio20;
        Obstaculo obstaculoFinal;
        Obstaculo onePiece;
        Obstaculo arbol2;
        Obstaculo moneda1;
        Obstaculo moneda2;
        Obstaculo moneda3;
        Obstaculo moneda4;
        Obstaculo moneda5;
        Obstaculo moneda6;
        Obstaculo moneda7;
        Obstaculo moneda8;
        Obstaculo moneda9;
        Obstaculo vidaExtraPersonaje;
        // Movimiento obstáculos.
        float incrementador = 0;
        float recorrido = 200;
        bool incrementar = true;
        // Banderas booleanas.
        bool inicio = true;
        bool perdio = false;
        bool reinicio = false;
        bool victoria = false;
    public:
        Game(sf::Vector2i dimensiones, std::string titulo);
        void update();
        void pantallaInicioGame();
        void pantallaDerrota();
        void pantallaFinal();
        void eventosGame();
        void eventosCamara();
        void eventosPersonaje();
        void verificarMuerte();
        void configEscenario();
        void movimientoPlataformas();
        void empujarLuffy(std::string direccion, int fuerza);
        void configMarcadores();
        void reposicionarMarcadores();
        void dibujar();
        void checkCollision();
        void reiniciarJuego();
};

#endif // GAME_H
