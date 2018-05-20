#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

struct cliente *alta_cliente(struct cliente *cl)
{

    char *buffer = (char *)malloc(sizeof(char)*255); //asigno un tamaño para los datos del nodo
    int lenght;// longitud del tamaño

    cl = (struct cliente *)malloc(sizeof(struct cliente)); //tamaño asignado al struct de los datos del cliente

    printf("Escriba el DNI del cliente:\n");
    fflush(stdin); //limpia
    gets(buffer);//lee lo introducido por teclado
    lenght = strlen(buffer); //calcula el tamaño
    cl->dni = malloc((lenght+1)*sizeof(char)); //tamaño para el dni
    strncpy(cl->dni,buffer,lenght+1); //copia la cadena del dni

    printf("Escriba el nombre:\n");
    fflush(stdin);
    gets(buffer);
    lenght = strlen(buffer);
    cl->nombre = malloc((lenght+1)*sizeof(char));
    strncpy(cl->nombre,buffer,lenght+1);

    printf("Escriba la direccion: \n");
    fflush(stdin);
    gets(buffer);
    lenght = strlen(buffer);
    cl->direccion = malloc((lenght+1)*sizeof(char));
    strncpy(cl->direccion,buffer,lenght+1);

    cl->contador_viajes = 0; //el cliente se inicia por defecto con 0 viajes asociados

    free(buffer); //limpia la memoria de los datos introducidos
    return cl; //devuelve todos los datos ordenados para que cuando se llame a esta funcion los genere todos
}

void mostrar_cliente (struct cliente *cl)
{
    printf("---------------------------------------------\n");
    printf("DNI %s\n",cl->dni);
    printf("NOMBRE: %s\n",cl->nombre);
    printf("DIRECCION: %s\n",cl->direccion);
    printf("---------------------------------------------\n");
}

