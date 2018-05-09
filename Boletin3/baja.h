#ifndef BAJA_H_INCLUDED
#define BAJA_H_INCLUDED
/**
\file mostrar.h
\brief Archivo que da de baja a los clientes y viajes del sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/


clientes* baja_clientes(int *contador_clientes, clientes *cliente);
clientes* baja_viajes(int contador_clientes, clientes *cliente);

#endif // BAJA_H_INCLUDED
