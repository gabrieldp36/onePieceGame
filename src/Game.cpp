#include "Game.h"

Game::Game( sf::Vector2i dimensiones, std::string titulo)
{
        // Reproducimos la música de fondo.
        this->sonido.reproducirMusicaFondo();
        // Creamos la ventana donde se renderiza el juego.
        this->ventana = new sf::RenderWindow( sf::VideoMode(dimensiones.x, dimensiones.y), titulo );
        this->ventana->setFramerateLimit(60);
        // Creamos el objeto evento, para gestionar los eventos del juego.
        this->evento = new sf::Event;
        // Llamamos al método update para renderizar el juego.
        this->update();
}

/*************************************GAME LOOP*************************************/

void Game::update()
{
    // Mendiante el ciclo while vamos reproduciendo el juego mientras la ventana esté abierta.
    while ( this->ventana->isOpen() )
    {
        if(estadoJuego == EJECUTANDO) {
            if(this->inicio) {
               this->pantallaInicioGame();
            } else  if(!this->perdio && !this->inicio && !this->victoria) {
                this->dibujar();
                this->eventosPersonaje();
                this->eventosCamara();
                this->checkCollision();
            } else if(this->perdio) {
                this->pantallaDerrota();
            } else {
                this->pantallaFinal();
            }
        }
        // Eventos del juego.
        this->eventosGame();
    }
}

/******************************DIBUJO DE LOS ELEMENTOS DEL JUEGO*********************/

void Game::dibujar() {
    // En cada update vamos limpiando la vista.
    this->ventana->clear();
    // Dibujamos los elementos que aparecen en pantalla.
    this->ventana->draw( *this->pantalla.getSpriteFondo() );
    // Marcador vidas.
    this->configMarcadores();
    // Escenario
    this->configEscenario();
    //Personaje
    this->ventana->draw( *this->luffy.getSpriteLuffy() );
    // Mostramos lo dibujado en pantalla.
    this->ventana->display();
}

void Game::configMarcadores() {
            if(this->luffy.getVidas() == 2) {
                if( this->luffy.getRecogioVidaExtra() ) {
                    this->luffy.getSpriteVidaLuffy2()->setPosition(this->luffy.getSpriteVidaLuffy1()->getPosition().x, 10);
                    this->luffy.getSpMarcadorMonedas0()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas1()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas2()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas3()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas4()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas5()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas6()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas7()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas8()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                    this->luffy.getSpMarcadorMonedas9()->setPosition( this->luffy.getSpriteVidaLuffy2()->getPosition().x+120, 15);
                }
                this->ventana->draw( *this->luffy.getSpriteVidaLuffy2() );
            } else if (this->luffy.getVidas() == 1 ) {
                this->ventana->draw(* this->luffy.getSpriteVidaLuffy1());
            }
            switch ( this->luffy.getMonedas() ) {
                case 0:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas0());
                break;
                case 1:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas1());
                break;
                case 2:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas2());
                break;
                case 3:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas3());
                break;
                case 4:
                    this->ventana->draw( * this->luffy.getSpMarcadorMonedas4() );
                break;
                case 5:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas5());
                break;
                case 6:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas6());
                break;
                case 7:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas7());
                break;
                case 8:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas8());
                break;
               case 9:
                    this->ventana->draw(* this->luffy.getSpMarcadorMonedas9());
                break;
            }
}

void Game::reposicionarMarcadores() {
        this->luffy.getSpriteVidaLuffy1()->setPosition(20, 10);
        this->luffy.getSpMarcadorMonedas0()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas1()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas2()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas3()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas4()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas5()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas6()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas7()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas8()->setPosition(90, 15);
        this->luffy.getSpMarcadorMonedas9()->setPosition(90, 15);
        if(this->reinicio) {
            this->luffy.getSpriteVidaLuffy2()->setPosition(20, 10);
            this->luffy.getSpMarcadorMonedas0()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas1()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas2()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas3()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas4()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas5()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas6()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas7()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas8()->setPosition(140, 15);
            this->luffy.getSpMarcadorMonedas9()->setPosition(140, 15);
            this->reinicio = false;
        }
}

