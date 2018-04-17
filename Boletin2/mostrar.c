#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void mostrar(int contador_clientes, clientes *cliente){

int i,j=0;
for(i=0;i<contador_clientes;i++){

        printf("Cliente %d\n",i+1);
        printf("DNI: %s\n",cliente[i].dni);
        printf("Nombre: %s\n",cliente[i].nombre);
        printf("Apellidos: %s\n",cliente[i].apellidos);
        printf("Direccion: %s\n",cliente[i].direccion);
        printf("-----------------------\n");

        for (;j<cliente[i].contador_de_viajes;j++){
          printf("\t####Viaje %d####\n",j+1);
                    printf("\tID: %s\n",cliente[i].viajes[j].id);
                    printf("\tCiudad de destino: %s\n",cliente[i].viajes[j].ciudad_destino);
                    printf("\tHotel: %s\n",cliente[i].viajes[j].hotel);
                    printf("\tNoches: %s\n",cliente[i].viajes[j].noches);
                    printf("\tPrecio alejamiento: %s\n",cliente[i].viajes[j].precio_alojamiento);
                    printf("\tTransporte: %s\n",cliente[i].viajes[j].transporte);
                    printf("\tPrecio del desplazamiento: %s\n",cliente[i].viajes[j].precio_desplazamiento);


        }
}

}
