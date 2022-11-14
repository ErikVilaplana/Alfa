#include <cstdio>
#include "ArchivoEstadistica.h"
using namespace std;


/*
Jugador ArchivoEstadistica::guardar(Jugador jugador)
{
    FILE* pFile;

    jugador.setCodigo(generarCodigo());

    pFile = fopen("Jugadors.dat", "ab");
  
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo" << endl;
        exit(1552);
    }

    fwrite(&jugador, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return jugador;
}

int ArchivoJugador::generarCodigo()
{
    return cantidadJugadores() + 1;
}

int ArchivoJugador::cantidadJugadors()
{
    FILE* pFile;
    int cantidad = 0;
    Jugador Jugador;

    pFile = fopen("Jugadors.dat", "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Jugador);

    fclose(pFile);

    return cantidad;
}

void ArchivoEstadistica::leerJugadors(Jugador Jugadors[], int cantidad)
{
    FILE* pFile;
    pFile = fopen("Jugadors.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
  
    fread(Jugadors, sizeof(Jugador), cantidad, pFile);

    fclose(pFile);
}*/