void Game::configEscenario() {
    // Activamos el movimiento de las plataformas.
    this->movimientoPlataformas();
    // Dibujamos los obstáculos.
    // -----Obstáculo inicial-------.
    this->obstaculoInicio.configurar("sprites/plataformaInicio.png", -20, 495);
    this->ventana->draw( *this->obstaculoInicio.getSpriteObstaculo() );
    this->arbol1.configurar("sprites/arbol1.png", 20, 210);
    this->ventana->draw( *this->arbol1.getSpriteObstaculo() );
    // -----Obstáculos intermedios-------.
    this->obsIntermedio1.configurar("sprites/plataformaIntermedia.png", 590 + this->incrementador, 400);
    this->ventana->draw( *this->obsIntermedio1.getSpriteObstaculo() );
    this->obsIntermedio2.configurar("sprites/plataformaIntermedia2.png", 1000, 250);
    this->ventana->draw( *this->obsIntermedio2.getSpriteObstaculo() );
    this->obsIntermedio3.configurar("sprites/plataformaIntermedia.png", 1360, 350 + this->incrementador);
    this->ventana->draw( *this->obsIntermedio3.getSpriteObstaculo() );
    this->obsIntermedio4.configurar("sprites/plataformaIntermedia.png", 1700 + this->incrementador, 260);
    this->ventana->draw( *this->obsIntermedio4.getSpriteObstaculo() );
    this->obsIntermedio5.configurar("sprites/plataformaIntermedia.png", 2150 + this->incrementador, 500);
    this->ventana->draw( *this->obsIntermedio5.getSpriteObstaculo() );
    this->obsIntermedio6.configurar("sprites/plataformaIntermedia.png", 2590 + this->incrementador, 450);
    this->ventana->draw( *this->obsIntermedio6.getSpriteObstaculo() );
    this->obsIntermedio7.configurar("sprites/plataformaIntermedia.png", 3180, 200+ this->incrementador*2);
    this->ventana->draw( *this->obsIntermedio7.getSpriteObstaculo() );
    this->obsIntermedio8.configurar("sprites/plataformaIntermedia.png", 3560, 192);
    this->ventana->draw( *this->obsIntermedio8.getSpriteObstaculo() );
    this->obsIntermedio9.configurar("sprites/plataformaIntermedia.png", 3930+ this->incrementador*2, 500);
    this->ventana->draw( *this->obsIntermedio9.getSpriteObstaculo() );
    this->obsIntermedio10.configurar("sprites/plataformaIntermedia2.png", 4380, 400);
    this->ventana->draw( *this->obsIntermedio10.getSpriteObstaculo() );
    this->obsIntermedio11.configurar("sprites/plataformaIntermedia2.png", 4780, 400);
    this->ventana->draw( *this->obsIntermedio11.getSpriteObstaculo() );
    this->obsIntermedio12.configurar("sprites/plataformaIntermedia2.png", 5180, 400);
    this->ventana->draw( *this->obsIntermedio12.getSpriteObstaculo() );
    this->obsIntermedio13.configurar("sprites/plataformaIntermedia.png", 5380+ this->incrementador*2, 500);
    this->ventana->draw( *this->obsIntermedio13.getSpriteObstaculo() );
    this->obsIntermedio14.configurar("sprites/plataformaIntermedia2.png", 5780 + this->incrementador, 400);
    this->ventana->draw( *this->obsIntermedio14.getSpriteObstaculo() );
    this->obsIntermedio15.configurar("sprites/plataformaIntermedia2.png", 6180 + this->incrementador, 400);
    this->ventana->draw( *this->obsIntermedio15.getSpriteObstaculo() );
    this->obsIntermedio16.configurar("sprites/plataformaIntermedia2.png", 6580 + this->incrementador, 400);
    this->ventana->draw( *this->obsIntermedio16.getSpriteObstaculo() );
    this->obsIntermedio17.configurar("sprites/plataformaIntermedia2.png", 7080 , 200+this->incrementador*2);
    this->ventana->draw( *this->obsIntermedio17.getSpriteObstaculo() );
    this->obsIntermedio18.configurar("sprites/plataformaIntermedia.png", 7400 , 192);
    this->ventana->draw( *this->obsIntermedio18.getSpriteObstaculo() );
    this->obsIntermedio19.configurar("sprites/plataformaIntermedia.png", 7630 ,400);
    this->ventana->draw( *this->obsIntermedio19.getSpriteObstaculo() );
    this->obsIntermedio20.configurar("sprites/plataformaIntermedia.png", 8000+this->incrementador,350);
    this->ventana->draw( *this->obsIntermedio20.getSpriteObstaculo() );
    // -----Obstáculo final-------.
    this->obstaculoFinal.configurar("sprites/plataformaFinal.png", 8400, 495);
    this->ventana->draw( *this->obstaculoFinal.getSpriteObstaculo() );
    this->onePeace.configurar("sprites/onePeace.png", 8630,430);
    this->ventana->draw( *this->onePeace.getSpriteObstaculo() );
    this->arbol2.configurar("sprites/arbol2.png", 8590, 200);
    this->ventana->draw( *this->arbol2.getSpriteObstaculo() );
    // -----Monedas-----.
    if( this->moneda1.obtenerPosicion().y < 2000 ) {
        this->moneda1.configurar("sprites/moneda.png", 850, 190 );
        this->ventana->draw( *this->moneda1.getSpriteObstaculo() );
    }
    if( this->moneda2.obtenerPosicion().y < 2000 ) {
        this->moneda2.configurar("sprites/moneda.png", 1700, 190);
        this->ventana->draw( *this->moneda2.getSpriteObstaculo() );
    }
    if(this->moneda3.obtenerPosicion().y < 2000) {
        this->moneda3.configurar("sprites/moneda.png", 2500, 450);
        this->ventana->draw( *this->moneda3.getSpriteObstaculo() );
    }
    if(this->moneda4.obtenerPosicion().y < 2000) {
        this->moneda4.configurar("sprites/moneda.png", 4100, 400);
        this->ventana->draw( *this->moneda4.getSpriteObstaculo() );
    }
    if(this->moneda5.obtenerPosicion().y < 2000) {
        this->moneda5.configurar("sprites/moneda.png", 5100, 250);
        this->ventana->draw( *this->moneda5.getSpriteObstaculo() );
    }
    if(this->moneda6.obtenerPosicion().y < 2000) {
        this->moneda6.configurar("sprites/moneda.png", 6200, 250);
        this->ventana->draw( *this->moneda6.getSpriteObstaculo() );
    }
    if(this->moneda7.obtenerPosicion().y < 2000) {
        this->moneda7.configurar("sprites/moneda.png", 7200, 150);
        this->ventana->draw( *this->moneda7.getSpriteObstaculo() );
    }
    if(this->moneda8.obtenerPosicion().y < 2000) {
        this->moneda8.configurar("sprites/moneda.png", 7500, 100);
        this->ventana->draw( *this->moneda8.getSpriteObstaculo() );
    }
    if(this->moneda9.obtenerPosicion().y < 2000) {
        this->moneda9.configurar("sprites/moneda.png", 8200, 250);
        this->ventana->draw( *this->moneda9.getSpriteObstaculo() );
    }
    // Vida extra.
    if( !this->luffy.getRecogioVidaExtra() ) {
        this->vidaExtraPersonaje.configurar("sprites/vidaExtra.png", 3650, 160);
        this->ventana->draw( *this->vidaExtraPersonaje.getSpriteObstaculo() );
    }
}

