#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "viajes.h"
#include "menu.h"
#include "buscar.h"

/**
\file alta.h
\brief Archivo con las funciones para dar de alta a los usuarios y sus viajes
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/

void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

}

clientes *alta_cliente(int *contador_clientes, clientes *cliente)
{

    clientes cliente_actual;
    char *nombre_fichero;
    int contador=*contador_clientes;
    nombre_fichero=malloc(250*sizeof(char));
    printf("Vamos a dar de alta a un cliente.\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente;
    }
    cliente_actual.dni = malloc(150*sizeof(char));
    cliente_actual.nombre = malloc(150*sizeof(char));
    cliente_actual.apellidos = malloc(150*sizeof(char));
    cliente_actual.direccion = malloc(150*sizeof(char));


    fgets(cliente_actual.dni,150,fichero);
    cliente_actual.dni[strlen(cliente_actual.dni) - 1] = '\0';
    fgets(cliente_actual.nombre,150,fichero);
    cliente_actual.nombre[strlen(cliente_actual.nombre) - 1] = '\0';
    fgets(cliente_actual.apellidos,150,fichero);
    cliente_actual.apellidos[strlen(cliente_actual.apellidos) - 1] = '\0';
    fgets(cliente_actual.direccion,150,fichero);
    fclose(fichero);

    if(buscar_cliente(cliente_actual.dni, contador, cliente)==-1)//Si el cliente existe
    {
        if(contador !=0 )//Si no es el primer cliente que entra en el sistema
        {
            cliente_actual.contador_de_viajes=0;
            cliente=realloc(cliente,(contador+1)*sizeof(clientes));
            cliente[contador]=cliente_actual;
            contador++;
            *contador_clientes=contador;
            printf("El cliente %s se añadio correctamente al sistema\n", cliente_actual.nombre);
            return cliente;
        }
        else
        {
            cliente_actual.contador_de_viajes=0;
            cliente[contador]=cliente_actual;
            contador++;
            *contador_clientes=contador;

            printf("El cliente %s se a%cadio correctamente al sistema\n", cliente_actual.nombre,-92);

            return cliente;

        }
    }
    else
        printf("El cliente ya existe en el sistema\n");
    return cliente;
}

clientes *alta_viaje(int contador_clientes,clientes *cliente)
{

    char *nombre_fichero;
    char *dni;
    char *str;
    char *date;

    int i=0;

    nombre_fichero = malloc(150*sizeof(char));
    dni = malloc(150*sizeof(char));
    str = malloc(3*sizeof(char));
    date = malloc(150*sizeof(char));


    printf("Vamos a introducir un viaje a un cliente\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente;
    }

    fgets(dni,13,fichero);
    dni[strlen(dni) - 1] = '\0';

    i=buscar_cliente(dni,contador_clientes, cliente);

    if(i==-1)
    {
        fclose(fichero);
        printf("El cliente no existe.No se ha podido insertar el funcion\n");
        return cliente;

    }
    else
    {
        if((cliente[i].contador_de_viajes > 0))
        {
            cliente[i].viajes = realloc(cliente[i].viajes,(cliente[i].contador_de_viajes+1)*sizeof(viaje));
        }
        if((cliente[i].contador_de_viajes == 0))
        {
            cliente[i].viajes = malloc(sizeof(viaje));
        }
        cliente[i].viajes[cliente[i].contador_de_viajes].id = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].noches = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].hotel = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].transporte = malloc(150*sizeof(char));

        tiempo(date);//Empieza a concatenar cadenas para el id
        strcat(dni,"_");
        sprintf(str, "%d", cliente[i].contador_de_viajes);
        strcat(dni,str);
        strcat(dni,"_");
        strcat(dni,date);
        strcat(dni,"\0");

        strcpy(cliente[i].viajes[cliente[i].contador_de_viajes].id, dni);
        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].hotel,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].hotel[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].hotel) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].noches,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].noches[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].noches) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento,20,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].transporte,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].transporte[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].transporte) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento,20,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento) - 1] = '\0';

        cliente[i].contador_de_viajes++;
        fclose(fichero);

        printf("Viaje creado con exito\n");
        printf("El identificador del viaje es %s\n",dni);

        return cliente;

    }

}
