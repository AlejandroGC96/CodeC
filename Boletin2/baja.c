#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "buscar.h"

void baja_viajes2(int i) //Da de baja a los viajes del cliente eliminando el cliente
{
    int v=0;
    for(; v<=49; v++)
    {
        strcpy(clientes[i].viajes[v].id,"/0");
        strcpy(clientes[i].viajes[v].hotel,"/0");
        strcpy(clientes[i].viajes[v].ciudad_destino,"/0");
        strcpy(clientes[i].viajes[v].noches,"/0");
        strcpy(clientes[i].viajes[v].precio_alojamiento,"/0");
        strcpy(clientes[i].viajes[v].precio_desplazamiento,"/0");
        strcpy(clientes[i].viajes[v].transporte,"/0");
    }


}
int baja_clientes()
{

    char dni[13];
    char opcion;
    char nombre_fichero[150];
    int i=0;

     FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        exit (EXIT_FAILURE);
    }

    fgets(dni,15,fichero);
    i=buscar_cliente(dni);
    if(i==-1)
    {
        printf("No existe el usuario\n");
        return 1;
    }
    if(clientes[i].contador_viajes>0)
    {
        printf("El cliente %s tiene viajes en su cuenta, si los elimina seran borrados\n",clientes[i].nombre);

    }
    printf("El cliente con nombre: %s sera eliminado. Continuar? s/n\n",clientes[i].nombre);
    opcion=getc(stdin);
    if(opcion!='n')
    {
        clientes[i].usuario_en_uso=0;
        clientes[i].contador_viajes=0;
        baja_viajes2(i);
        printf("Usuario eliminado\n");
        return 0;
    }
    else
        printf("Operacion cancelada. Saliendo.......\n");
    return 1;

}



int baja_viajes()
{


    char *dni;
    char id[15];
    char nombre_fichero[150];
    char id2[15];
    int i=0;
    int v=0;

    FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
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


