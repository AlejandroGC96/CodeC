#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(i==-1)
    {
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



int baja_viajes()
{


    char *dni;
    char id[15];
    char id2[15];
    int i=0;
    int v=0;

    FILE *fichero;


    if ((fichero = fopen("baja1.txt", "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        exit (EXIT_FAILURE);
    }

    fgets(id,15,fichero);
    strcpy(id2,id);
    dni= strtok(id, "_");//Acorta para buscar un usuario por su DNI
    fclose(fichero);
    i=buscar_cliente(dni);
    if(i==-1)
    {
        printf("No existe ningun cliente con ese DNI %s\n",dni);

        return 1;
    }
    else
    {
        printf("Cliente %s encontrado\n",clientes[i].nombre);
        v=buscar_viaje(i,id2);
        if(v==-1)
        {
            printf("El viaje asignado no existe\n");

            return 1;


        }
        else
        {
            strcpy(clientes[i].viajes[v].id,"/0");
            strcpy(clientes[i].viajes[v].hotel,"/0");
            strcpy(clientes[i].viajes[v].ciudad_destino,"/0");
            strcpy(clientes[i].viajes[v].noches,"/0");
            strcpy(clientes[i].viajes[v].precio_alojamiento,"/0");
            strcpy(clientes[i].viajes[v].precio_desplazamiento,"/0");
            strcpy(clientes[i].viajes[v].transporte,"/0");
            clientes[i].contador_viajes--;
            printf("Viaje borrado\n");
            return 0;

        }

    }

    return 1;
}
