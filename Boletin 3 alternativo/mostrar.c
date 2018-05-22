#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "viajes.h"


extern lclientes *lista;

void imprimir()
{
    if(lista == NULL)
    {
        printf("No hay datos:)\n");
        return;
    }
    lclientes * aux;
    lviajes *auxref;
    aux = lista;//Igualamos al puntero aux el de lista

    while (aux->anterior) aux = aux->anterior;//Nos posicionamos al principio de la lista

    printf("#########Lista de clientes#########\n");
    for(;aux!=NULL;aux=aux->siguiente)//Recorremos la lista entera para imprimir sus valores por pantalla
    {
        auxref = aux->lista_viajes;
        printf("---------------------------\n");
        printf("%s\n",aux->dni);
        printf("%s\n",aux->nombre);
        printf("%s\n",aux->apellidos);
        printf("%s\n",aux->direccion);
        printf("---------------------------\n");
        if (aux->contador_viajes !=0){//Si la lista tiene a su vez lista de viajes, se recorre tambien para imprimirlas
            if (auxref) while (auxref->anterior) auxref = auxref->anterior;
                for(;auxref!=NULL;auxref=auxref->siguiente)
                {
                printf("---------------------------\n");
                printf("ID : %s\n",auxref->id);
                printf("Ciudad : %s\n",auxref->ciudad_destino);
                printf("Hotel : %s\n",auxref->hotel);
                printf("%s\n",auxref->noches);
                printf("Precio de alejamiento : %s\n",auxref->precio_alojamiento);
                printf("Transporte : %s\n",auxref->transporte);
                printf("Precio desplazamiento : %s\n",auxref->precio_desplazamiento);

                printf("---------------------------\n");
                }
        }
    }
}
