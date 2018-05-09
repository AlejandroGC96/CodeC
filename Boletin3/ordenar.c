#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alta.h"
/**
\file ordenar.c
\brief Archivo con la estructura de los clientes del sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/

void swap(clientes *xp, clientes *yp)//Cambia la posicion de los punteros
{
    clientes temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swap2(viaje *xp, viaje *yp)
{
    viaje temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(clientes *cliente, int n)//Implementacion del algoritmo de la burbuja
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if ((strcmp(cliente[j].apellidos, cliente[j+1].apellidos))>0)
              swap(&cliente[j], &cliente[j+1]);
}


int ordenar(clientes *cliente, int contador){

    bubbleSort(cliente, contador);
    return 0;
}
