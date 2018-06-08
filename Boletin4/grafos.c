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
    // aux_origen=(P_NODO) malloc(sizeof (NODO));
    // aux_destino=(P_NODO) malloc(sizeof (NODO));

    if ((fichero = fopen("carreteras.txt", "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero fuente \n");
        fclose(fichero);
        return n;
    }

    variable_auxiliar = malloc(150*sizeof(char));

    fsetpos(fichero, &posicion);

    while(posicion<161)
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
        if(aux_origen==NULL)
            return n;

        fscanf(fichero,"%s",variable_auxiliar);
        printf("Ciudad destino : %s\n",variable_auxiliar);
        aux_destino=buscar_grafo(n, variable_auxiliar);
        if(aux_destino==NULL)
            return n;

        fscanf(fichero,"%d",&i);
        printf("Distansia : %d\n",i);
        arco(aux_origen, aux_destino,i);
        printf("------------\n");
    }
    fclose(fichero);

    printf("Archivo cargado...\n");
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
        if(strcmp(paux->nombre_ciudad,nombre_ciudad)==0)
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
void listarNodos(P_NODO n, int *nNodos)
{

    P_NODO paux = n;

    while (paux!= NULL)
    {
        printf("Nodo: %s\n", paux->nombre_ciudad);
        paux = paux->sgte;
        *nNodos=*nNodos+1;
    }
}
void arco(P_NODO origen, P_NODO destino, int distancia)
{

    P_ARCO paux = (P_ARCO) malloc(sizeof (ARCO));

    paux->apunta = destino;
    paux->sgte = origen->apunta;
    origen->apunta = paux;
    paux->distancia = distancia;

}
void listarArcos(P_NODO n)
{


    P_ARCO arc;
    P_NODO paux = n;
    if(paux == NULL)
    {
        printf("\n***El nodo no existe");
    }
    else
    {
        while (paux!= NULL)
        {
            printf("\nNodo: %s", paux->nombre_ciudad);
            arc=paux->apunta;
            while (arc != NULL)
            {
                printf("-> arco: %s ", arc->apunta->nombre_ciudad);
                arc = arc-> sgte;
            }
            paux = paux->sgte;
        }
    }
}



P_NODO mas_corto(P_NODO n, P_NODO FINAL)
{
    P_ARCO arc, aux_arc;

    P_NODO paux = n;

    while(paux!= NULL)
    {
        arc=paux->apunta;
        while(arc != NULL)
        {
            // Inicializamos con el coste de los caminos directos
            aux_arc = arc;
            FINAL = -1;
            arc = arc-> sgte;
        }
        paux = paux->sgte;
    }
    paux=n;

    while (paux!=NULL)
    {
        arc=paux->apunta;
        while(arc!= NULL)
        {
            aux_arc=paux->apunta;
            while(aux_arc != NULL)
            {
                if (aux_arc->distancia+arc->distancia < aux_arc->distancia)
                {
                    aux_arc->distancia = aux_arc->distancia+arc->distancia ;
                    FINAL = paux;
                }
                aux_arc = aux_arc-> sgte;
            }
            arc = arc-> sgte;
        }
        paux = paux->sgte;

    }
    return FINAL;
}
/*
void camino (P_NODO FINAL)
{
    char *nombre_ciudad;
    nombre_ciudad = malloc(150*sizeof(char));
    printf("\nIntroduce el nombre del nodo: ");
    scanf("%s", nombre_ciudad);
     fflush(stdin);

    P_ARCO arc;
    P_NODO paux = buscar_grafo(FINAL, nombre_ciudad);
    if(paux == NULL){
            printf("\n***El nodo no existe");
    }else{
         printf("\nIntroduce el nombre del nodo: ");
        scanf("%s", nombre_ciudad);
        fflush(stdin);
        P_NODO paux2 = buscar_grafo(FINAL, nombre_ciudad);

         if(paux2 == NULL){
            printf("\n***El nodo no existe");
         }else {

       if()
        arc=paux->apunta;
        while (arc != NULL) {
            printf("-> arco: %c ", arc->apunta->nombre);
            arc = arc-> sgte;
        }
    }
    }
    int k;
    if ((k=P[i][j])== -1)
        return;
    camino(i,k);
    printf(Åg%d Åg,k);
    camino(k,j);
}
*/
