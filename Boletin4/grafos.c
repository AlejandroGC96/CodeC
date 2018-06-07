#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

P_NODO cargar(P_NODO n, P_NODO aux_origen, P_NODO aux_destino)
{

    char *variable_auxiliar;
    fpos_t posicion = 16;
    int i=0;
    FILE *fichero;

    if ((fichero = fopen("carreteras.txt", "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero fuente \n");
        fclose(fichero);
        return n;
    }

    variable_auxiliar = malloc(150*sizeof(char));

    fsetpos(fichero, &posicion);

    while(posicion<137)
    {

        fscanf(fichero,"%s",variable_auxiliar);
        posicion=ftell(fichero);

        if(variable_auxiliar[strlen(variable_auxiliar) - 1]==',')
            variable_auxiliar[strlen(variable_auxiliar) - 1] = '\0';
        printf("%s\n",variable_auxiliar);
        n=nuevo(n, variable_auxiliar);
    }

    posicion = 192;
    fsetpos(fichero, &posicion);

    while(!feof(fichero))
    {
        fscanf(fichero,"%s",variable_auxiliar);
        printf("Ciudad inicial : %s\n",variable_auxiliar);
        aux_origen=buscar_grafo(n, variable_auxiliar);

        fscanf(fichero,"%s",variable_auxiliar);
        printf("Ciudad destino : %s\n",variable_auxiliar);
        aux_destino=buscar_grafo(n, variable_auxiliar);

        fscanf(fichero,"%d",&i);
        printf("Distansia : %d\n",i);
        arco(aux_origen, aux_destino,i);
        printf("------------\n");
    }
    fclose(fichero);
    return n;
}



P_NODO nuevo(P_NODO n, char *nombre_ciudad)
{

    if(buscar_grafo(n, nombre_ciudad) == NULL)
    {
        P_NODO paux = (P_NODO) malloc(sizeof (NODO));
        paux->nombre_ciudad = malloc(150*sizeof(char));
        strcpy(paux->nombre_ciudad, nombre_ciudad);
        paux->apunta = NULL;

        if (n == NULL)
        {
            paux->sgte = NULL;
        }
        else
        {
            paux->sgte = n;
        }

        n = paux;
        printf("Nodo creado\n");
    }
    else
    {
        printf("Nodo ya creado\n");
    }
    return n;
}

P_NODO buscar_grafo(P_NODO n, char *nombre_ciudad)
{

    P_NODO paux = n;
    while (paux != NULL)
    {
        if(paux->nombre_ciudad == nombre_ciudad)
        {
            return paux;
        }
        else
        {
            paux = paux->sgte;
        }
    }
    return NULL;
}
void listarNodos(P_NODO n)
{

    P_NODO paux = n;

    while (paux!= NULL)
    {
        printf("Nodo: %s\n", paux->nombre_ciudad);
        paux = paux->sgte;
    }
}
void arco(P_NODO origen, P_NODO destino, int distancia){

    P_ARCO paux = (P_ARCO) malloc(sizeof (ARCO));

    paux->apunta = destino;
    paux->sgte = origen->apunta;
    origen->apunta = paux;
    paux->distancia = distancia;
}