/****************************MOVIMIENTO DE LAS PLATAFORMAS**********************/

void Game::movimientoPlataformas() {
    if (this->incrementador <= this->recorrido && this->incrementar) {
        this->incrementador += 2;
    } else  {
        this->incrementar = false;
        this->incrementador -= 2;
        if(this->incrementador == 0 ) {
            this->incrementar = true;
        }
    }
}

void Game::empujarLuffy(std::string direccion, int fuerza) {
        if(luffy.getEstado() == QUIETO) {
                if(direccion == "horizontal") {
                    if (this->incrementador <= this->recorrido && this->incrementar) {
                        this->luffy.getSpriteLuffy()->move(fuerza,0);
                    } else  {
                        this->luffy.getSpriteLuffy()->move(fuerza*-1,0);
                    }
                } else if(direccion == "vertical") {
                    if (this->incrementador <= this->recorrido && this->incrementar) {
                        this->luffy.getSpriteLuffy()->move(0,fuerza);
                    } else  {
                        this->luffy.getSpriteLuffy()->move(0,fuerza*-1);
                    }
                }
        }
}

/****************************************COLISIONES***************************************/

 void Game::checkCollision() {
    // Plataformas.
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoInicio.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obstaculoInicio.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio1.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio1.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio2.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio2.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 4);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio3.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio3.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("vertical", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio4.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio4.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio5.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio5.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio6.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio6.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio7.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio7.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("vertical", 4);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio8.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio8.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio9.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio9.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 4);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio10.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio10.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 3);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio11.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio11.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 3);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio12.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio12.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 3);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio13.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio13.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 4);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio14.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio14.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 5);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio15.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio15.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 5);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio16.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio16.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 5);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio17.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio17.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 5);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio18.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio18.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio19.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio19.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
        this->empujarLuffy("horizontal", 2);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )  &&  this->luffy.getVelocidadSalto() < 0 ) {
        this->luffy.quieto(this->luffy.obtenerPosicion().x, this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds().top -  this->luffy.getSpriteLuffy()->getGlobalBounds().height);
    }
    // Monedas
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda1.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda1.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda2.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda2.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda3.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda3.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda4.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda4.setearPosicion(0,2000);
    }

    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda5.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda5.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda6.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda6.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda7.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda7.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda8.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda8.setearPosicion(0,2000);
    }
    if( this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->moneda9.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoMoneda();
        this->luffy.sumarMonedas();
        this->moneda9.setearPosicion(0,2000);
    }
    // Vida extra.
    if( !this->luffy.getRecogioVidaExtra() && this->luffy.getVidas() < 2 && this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->vidaExtraPersonaje.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.reproducirSonidoVidaExra();
        this->luffy.setRecogioVidaExtra(true);
        this->luffy.sumarVida();
    }
    // One peace;
    if(this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->onePeace.getSpriteObstaculo()->getGlobalBounds() ) ) {
        this->sonido.pararMusicaFondo();
        this->victoria = true;
        this->sonido.reproducirSonidoFinalFx();
        if(this->luffy.getMonedas() == 9) {
            this->sonido.reproducirMusicaFinal();
        }
    }
 }

