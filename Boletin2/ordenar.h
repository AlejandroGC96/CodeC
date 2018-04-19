#ifndef ORDENAR_H_INCLUDED
#define ORDENAR_H_INCLUDED
/**
\file ordenar.h
\brief Archivo para ordenar los datos en el sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/

int ordenar(clientes *cliente, int contador);
void swap(clientes *xp, clientes *yp);
void bubbleSort(clientes *cliente, int n);
void swap2(viaje *xp, viaje *yp);

#endif // ORDENAR_H_INCLUDED
