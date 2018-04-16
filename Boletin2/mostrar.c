#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void mostrar(int contador_clientes, clientes *cliente){

int i=0;
for(;i<contador_clientes;i++){

        printf("Cliente %d\n",i+1);
        printf("DNI: %s\n",cliente[i].dni);
        printf("Nombre: %s\n",cliente[i].nombre);
        printf("Apellidos: %s\n",cliente[i].apellidos);
        printf("Direccion: %s\n",cliente[i].direccion);
        printf("-----------------------\n");

        return EXIT_SUCCESS;

}
        return EXIT_FAILURE;
}
