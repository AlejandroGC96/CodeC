#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define MAX_CLIENTES 19
#define MAX_VIAJES 50
#include "viajes.h"


typedef struct clientes
{

    char dni[13];
    char nombre[20];
    char apellidos[80];
    char direccion[150];
    int contador_viajes;
    int usuario_en_uso;//Si esta en uso se asigna el valor de 1 si no esta ocuapado un valor distinto  de 1
    viaje viajes[MAX_VIAJES];

} cliente;

cliente clientes[MAX_CLIENTES];


#endif // CLIENTES_H_INCLUDED