/***************************************EVENTOS DEL PERSONAJE*********************************/

void Game::eventosPersonaje() {
     this->luffy.cmd();
     this->luffy.update();
     this->verificarMuerte();
}

void Game::verificarMuerte() {
        if( this->luffy.obtenerPosicion().y > 600 ) {
            this->luffy.restarVida();
            if(this->luffy.getVidas() == 0) {
                    this->perdio = true;
                    this->sonido.reproducirSonidoVidaExra();
            }
            // Limpiamos la cámara.
            this->camara.getVistaPointer()->setSize(sf::Vector2f(1000.f, 600.f) );
            this->camara.getVistaPointer()->setCenter({500,300});
            this->ventana->setView(*this->camara.getVistaPointer());
            // Reposicionamos personaje + marcadores.
            this->luffy.quieto(180, 352);
            this->reposicionarMarcadores();
            this->camara.reiniciarMovimientoVoluntario();
            if(!this->perdio) {
                if( !luffy.getRecogioVidaExtra() ) {
                    this->sonido.reproducirSonidoMuerte1();
                } else {
                    this->sonido.reproducirSonidoMuerte2();
                }
            }
     }
}

/**************************************EVENTOS DE LA CÁMARA*********************************/

void Game::eventosCamara() {
    // Movimiento Cámara.
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::D)  ) {
        //Cunado se trasladó más de 300 pixeles hacemos que la cámara siga al personaje.
         if(
            !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio2.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio10.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio11.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio12.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio14.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio15.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio16.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio17.getSpriteObstaculo()->getGlobalBounds() )
            && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )
            && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )
        ) {
            if( this->luffy.obtenerPosicion().x > 300 ) {
                this->corregirEjeX = true;
                this->luffy.getSpriteVidaLuffy2()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpriteVidaLuffy1()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas0()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas1()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas2()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas3()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas4()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas5()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas6()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas7()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas8()->move(this->luffy.getVelocityX()+0.7,0);
                this->luffy.getSpMarcadorMonedas9()->move(this->luffy.getVelocityX()+0.7,0);
                this->camara.moverCamara(this->luffy.getVelocityX()+0.7, this->ventana);
                // Regulación movimiento voluntario.
                if(this->camara.getMovimientoVoluntario() >= 5) {
                    this->camara.setMovimientoVoluntario( (this->luffy.getVelocityX()+0.7)*-1);
                }
             }
        } else {
            if(
                !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )
                && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )
            ) {
                this->luffy.getSpriteVidaLuffy2()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpriteVidaLuffy1()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas0()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas1()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas2()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas3()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas4()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas5()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas6()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas7()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas8()->move(this->luffy.getVelocityX()-5,0);
                this->luffy.getSpMarcadorMonedas9()->move(this->luffy.getVelocityX()-5,0);
                this->camara.moverCamara(this->luffy.getVelocityX()-5, this->ventana);
            }
        }
    }
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
        if(
            !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio2.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio10.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio11.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio12.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio14.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio15.getSpriteObstaculo()->getGlobalBounds() )
            && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio16.getSpriteObstaculo()->getGlobalBounds() )
           && !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio17.getSpriteObstaculo()->getGlobalBounds() )
           && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )
           && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )
        ) {
            //Cunado se trasladó más de 300 pixeles hacemos que la cámara siga al personaje.
                if( this->luffy.obtenerPosicion().x > 300 ) {
                    this->luffy.getSpriteVidaLuffy2()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpriteVidaLuffy1()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas0()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas1()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas2()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas3()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas4()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas5()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas6()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas7()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas8()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->luffy.getSpMarcadorMonedas9()->move( (this->luffy.getVelocityX()+0.7)*-1,0);
                    this->camara.moverCamara((this->luffy.getVelocityX()+0.7)*-1, this->ventana);
                 }
                  if( this->luffy.obtenerPosicion().x < 30 ) {
                        if(this->corregirEjeX) {
                            this->luffy.getSpriteVidaLuffy2()->move(-8,0);
                            this->luffy.getSpriteVidaLuffy1()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas0()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas1()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas2()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas3()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas4()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas5()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas6()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas7()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas8()->move(-8,0);
                            this->luffy.getSpMarcadorMonedas9()->move(-8,0);
                            this->camara.moverCamara(-8, this->ventana);
                            this->corregirEjeX = false;
                        }
                 }
                // Correcion cámara plataforma hielo.
            } else {
                  if(
                        !this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )
                        && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )
                    ) {
                        this->luffy.getSpriteVidaLuffy2()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpriteVidaLuffy1()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas0()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas1()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas2()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas3()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas4()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas5()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas6()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas7()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas8()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->luffy.getSpMarcadorMonedas9()->move((this->luffy.getVelocityX()-5)*-1,0);
                        this->camara.moverCamara((this->luffy.getVelocityX()-5)*-1, this->ventana);
                  }
            }
       }
        // Movimiento voluntario de la cámara.
       if(
            ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obsIntermedio20.getSpriteObstaculo()->getGlobalBounds() )
            && ! this->luffy.getSpriteLuffy()->getGlobalBounds().intersects( this->obstaculoFinal.getSpriteObstaculo()->getGlobalBounds() )
        ) {
              if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
                   if(this->camara.getMovimientoVoluntario() <= 800) {
                        this->camara.setMovimientoVoluntario(5);
                        this->luffy.getSpriteVidaLuffy2()->move(5,0);
                        this->luffy.getSpriteVidaLuffy1()->move(5,0);
                        this->luffy.getSpMarcadorMonedas0()->move(5,0);
                        this->luffy.getSpMarcadorMonedas1()->move(5,0);
                        this->luffy.getSpMarcadorMonedas2()->move(5,0);
                        this->luffy.getSpMarcadorMonedas3()->move(5,0);
                        this->luffy.getSpMarcadorMonedas4()->move(5,0);
                        this->luffy.getSpMarcadorMonedas5()->move(5,0);
                        this->luffy.getSpMarcadorMonedas6()->move(5,0);
                        this->luffy.getSpMarcadorMonedas7()->move(5,0);
                        this->luffy.getSpMarcadorMonedas8()->move(5,0);
                        this->luffy.getSpMarcadorMonedas9()->move(5,0);
                        this->camara.moverCamara(5, this->ventana);
                    }
               }
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
                   if(this->camara.getMovimientoVoluntario() >= -800) {
                        this->camara.setMovimientoVoluntario(-5);
                        this->luffy.getSpriteVidaLuffy2()->move(-5,0);
                        this->luffy.getSpriteVidaLuffy1()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas0()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas1()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas2()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas3()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas4()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas5()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas6()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas7()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas8()->move(-5,0);
                        this->luffy.getSpMarcadorMonedas9()->move(-5,0);
                        this->camara.moverCamara(-5, this->ventana);
                   }
               }
               if( sf::Keyboard::isKeyPressed(sf::Keyboard::M) ) {
                    this->luffy.getSpriteVidaLuffy2()->move(5,0);
                    this->luffy.getSpriteVidaLuffy1()->move(5,0);
                    this->luffy.getSpMarcadorMonedas0()->move(5,0);
                    this->luffy.getSpMarcadorMonedas1()->move(5,0);
                    this->luffy.getSpMarcadorMonedas2()->move(5,0);
                    this->luffy.getSpMarcadorMonedas3()->move(5,0);
                    this->luffy.getSpMarcadorMonedas4()->move(5,0);
                    this->luffy.getSpMarcadorMonedas5()->move(5,0);
                    this->luffy.getSpMarcadorMonedas6()->move(5,0);
                    this->luffy.getSpMarcadorMonedas7()->move(5,0);
                    this->luffy.getSpMarcadorMonedas8()->move(5,0);
                    this->luffy.getSpMarcadorMonedas9()->move(5,0);
               }
               if( sf::Keyboard::isKeyPressed(sf::Keyboard::N) ) {
                    this->luffy.getSpriteVidaLuffy2()->move(-5,0);
                    this->luffy.getSpriteVidaLuffy1()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas0()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas1()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas2()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas3()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas4()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas5()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas6()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas7()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas8()->move(-5,0);
                    this->luffy.getSpMarcadorMonedas9()->move(-5,0);
               }
        }
}

