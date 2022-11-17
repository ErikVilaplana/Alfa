#include <cstdio>
#include "ArchivoEstadistica.h"

#include "JugaEsta.h"
using namespace std;



bool ArchivoEstadistica::guardar(JugaEsta jugador)
{
    FILE* pFile;

    /*jugador.setCodigo(generarCodigo());*/

    pFile = fopen("Jugadores.dat", "ab+");
  
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo" << endl;
        exit(1552);
    }

   bool ok = fwrite(&jugador, sizeof(JugaEsta), 1, pFile);

    fclose(pFile);

    return ok;
}


bool ArchivoEstadistica::leerDeDisco(JugaEsta jugador,int pos){
        FILE* p = fopen("Jugadores.dat", "rb");
        if (p == NULL) {
            return false;
        }
        fseek(p, pos * sizeof(JugaEsta), SEEK_SET);
        bool ok = fread(&jugador, sizeof(JugaEsta), 1, p);
        fclose(p);
        return ok;
    }

/*bool ArchivoEstadistica::leerDeDisco(Jugador * jugador,int pos){
    FILE *p;
    p=fopen("Jugadores.dat","rb");
    if(p==NULL) return false;
    fseek(p,pos*sizeof *jugador, 0);
    bool leyo=fread(jugador, sizeof *(jugador), 1, p);
    fclose(p);
    return leyo;
}*/