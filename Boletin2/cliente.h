#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "viajes.h"
/**
\file cliente.h
\brief Archivo con la estructura de los clientes del sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/
typedef struct cliente{

char *dni;
char *nombre;
char *apellidos;
char *direccion;
int contador_de_viajes;
viaje *viajes;

}clientes;


#endif // CLIENTE_H_INCLUDED
