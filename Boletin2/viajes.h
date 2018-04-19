#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED
/**
\file viajes.h
\brief Archivo con la estructura de los viajes en el sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/

typedef struct viajes
{

    char *id;
    char *ciudad_destino;
    char *hotel;
    char *noches;
    char *transporte;
    char *precio_alojamiento;
    char *precio_desplazamiento;

} viaje;
#endif // VIAJES_H_INCLUDED
