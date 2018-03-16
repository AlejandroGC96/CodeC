#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"


void guardar(cliente *clientes, int contador_clientes)
{
    FILE *fichero;
    fichero = fopen("contenido.bin", "wb");
    fwrite(clientes, sizeof(cliente), contador_clientes, fichero);
    fclose(fichero);
    printf("Guardado\n");
}
void cargar(cliente *clientes)
{

    FILE *fichero;
    fichero = fopen("contenido.bin", "rb");

    if (fichero == NULL)
    {
        printf("No se encuentran bases de datos\n");
        system("pause");
    }
    else
    {
        fread(clientes, sizeof(cliente), 19, fichero);
        printf("Se ha cargado con exito\n");
    }
 fclose(fichero);
}