/**************************************EVENTOS DEL JUEGO*********************************/

void Game::eventosGame() {
    while(  this->ventana->pollEvent(*this->evento)  )  {
        switch(this->evento->type) {
            // Evento cierre de ventana
            case sf::Event::Closed:
                this->ventana->close();
                exit(1);
            break;
            // Eventos de teclado.
            case  sf::Event::KeyPressed:
                // Control de audio.
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::R) ) {
                        if( this->sonido.estadoMusicaFondo() == 2) {
                            this->sonido.pausarMusicaFondo();
                        } else {
                            this->sonido.reanudarMusicaFondo();
                        }
                }
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::P) ) {
                    this->estadoJuego = PAUSADO;
                    this->sonido.pausarMusicaFondo();
                }
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
                    this->estadoJuego = EJECUTANDO;
                    this->sonido.reanudarMusicaFondo();
                }
            }
        }
}

/**************************************PANTALLAS***************************************/
void Game::pantallaInicioGame() {
    // Limpiamos la ventana
    this->ventana->clear();
    // Dibujamos los elementos que aparecen en pantalla.
    this->ventana->draw( *this->pantalla.getSpriteInicio() );
    // Mostramos lo dibujado en pantalla.
     this->ventana->display();
    //Gestionamos los eventos que pueden ocurrir mientras se muestra la pantalla.
    while( this->ventana->pollEvent(*this->evento) ) {
        // Gestión de eventos.
        switch( this->evento->type) {
            // Evento de cierre de ventana
            case sf::Event::Closed:
                this->ventana->close();
                exit(1);
            break;
            // Eventos de teclado.
            case  sf::Event::KeyPressed:
                // Cambio de pantalla de inicio al juego.
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ) {
                    this->inicio = false;
                }
            break;
        }
    }
}


