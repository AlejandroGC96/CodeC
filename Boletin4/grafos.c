#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

P_NODO cargar(P_NODO n, P_NODO aux_origen, P_NODO aux_destino)
{

    FILE *fichero;

    if ((fichero = fopen("carreteras.txt", "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero fuente \n");
        fclose(fichero);
        return n;
    }

    while (!feof(fichero))
    {


















    }



}

