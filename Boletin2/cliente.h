#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "viajes.h"
typedef struct cliente{

char *dni;
char *nombre;
char *apellidos;
char *direccion;
int contador_de_viajes;
viaje *viajes;

}clientes;


#endif // CLIENTE_H_INCLUDED
