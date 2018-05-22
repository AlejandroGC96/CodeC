#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "viajes.h"


extern lclientes *lista;

void baja_clientes(){

    lclientes *nodo;
    nodo=lista;

    char *dni;
    char opcion;
    char *nombre_fichero;

    dni = malloc(150*sizeof(char));
    nombre_fichero = malloc(150*sizeof(char));
    FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir: \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return;
    }

    fgets(dni,15,fichero);






    if (nodo) while (nodo->anterior) nodo = nodo->anterior; // Se posiciona en el primer nodo de la lista

    for(;nodo!=NULL;nodo=nodo->siguiente){ // Bucle que recorre la lista desde el principio hasta el final
        if (strcmp(nodo->dni, dni) == 0){ // Compara si existe un nodo con una clave igual a la que el usuario propone
            /* Borrar el nodo */
            /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
            if(nodo == lista) // Si la lista apunta al nodo que queremos borrar, hacemos que apunte a otro
                if(nodo->anterior) lista = nodo->anterior;
                else lista = nodo->siguiente;

            if(nodo->anterior) // No es el primer nodo
                nodo->anterior->siguiente = nodo->siguiente;
            if(nodo->siguiente) // No es el �ltimo nodo
                nodo->siguiente->anterior = nodo->anterior;

            // Liberamos la memoria previamente reservada

            lviajes *auxref;
            auxref = nodo->lista_viajes;
            if (nodo->contador_viajes !=0){
                if (auxref) while (auxref->anterior) auxref = auxref->anterior;
                    for(;auxref!=NULL;auxref=auxref->siguiente)
                    {
                    free(auxref->id);
                    free(auxref->hotel);
                    free(auxref->ciudad_destino);
                    free(auxref->noches);
                    free(auxref->precio_alojamiento);
                    free(auxref->transporte);
                    free(auxref->precio_desplazamiento);
                    }
                    free(nodo->lista_viajes);
            }
            free(nodo->dni);
            free(nodo->nombre);
            free(nodo->apellidos);
            free(nodo->direccion);
            free(nodo);
            printf("\nCliente borrado correctamente\n");
            return;
        }
    }
    printf("\nNo se ha encontrado cliente para borrar\n");



}



void baja_viajes(){

    char *dni;
    char *id;
    char *nombre_fichero;
    char *id2;
    char *id_2;



    nombre_fichero=malloc(150*sizeof(char));
    id=malloc(150*sizeof(char));
    id2=malloc(150*sizeof(char));
    dni=malloc(150*sizeof(char));
    id_2=malloc(150*sizeof(char));


    FILE *fichero;
    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return ;
    }

    fgets(id,15,fichero);
    strcpy(id2,id);
    dni= strtok(id, "_");//Acorta para buscar un usuario por su DNI
    fclose(fichero);

    lclientes * aux;
    lviajes *nodo;
    aux = lista;//Igualamos el puntero aux a la lista

    if (aux) while (aux->anterior) aux = aux->anterior;//Nos ponemos al principio de la lista

    for(;aux!=NULL;aux=aux->siguiente)//Bucle que recorre la lista buscando una coincidencia con el nombre que introduce el usuario
    {
        nodo=aux->lista_viajes;
        if(nodo) while (nodo->anterior) nodo = nodo->anterior;//Se pone al principio de la lista de viajes dentro de cada cliente
                for(;nodo!=NULL;nodo=nodo->siguiente)
                {

                    strncpy(id_2,nodo->id,9);
                    if (strcmp(id_2, dni) == 0){ // Compara si existe un nodo con una clave igual a la que el usuario propone
                        // Borrar el nodo
                        // Si lista apunta al nodo que queremos borrar, apuntar a otro
                        if(nodo == aux->lista_viajes) // Si la lista apunta al nodo que queremos borrar, hacemos que apunte a otro
                            if(nodo->anterior) aux->lista_viajes = nodo->anterior;
                            else aux->lista_viajes = nodo->siguiente;

                        if(nodo->anterior) // No es el primer nodo
                            nodo->anterior->siguiente = nodo->siguiente;
                        if(nodo->siguiente) // No es el �ltimo nodo
                            nodo->siguiente->anterior = nodo->anterior;

                        // Liberamos la memoria previamente reservada

                        free(nodo->id);
                        free(nodo->ciudad_destino);
                        free(nodo->hotel);
                        free(nodo->noches);
                        free(nodo->precio_alojamiento);
                        free(nodo->transporte);
                        free(nodo->precio_desplazamiento);
                        free(nodo);

                        printf("Vieje borrado correctamente\n\n");
                        return;
                    }
                }
    }
    printf("No se ha encontrado viaje\n\n");

}


























