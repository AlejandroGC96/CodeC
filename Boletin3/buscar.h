#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED
/**
\file buscar.h
\brief Archivo con la estructura de los clientes del sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/

int buscar_cliente(char *dni, int contador, clientes *cliente);
int buscar_viaje(int i, char *id, clientes *cliente);

#endif // BUSCAR_H_INCLUDED
