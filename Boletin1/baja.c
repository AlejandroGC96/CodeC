#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "buscar.h"

int baja_clientes()
{

    char dni[13];
    char opcion;
    int i=0;
    printf("Introduce el DNI del usuario que quieres eliminiar\n");
    gets(dni);
    i=buscar_cliente(dni);
    if(i==-1){
        printf("No existe el usuario\n");
        return 1;
    }
    printf("El cliente con nombre: %s sera eliminado. Continuar? s/n\n",clientes[i].nombre);
    opcion=getc(stdin);
    if(opcion!='n')
    {
        clientes[i].usuario_en_uso=0;
        printf("Usuario eliminado");
        return 0;
    }
    else
        printf("Operacion cancelada. Saliendo.......");
    return 1;

}
