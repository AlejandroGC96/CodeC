#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

extern tcliente *lista;

void imprimir()
{
    system("cls");
    if(lista == NULL)
    {
        printf("\nNo hay datos en la memoria del programa\n\n");
        return;
    }
    tcliente * aux;
    tviaje *auxref;
    aux = lista;//Igualamos al puntero aux el de lista

    while (aux->anterior) aux = aux->anterior;//Nos posicionamos al principio de la lista

    printf("/********************************************************************/\n");
    printf("/****************** LISTADO DE LA AGENCIA DE VIAJES *****************/\n");
    printf("/********************************************************************/\n");
    for(;aux!=NULL;aux=aux->siguiente)//Recorremos la lista entera para imprimir sus valores por pantalla
    {
        auxref = aux->listaref;

        printf("%s\n",aux->nombre);
        printf("%s\n",aux->dni);
        printf("Cont viajes %d\n\n",aux->contref);
        if (aux->contref !=0){//Si la lista tiene a su vez lista de viajes, se recorre tambien para imprimirlas
            if (auxref) while (auxref->anterior) auxref = auxref->anterior;
                for(;auxref!=NULL;auxref=auxref->siguiente)
                {
                printf("     - viaje identificador '%s'\n",auxref->identificador);
                printf("     - %s\n",auxref->ciudad);
                printf("     - %s\n",auxref->destino);
                printf("     - %s\n",auxref->hotel);
                printf("     - Noches: %d\n",auxref->noches);
                printf("     - Pecio Total: %d\n\n",auxref->precio);
                }
        }
    }
}
