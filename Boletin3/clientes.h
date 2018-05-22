#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "viajes.h"

typedef struct cliente{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;
    int contador_viajes;
    struct viajes *listaviajes;
    struct cliente *siguiente;
    struct cliente *anterior;

}lclientes;



#endif // CLIENTES_H_INCLUDED
