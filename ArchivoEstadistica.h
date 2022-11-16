#pragma once
# include<iostream>
# include<cstring>
using namespace std;
#include "Jugador.h"

class ArchivoEstadistica
{

public:
    Jugador guardar(Jugador jugador);
    int generarCodigo();
    int cantidadJugador();
    void leerJugador(Jugador jugador[], int cantidad);
    Jugador leerDeDisco(Jugador * jugador,int pos);
};
