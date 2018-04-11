#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "viajes.h"


typedef struct clientes
{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;
    int contador_viajes;
    int usuario_en_uso;//Si esta en uso se asigna el valor de 1 si no esta ocuapado un valor distinto  de 1
    viaje *viajes;

} cliente;



#endif // CLIENTES_H_INCLUDED
