#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cliente.h"

extern tcliente *lista;

void alta_cliente(){
    tcliente *nuevo, *actual;
    char *nomcat;
    nomcat=(char*)malloc(sizeof(char));
    system ("cls");
    printf("Introduce el nombre de un cliente terminado en .txt \n");
    scanf("%s", nomcat);
    FILE *archivo;
    archivo = fopen(nomcat,"r");
    if(!archivo){ //Primero comprueba si el nombre del cliente existe
        printf("El cliente no existe \n");
        return;
    }
//Mientras no se llega al final del archivo recoge las lineas y las guarda en memoria
//Los archivos de cliente se componen de tres lineas por eso el switch tiene 3 casos

    nuevo=(tcliente*)malloc(sizeof(tcliente));
    if (nuevo == NULL){
        printf("No se ha podido reservar la memoria\n");
        exit(1);
    }
    char valores[80];
    char *auxilia;
    int cont = 1, aux;
    while( !feof(archivo) )
    {
      switch(cont){
        case 1:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->clave=(char*)malloc(aux*sizeof(char));
            if (nuevo->clave == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->clave, valores);
            rewind(archivo);
            fscanf( archivo, "%s%s\n", &auxilia, &valores);
            aux = strlen(valores)+1;
            nuevo->ordclave=(char*)malloc(aux*sizeof(char));
            if (nuevo->ordclave  == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->ordclave, valores);
            break;
        case 2:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->nombre=(char*)malloc(aux*sizeof(char));
            if (nuevo->nombre == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->nombre, valores);
            break;
        case 3:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->dni=(char*)malloc(aux*sizeof(char));
            if (nuevo->dni == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->dni, valores);
            break;
      }
      cont++;
    }
    fclose(archivo);

    actual = lista;

    if (actual) while (actual->anterior) actual = actual->anterior;

    if (actual==NULL || strcmp(actual->ordclave, nuevo->ordclave) > 0){
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if (actual) actual->anterior = nuevo; //Si existe actual es que no es el último
        if(lista==NULL) lista = nuevo;
    }else{
        while(actual->siguiente && (strcmp(actual->siguiente->ordclave, nuevo->ordclave) < 0 || strcmp(actual->siguiente->ordclave, nuevo->ordclave) == 0)) //Recorremos la lista hasta el lugar donde queremos insertar
            actual = actual->siguiente;

            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
            if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo; //Si existe nuevo-> es que no es el último
    }
    printf("\nEl cliente se ha cargado en memoria correctamente!!\n");
    nuevo->listaref=(tviaje*)malloc(sizeof(tviaje));
    nuevo->listaref = NULL;
    nuevo->contref=0;
    free(nomcat);
}

void borracliente() {

    tcliente *nodo;

    nodo = lista; // Hacemos que nodo sea igual a la lista

    char *nomcat;
    nomcat = (char*)malloc(sizeof(char));
    system("cls");
    printf("Introduce la clave de cliente para borrar por ejemplo C: ");
    scanf("%s",nomcat);

    if (nodo) while (nodo->anterior) nodo = nodo->anterior; // Se posiciona en el primer nodo de la lista

    for(;nodo!=NULL;nodo=nodo->siguiente){ // Bucle que recorre la lista desde el principio hasta el final
        if (strcmp(nodo->ordclave, nomcat) == 0){ // Compara si existe un nodo con una clave igual a la que el usuario propone
            /* Borrar el nodo */
            /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
            if(nodo == lista) // Si la lista apunta al nodo que queremos borrar, hacemos que apunte a otro
                if(nodo->anterior) lista = nodo->anterior;
                else lista = nodo->siguiente;

            if(nodo->anterior) // No es el primer nodo
                nodo->anterior->siguiente = nodo->siguiente;
            if(nodo->siguiente) // No es el último nodo
                nodo->siguiente->anterior = nodo->anterior;

            // Liberamos la memoria previamente reservada

            tviaje *auxref;
            auxref = nodo->listaref;
            if (nodo->contref !=0){
                if (auxref) while (auxref->anterior) auxref = auxref->anterior;
                    for(;auxref!=NULL;auxref=auxref->siguiente)
                    {
                    free(auxref->clave);
                    free(auxref->identificador);
                    free(auxref->ciudad);
                    free(auxref->destino);
                    free(auxref->hotel);
                    }
                    free(nodo->listaref);
            }
            free(nodo->clave);
            free(nodo->ordclave);
            free(nodo->nombre);
            free(nodo->dni);
            free(nodo);
            printf("\nCliente borrado correctamente\n");
            return;
        }
    }
    printf("\nNo se ha encontrado cliente para borrar\n");
}
