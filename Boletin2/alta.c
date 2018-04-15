#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menu.h"


void alta_cliente(int *contador_clientes, clientes *cliente){

clientes cliente_actual;
char *nombre_fichero;
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

if(*contador_clientes==0){

    cliente[*contador_clientes]=cliente_actual;

    return EXIT_SUCCESS;
fclose(fichero);


}else printf("Error.");
fclose(fichero);


}
