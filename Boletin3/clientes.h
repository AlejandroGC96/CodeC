#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "viajes.h"

typedef struct cliente{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;
    Lista_viajes viajes;

}clientes;

typedef struct Nodo_clientes{

    clientes *clientes;
    struct Nodo_clientes* siguiente;

}Nodo_clientes;

Nodo_clientes *Lista_clientes;
Nodo_clientes *Posicion_clientes;

#endif // CLIENTES_H_INCLUDED
