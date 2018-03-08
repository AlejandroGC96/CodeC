#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "alta.h"

int buscar_cliente(char *dni)
{
    int i=0;
    int comparacion=0;
    for(i=0; i<=MAX_CLIENTES; i++)
    {
        comparacion=strcmp(dni,clientes[i].dni);
        if( comparacion == 0)
        {
            return i;
        }

    }
    return -1;
}
/*

int buscar_viaje(char *dni,char *id){

int i=0;





}
*/
