#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

P_NODO cargar(P_NODO n, P_NODO aux_origen, P_NODO aux_destino)
{

    char *variable,*variable_auxiliar;
    int i=0;
    FILE *fichero;

    if ((fichero = fopen("carreteras.txt", "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero fuente \n");
        fclose(fichero);
        return n;
    }

    variable = malloc(10000*sizeof(char));
    variable_auxiliar = malloc(150*sizeof(char));
    while (!feof(fichero))
    {

        fgets (variable_auxiliar,150,fichero);
        fgets (variable_auxiliar,150,fichero);

        fgets (variable,10000,fichero);
        fgets (variable,10000,fichero);
        fgets (variable,10000,fichero);

        while((strlen(variable))!= i){

              fscanf(fichero,"%s",variable_auxiliar);
                 variable[strlen(variable_auxiliar) - 1] = '\0';
                i++;

              }



    }



}

