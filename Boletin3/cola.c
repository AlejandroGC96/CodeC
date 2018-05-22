#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cola.h"

extern tcola *cola;
void reservaviaje() {

    tcola *nuevo, *actual;
    char valores[20];
    int aux;

    // Crear un nodo nuevo
    nuevo = (tcola*)malloc(sizeof(tcola));
    system("cls");
    printf("Introduce el identificador del viaje: ");
    scanf ("%s",&valores);
    aux = strlen(valores)+1;
    nuevo->identificador = (char*) malloc(aux*sizeof(char));
    strcpy (nuevo->identificador, valores);

    printf("Introduce la prioridad del viaje: ");
    scanf ("%d",&nuevo->prioridad);


    actual = cola;//Igualamos actual a la cola
    if (actual) while (actual->anterior) actual = actual->anterior;//Nos ponemos al principio de la cola

    if (actual==NULL || actual->prioridad >= nuevo->prioridad){//Si la cola esta vacia o el elemento a insertar el menor o igual que el actual se inserta
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if (actual) actual->anterior = nuevo;//Si existe actual entonces actual anterior apuntara al nuevo nodo
        if(cola==NULL) cola = nuevo;//Si la cola esta vacia se iguala al nuevo elemento
    }else{
        while(actual->siguiente && actual->siguiente->prioridad <= nuevo->prioridad)//Recorre la cola hasta ver donde insertarse cuando la prioridad del nuevo sea mayor que la del actual
            actual = actual->siguiente;

            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
            if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
    }
    printf("\nCargado en memoria correctamente!!\n");
}

int listarviaje() {
    system("cls");
    if(cola == NULL)
    {
        printf("\nNo hay datos en memoria\n\n");
        return;
    }
    tcola * aux;
    aux = cola;//Se iguala aux a cola
    if (aux) while (aux->siguiente) aux = aux->siguiente;//Se posiciona al final de la cola

    for(;aux!=NULL;aux=aux->anterior)//Recorre la cola desde el final mostrando los valores ya que han sido insertados ordenados
    {
        printf("Identificador: %s prioridad: %d\n",aux->identificador,aux->prioridad);
    }
}