void Game::pantallaDerrota() {
    // Paramos la musica.
    this->sonido.pararMusicaFondo();
    // Limpiamos la ventana y la cámara.
    this->ventana->clear();
    this->camara.getVistaPointer()->setSize(sf::Vector2f(1000.f, 600.f) );
    this->camara.getVistaPointer()->setCenter({500,300});
    this->ventana->setView(*this->camara.getVistaPointer());
    // Dibujamos los elementos que aparecen en pantalla.
    this->ventana->draw( *this->pantalla.getSpriteDerrota() );
    // Mostramos lo dibujado en pantalla.
     this->ventana->display();
    //Gestionamos los eventos que pueden ocurrir mientras se muestra la pantalla.
    while( this->ventana->pollEvent(*this->evento) ) {
        // Gestión de eventos.
        switch( this->evento->type) {
            // Evento de cierre de ventana
            case sf::Event::Closed:
                this->ventana->close();
                exit(1);
            break;
            // Eventos de teclado.
            case  sf::Event::KeyPressed:
                // Cambio de pantalla de inicio al juego.
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
                    this->reiniciarJuego();
                }
            break;
        }
    }
}

void Game::reiniciarJuego() {
    this->reinicio = true;
    this->luffy.quieto(180, 352);
    this->luffy.setVida(2);
    this->luffy.setMonedas(0);
    this->luffy.setRecogioVidaExtra(false);
    this->reposicionarMarcadores();
    this->camara.reiniciarMovimientoVoluntario();
    this->moneda1.setearPosicion(850, 190 );
    this->moneda2.setearPosicion(1700, 190);
    this->moneda3.setearPosicion(2500, 450);
    this->moneda4.setearPosicion(4100, 400);
    this->moneda5.setearPosicion(5100, 250);
    this->moneda6.setearPosicion(6200, 250);
    this->moneda7.setearPosicion(7200, 150);
    this->moneda8.setearPosicion(7500, 100);
    this->moneda9.setearPosicion(8200, 250);
    this->sonido.pararMusicaFinal();
    this->sonido.reanudarMusicaFondo();
    this->perdio = false;
    this->victoria = false;
}

void Game::pantallaFinal() {
    // Limpiamos la ventana y la cámara.
    this->ventana->clear();
    this->camara.getVistaPointer()->setSize(sf::Vector2f(1000.f, 600.f) );
    this->camara.getVistaPointer()->setCenter({500,300});
    this->ventana->setView(*this->camara.getVistaPointer());
    // Dibujamos los elementos que aparecen en pantalla.
    this->ventana->draw( *this->pantalla.getSpriteFinal() );
    // Mostramos lo dibujado en pantalla.
     this->ventana->display();
    //Gestionamos los eventos que pueden ocurrir mientras se muestra la pantalla.
    while( this->ventana->pollEvent(*this->evento) ) {
        // Gestión de eventos.
        switch( this->evento->type) {
            // Evento de cierre de ventana
            case sf::Event::Closed:
                this->ventana->close();
                exit(1);
            break;
            // Eventos de teclado.
            case  sf::Event::KeyPressed:
                // Cambio de pantalla de inicio al juego.
                if( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
                    this->reiniciarJuego();
                }
            break;
        }
    }
}
