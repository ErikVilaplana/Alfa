#pragma once
# include<iostream>
# include<cstring>
using namespace std;
#include "JugaEsta.h"

class ArchivoEstadistica
{

public:
    bool guardar(JugaEsta JugaEsta);
    int generarCodigo();
    int cantidadJugaEsta();
    bool leerDeDisco(JugaEsta &jugador,int pos);
    /*void leerJugaEsta(JugaEsta jugador[], int cantidad);*/
    /*Jugador leerDeDisco(Jugador * jugador,int pos);*/
};
