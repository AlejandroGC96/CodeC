#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones_viajes.h"
#include "funciones_cliente.h"

struct cliente *alta_viaje(Lista_cliente L, struct viaje *vj)
{
    int i,lenght;
    //float f;
    char buffer[255];
    Lista_cliente laux;

    printf("Escriba el DNI del cliente: ");
    fflush(stdin);
    gets(buffer);

    laux = l_cliente_localizar_viaje (L,buffer);
    if (laux != NULL)
    {
        vj = (struct viaje *)malloc(sizeof(struct viaje));

        printf("Escriba el id del viaje: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->id = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->id,buffer,lenght+1);

        printf("Escriba la ciudad de destino del viaje: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->ciudad = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->ciudad,buffer,lenght+1);

        printf("Escriba el hotel del viaje: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->hotel = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->hotel,buffer,lenght+1);

        printf("Escriba el numero de noches: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->noches = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->noches,buffer,lenght+1);

        printf("Escriba el medio de transporte: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->transporte = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->transporte,buffer,lenght+1);

        printf("Escriba el precio de alojamiento: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->precioalo = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->precioalo,buffer,lenght+1);

        printf("Escriba el precio de desplazamiento: ");
        fflush(stdin);
        gets(buffer);
        lenght = strlen(buffer);
        vj->preciodes = (char *)malloc((lenght+1)*sizeof(char));
        strncpy(vj->preciodes,buffer,lenght+1);
        //vj->precio = 0;//deja por defecto el precio a 0

        laux->cl->v = l_viaje_insertar(laux->cl->v, l_viaje_primero(laux->cl->v),vj);
    }
    return L; //devuelve todos los datos introducidos del nuevo viaje
}

void mostrar_viaje(struct viaje *vj)
{
    printf("\n");
    printf("ID %s\n",vj->id);
    printf("Ciudad de destino: %s\n",vj->ciudad);
    printf("Hotel: %s\n",vj->hotel);
    printf("Numero de noches: %s\n",vj->noches);
    printf("Medio de transporte: %s\n",vj->transporte);
    printf("Precio de alojamiento: %s\n",vj->precioalo);
    printf("Precio de desplazamiento: %s\n",vj->preciodes);
    printf("\n");
}

