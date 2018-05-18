#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"



Nodo* CrearNodo(clientes* clientes)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    strncpy(nodo->clientes.dni, clientes->dni, 150);
    strncpy(nodo->clientes.nombre, clientes->nombre, 150);
    strncpy(nodo->clientes.apellidos, clientes->apellidos,150);
    strncpy(nodo->clientes.direccion, clientes->direccion,150);

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
Nodo *alta_cliente(Lista* lista, clientes* cliente)
{

    clientes cliente_actual;
    char *nombre_fichero;
    int contador=lista->longitud;
    nombre_fichero=malloc(250*sizeof(char));
    printf("Vamos a dar de alta a un cliente.\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return NULL;
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

  //  if(buscar_cliente(cliente_actual.dni, contador, cliente)==-1)//Si el cliente existe
    /*{
        if(contador !=0 )//Si no es el primer cliente que entra en el sistema
        {
            cliente_actual.contador_de_viajes=0;
             Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

            strncpy(nodo->clientes.dni, clientes->dni, 150);
            strncpy(nodo->clientes.nombre, clientes->nombre, 150);
            strncpy(nodo->clientes.apellidos, clientes->apellidos,150);
            strncpy(nodo->clientes.direccion, clientes->direccion,150);

            nodo->siguiente=NULL;

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
            return nodo;
        }
        else
        {*/
           // cliente_actual.contador_de_viajes=0;

            Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
            strncpy(nodo->clientes.dni, cliente_actual.dni, 150);
            strncpy(nodo->clientes.nombre, cliente_actual.nombre, 150);
            strncpy(nodo->clientes.apellidos, cliente_actual.apellidos,150);
            strncpy(nodo->clientes.direccion, cliente_actual.direccion,150);

            nodo->siguiente=NULL;
            nodo->siguiente = lista->cabeza;
            lista->cabeza = nodo;
            lista->longitud++;

            printf("El cliente %s se a%cadio correctamente al sistema\n", cliente_actual.nombre,-92);

            return nodo;

      //  }
   // }
    //else
     //   printf("El cliente ya existe en el sistema\n");
   // return nodo;
}
