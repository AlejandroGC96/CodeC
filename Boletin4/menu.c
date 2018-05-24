#include <stdio.h>
#include <stdlib.h>
#include "insertar.h"
#include "arbol.h"

void menu(){

int opcion = 0;
P_NODO_ARBOL arbol = NULL;

do{
printf("###Menu###\n");
printf("1. Insertar un nuevo contacto\n");
printf("2. Buscar un contacto\n");
printf("3.Salir\n");
scanf("%d",&opcion);
fflush(stdin);
switch(opcion){

case 1:
    arbol = insertar(arbol);
    break;
case 2:
    break;

}
    }while(opcion!=3);

}

