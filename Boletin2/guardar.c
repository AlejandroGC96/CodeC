#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"


void guardar(cliente *clientes, int contador_clientes)
{
    FILE *fichero;
    fichero = fopen("contenido.bin", "wb");
    fwrite(&contador_clientes,sizeof(int),1,fichero);
    fwrite(clientes, sizeof(cliente), contador_clientes, fichero);
    fclose(fichero);
    printf("Guardado\n");
}
 int cargar(cliente *clientes,int contador_clientes)
{

    FILE *fichero;
    fichero = fopen("contenido.bin", "rb");

    if (fichero == NULL)
    {
        printf("No se encuentran bases de datos\n");
        system("pause");
        return 0;
    }
    else
    {
        fread(&contador_clientes,sizeof(int),1,fichero);
        fread(clientes, sizeof(cliente), 19, fichero);
        printf("Se ha cargado con exito\n");
    }
 fclose(fichero);

 return contador_clientes;
}

