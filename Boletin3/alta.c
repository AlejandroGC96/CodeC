#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"

 Nodo* CrearLista()
{
   return NULL;
}


Nodo* CrearNodo(clientes* clientes)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    strncpy(nodo->clientes->dni, clientes->dni, 150);
    strncpy(nodo->clientes->nombre, clientes->nombre, 150);
    strncpy(nodo->clientes->apellidos, clientes->apellidos,150);
    strncpy(nodo->clientes->direccion, clientes->direccion,150);

    nodo->siguiente=NULL;

    return nodo;

}

void InsertarPrincipio(Lista* lista, clientes* clientes)
{

    Nodo* nodo = CrearNodo(clientes);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;

}

void InsertarFinal(Lista* lista, clientes* cliente)
{

    Nodo* nodo = CrearNodo(cliente);
    if(lista->cabeza == NULL)
    {
        lista->cabeza= nodo;
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;

    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista* lista, clientes* clientes)
{

    Nodo* nodo = CrearNodo(clientes);

    if(lista->cabeza == NULL)
    {

        lista->cabeza=nodo;
    }
    else
    {
        Nodo* puntero = lista->cabeza;
        int posicion=0;
        while (posicion < n && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;

    }

    lista->longitud++;

}
void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

}

clientes *alta_cliente()
{


    clientes cliente_actual;
    char *nombre_fichero;

    nombre_fichero=malloc(250*sizeof(char));
    printf("Vamos a dar de alta a un cliente.\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente_actual;
    }
    cliente_actual.dni = malloc(150*sizeof(char));
    cliente_actual.nombre = malloc(150*sizeof(char));
    cliente_actual.apellidos = malloc(150*sizeof(char));
    cliente_actual.direccion = malloc(150*sizeof(char));


    fgets(cliente_actual.dni,150,fichero);
    cliente_actual.dni[strlen(cliente_actual.dni) - 1] = '\0';
    fgets(cliente_actual.nombre,150,fichero);
    cliente_actual.nombre[strlen(cliente_actual.nombre) - 1] = '\0';
    fgets(cliente_actual.apellidos,150,fichero);
    cliente_actual.apellidos[strlen(cliente_actual.apellidos) - 1] = '\0';
    fgets(cliente_actual.direccion,150,fichero);
    fclose(fichero);
  //  cliente_actual.contador_de_viajes=0;

            printf("El cliente %s se a%cadio correctamente al sistema\n", cliente_actual.nombre,-92);
            return cliente_actual;

}

