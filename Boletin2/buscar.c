#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alta.h"

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

/*
int buscar_viaje(int i,char *id)
{

    int v=0;
    char id_2[11];
    int comparacion=0;

    for(v=0; v<49; v++)
    {

        strncpy(id_2,clientes[i].viajes[v].id,11);

        comparacion=strcmp(id,id_2);
        if( comparacion == 0)
        {
            return v;
        }

    }
    return -1;
}

*/
