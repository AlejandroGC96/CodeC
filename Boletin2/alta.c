#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menu.h"
#include "buscar.h"

clientes *alta_cliente(int *contador_clientes, clientes *cliente)
{

    clientes cliente_actual;
    char *nombre_fichero;
    //int i=0;
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
        exit (EXIT_FAILURE);
    }
    cliente_actual.dni = malloc(150*sizeof(char));
    cliente_actual.nombre = malloc(150*sizeof(char));
    cliente_actual.apellidos = malloc(150*sizeof(char));
    cliente_actual.direccion = malloc(150*sizeof(char));

    fscanf(fichero,"%s",cliente_actual.dni);
    fscanf(fichero,"%s",cliente_actual.nombre);
    fscanf(fichero,"%s",cliente_actual.apellidos);
    fscanf(fichero,"%s",cliente_actual.direccion);
    fclose(fichero);

    if(buscar_cliente(cliente_actual.dni, contador, cliente)==-1)
    {
        if(contador !=0 )
        {
            cliente=realloc(cliente,(contador+1)*sizeof(clientes));
            //i=ordenar(cliente_actual.apellidos, cliente, contador);
            cliente[contador]=cliente_actual;
            contador++;
            *contador_clientes=contador;
            printf("El cliente %s se añadio correctamente al sistema\n", cliente_actual.nombre);
            return cliente;
        }
        else
        {
            cliente[contador]=cliente_actual;
            contador++;
            *contador_clientes=contador;
            printf("El cliente %s se a%cadio correctamente al sistema\n", cliente_actual.nombre,-92);

            return cliente;

        }
    }
    else
        printf("El cliente ya existe en el sistema\n");
    return EXIT_FAILURE;
}
