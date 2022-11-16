#include <cstdio>
#include "ArchivoEstadistica.h"
using namespace std;



Jugador ArchivoEstadistica::guardar(Jugador jugador)
{
    FILE* pFile;

    jugador.setCodigo(generarCodigo());

    pFile = fopen("Jugadores.dat", "ab+");
  
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo" << endl;
        exit(1552);
    }

    fwrite(&jugador, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return jugador;
}

int ArchivoEstadistica::generarCodigo()
{
    return cantidadJugador() + 1;
}

int ArchivoEstadistica::cantidadJugador()
{
    FILE* pFile;
    int cantidad = 0;
    Jugador Jugador;

    pFile = fopen("Jugadores.dat", "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof(Jugador);

    fclose(pFile);

    return cantidad;
}

void ArchivoEstadistica::leerJugador(Jugador Jugadors[], int cantidad)
{
    FILE* pFile;
    pFile = fopen("Jugadores.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
  
    fread(Jugadors, sizeof(Jugador), cantidad, pFile);

    fclose(pFile);
}
bool ArchivoEstadistica::leerDeDisco(Jugador * jugador,int pos){
    FILE *p;
    p=fopen("Jugadores.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof *jugador, 0);
    bool leyo=fread(jugador, sizeof *(jugador), 1, p);
    fclose(p);
    return leyo;
}