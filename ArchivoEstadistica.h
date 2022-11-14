#pragma once
#include <iostream>
#include "Jugador.h"

class ArchivoEstadistica
{

public:
    Jugador guardar(Jugador jugador);
    int generarCodigo();
    int cantidadJugador();
    void leerJugador(Jugador jugador[], int cantidad);
};
