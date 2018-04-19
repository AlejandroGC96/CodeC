#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alta.h"
/**
\file buscar.c
\brief Busca viajes y clientes en el sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/


int buscar_cliente(char *dni, int contador, clientes *cliente)//Return el valor de la posicion del cliente que estamos buscando
{
    int i=0;
    int comparacion=0;
    for(i=0; i<contador; i++)
    {
        comparacion=strcmp(dni,cliente[i].dni);
        if( comparacion == 0)
        {
            return i;
        }

    }
    return -1;
}


int buscar_viaje(int i,char *id,clientes *cliente)
{

    int v=0;
    char *id_2;
    int comparacion=0;
    id_2=malloc(150*sizeof(char));
    for(v=0; v<cliente[i].contador_de_viajes; v++)
    {

        strncpy(id_2,cliente[i].viajes[v].id,11);

        comparacion=strcmp(id,id_2);
        if( comparacion == 0)
        {
            return v;
        }

    }
    return -1;
}


