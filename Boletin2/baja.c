#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "buscar.h"
#include "ordenar.h"
/**
\file baja.c
\brief Archivo para dar de baja a los usuarios y clientes en el sistema
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/


clientes* baja_clientes(int *contador_clientes, clientes *cliente)
{

    char *dni;
    char opcion;
    char *nombre_fichero;
    int contador=*contador_clientes;
    int i=0;
    int v=0;
    dni = malloc(150*sizeof(char));
    nombre_fichero = malloc(150*sizeof(char));
    FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente;
    }

    fgets(dni,15,fichero);
    i=buscar_cliente(dni, *contador_clientes, cliente);
    if(i==-1)
    {
        printf("No existe el usuario\n");
        return cliente;
    }
    if(cliente[i].contador_de_viajes>0)
    {
        printf("El cliente %s tiene viajes en su cuenta, si los elimina seran borrados\n",cliente[i].nombre);

    }
    printf("El cliente con nombre: %s sera eliminado. Continuar? s/n\n",cliente[i].nombre);
    opcion=getc(stdin);
    if(opcion!='n')
    {

    for(; v<cliente[i].contador_de_viajes; v++)
    {
            free(cliente[i].viajes[v].id);//Liberamos memoria
            free(cliente[i].viajes[v].hotel);
            free(cliente[i].viajes[v].ciudad_destino);
            free(cliente[i].viajes[v].noches);
            free(cliente[i].viajes[v].precio_alojamiento);
            free(cliente[i].viajes[v].precio_desplazamiento);
            free(cliente[i].viajes[v].transporte);

    }

            free(cliente[i].dni);//Liberamos memoria
            free(cliente[i].nombre);
            free(cliente[i].apellidos);
            free(cliente[i].direccion);
            free(cliente[i].viajes);
            for(v=i; v<contador-1; v++) //Desplaza posiciones despues de haber borrado el que buscamos
                {
                    swap(&cliente[v], &cliente[v+1]);
                }
            contador--;
            *contador_clientes=contador;
            cliente=realloc(cliente, contador*sizeof(clientes));
        printf("Usuario eliminado\n");
        return cliente;
    }
    else
        printf("Operacion cancelada. Saliendo.......\n");
     return cliente;

}



clientes* baja_viajes(int contador_clientes, clientes *cliente)
{


    char *dni;
    char *id;
    char *nombre_fichero;
    char *id2;
    int i=0;
    int v=0;


    nombre_fichero=malloc(150*sizeof(char));
    id=malloc(150*sizeof(char));
    id2=malloc(150*sizeof(char));
    dni=malloc(150*sizeof(char));

    FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente;
    }

    fgets(id,15,fichero);
    strcpy(id2,id);
    dni= strtok(id, "_");//Acorta para buscar un usuario por su DNI
    fclose(fichero);
    i=buscar_cliente(dni, contador_clientes, cliente);
    if(i==-1)
    {
        printf("No existe ningun cliente con ese DNI %s\n",dni);

        return cliente;
    }
    else
    {
        v=buscar_viaje(i, id2, cliente);
        if(v==-1)
        {
            printf("El viaje asignado no existe\n");

            return cliente;


        }
        else
        {
            free(cliente[i].viajes[v].id);//Liberamos memoria
            free(cliente[i].viajes[v].hotel);
            free(cliente[i].viajes[v].ciudad_destino);
            free(cliente[i].viajes[v].noches);
            free(cliente[i].viajes[v].precio_alojamiento);
            free(cliente[i].viajes[v].precio_desplazamiento);
            free(cliente[i].viajes[v].transporte);
            if(cliente[i].contador_de_viajes>1)
            {

                for(; v<cliente[i].contador_de_viajes-1; v++) //Desplaza posiciones en el array despues de haber borrado el que buscamos
                {
                    swap2(&cliente[i].viajes[v], &cliente[i].viajes[v+1]);
                }
                cliente[i].contador_de_viajes--;
                printf("Viaje borrado\n");
                cliente[i].viajes=realloc(cliente[i].viajes, cliente[i].contador_de_viajes*sizeof(viaje));
                return cliente;
            }
            else
            {

                cliente[i].contador_de_viajes--;
                cliente[i].viajes=realloc(cliente[i].viajes, cliente[i].contador_de_viajes*sizeof(viaje));
                printf("Viaje borrado\n");
                return cliente;
            }
        }

    }


}


