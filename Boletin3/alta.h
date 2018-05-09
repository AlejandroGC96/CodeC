#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "cliente.h"

/**
\file alta.h
\brief Archivo con las funciones para dar de alta a los usuarios y sus viajes
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/
clientes *alta_cliente(int *contador_clientes, clientes *cliente);
clientes *alta_viaje(int contador_clientes,clientes *cliente);
#endif // ALTA_H_INCLUDED
