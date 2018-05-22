#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "viaje.h"

extern tcliente *lista;
void alta_viaje(){

    tviaje *nuevo, *actual;
    int encontrado=0;
    char *nomref;
    nomref=(char*)malloc(sizeof(char));
    system ("cls");
    printf("Introduce el nombre de una viaje terminado en .txt ej: viaje1.txt \n");
    scanf("%s", nomref);
    FILE *archivo;
    archivo = fopen(nomref,"r");
    if(!archivo){ //Se comprueba que la viaje que introduce el usuario existe
        printf("El archivo de viaje no existe \n");
        return;
    }
    if (!lista){ //Si la lista esta vacia, le pide al usuario que de de alta primero clientes
        printf("Antes tienes que dar de alta clientes\n");
        return;
    }

    nuevo = (tviaje*)malloc(sizeof(tviaje));
    if (nuevo == NULL){
        printf("No se ha podido reservar la memoria\n");
        exit(1);
    }

    char valores[80];
    char *auxilia;
    int cont = 1, aux, numero;
    while( !feof(archivo) )//Bucle que recorrerá el fichero linea por linea y lo guardara en memoria
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
            break;
        case 2:
            fscanf( archivo, "%s%s\n", &auxilia, &valores);
            aux = strlen(valores)+1;

            nuevo->identificador=(char*)malloc(aux*sizeof(char));
            if (nuevo->identificador == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->identificador, valores);
            break;
        case 3:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->ciudad=(char*)malloc(aux*sizeof(char));
            if (nuevo->ciudad == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->ciudad, valores);
            break;
        case 4:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->destino = (char*) malloc(aux*sizeof(char));
            if (nuevo->destino == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->destino,valores);
            break;
        case 5:
            fscanf( archivo, "%[^\n] \n", &valores);
            aux = strlen(valores)+1;
            nuevo->hotel = (char*) malloc(aux*sizeof(char));
            if (nuevo->hotel == NULL){
                printf("No se ha podido reservar la memoria\n");
                exit(1);
            }
            strcpy (nuevo->hotel,valores);
            break;
        case 6:
            fscanf( archivo, "%s%d", &valores,&numero);
            nuevo->noches=numero;
            break;
        case 7:
            fscanf( archivo, "%s%d", &valores,&numero);
            nuevo->precio=numero;
            break;
      }
      cont++; //Aumenta el contador que sirve para saber el numero de linea del archivo
    }

    fclose(archivo);

    tcliente *auxiliar;
    auxiliar = lista;//igualamos el puntero auxiliar a la lista

    while (auxiliar->anterior) auxiliar = auxiliar->anterior;//Se posiciona al principio de la lista

    while(auxiliar){//Recorre la lista de los clientes en busca de uno que tenga la misma clave que el usuario ha introducido
            if (strcmp(auxiliar->clave, nuevo->clave) == 0)
            {
                actual = auxiliar->listaref;//Igualamos puntero actual con el puntero de lista de viajes del cliente
                auxiliar->contref++;

                if (actual) while (actual->anterior) actual = actual->anterior;//Se posiciona la principio de la lista de viajes

                if (actual==NULL || strcmp(actual->identificador, nuevo->identificador) > 0){//Si la lista de viajes esta vacia o el elemento es menor al de la lista se inserta
                    nuevo->siguiente = actual;
                    nuevo->anterior = NULL;
                    if (actual) actual->anterior = nuevo;//Si existe actual, es que no es el ultimo
                    if(auxiliar->listaref == NULL) auxiliar->listaref = nuevo;//Si la lista de viajes esta vacia apuntamos la lista al nuevo
                }else{
                    while(actual->siguiente && (strcmp(actual->siguiente->identificador, nuevo->identificador) < 0 || strcmp(actual->siguiente->identificador, nuevo->identificador) == 0))
                        actual = actual->siguiente;

                        nuevo->siguiente = actual->siguiente;
                        actual->siguiente = nuevo;
                        nuevo->anterior = actual;
                        if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
                }
                printf("\nEl viaje se ha cargado en memoria correctamente!!\n");

                return;
            }
             auxiliar = auxiliar->siguiente;
    }
    auxiliar = auxiliar->siguiente;
    free(nomref);
}

void borraviaje(){
    int i,j;
    char *nomref;
    nomref = (char*)malloc(sizeof(char));
    int cont;
    system("cls");
    printf("Introduce el identificador de la viaje a borrar ej: C_01 ");
    scanf("%s",nomref);

    tcliente * aux;
    tviaje *nodo;
    aux = lista;//Igualamos el puntero aux a la lista

    if (aux) while (aux->anterior) aux = aux->anterior;//Nos ponemos al principio de la lista

    for(;aux!=NULL;aux=aux->siguiente)//Bucle que recorre la lista buscando una coincidencia con el nombre que introduce el usuario
    {
        nodo=aux->listaref;
        if(nodo) while (nodo->anterior) nodo = nodo->anterior;//Se pone al principio de la lista de viajes dentro de cada cliente
                for(;nodo!=NULL;nodo=nodo->siguiente)
                {
                    if (strcmp(nodo->identificador, nomref) == 0){ // Compara si existe un nodo con una clave igual a la que el usuario propone
                        // Borrar el nodo
                        // Si lista apunta al nodo que queremos borrar, apuntar a otro
                        if(nodo == aux->listaref) // Si la lista apunta al nodo que queremos borrar, hacemos que apunte a otro
                            if(nodo->anterior) aux->listaref = nodo->anterior;
                            else aux->listaref = nodo->siguiente;

                        if(nodo->anterior) // No es el primer nodo
                            nodo->anterior->siguiente = nodo->siguiente;
                        if(nodo->siguiente) // No es el último nodo
                            nodo->siguiente->anterior = nodo->anterior;

                        // Liberamos la memoria previamente reservada

                        free(nodo->clave);
                        free(nodo->identificador);
                        free(nodo->ciudad);
                        free(nodo->hotel);
                        free(nodo);
                        aux->contref--;
                        printf("\nviaje borrada correctamente\n\n");
                        return;
                    }
                }
    }
    printf("\nNo se ha encontrado viaje\n\n");
	free(nomref);
}
