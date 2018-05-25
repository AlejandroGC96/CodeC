#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "insertar.h"



P_NODO_ARBOL insertar_recursivo(P_NODO_ARBOL arbol, char *nombre, int numero){


if(arbol==NULL){
    P_NODO_ARBOL p;
    p = (P_NODO_ARBOL)malloc(sizeof(P_NODO_ARBOL));
    p->nombre = malloc(sizeof(char));

    p->izq = NULL;
    p->der = NULL;
    strcpy(p->nombre, nombre);
    p->numero = numero;

    return p;

}

if(((strcmp(arbol->nombre,nombre))==0)){

    printf("El valor ya esta en el arbol");
    return arbol;

}


if((strcmp(arbol->nombre, nombre))>0){


   arbol->izq = insertar_recursivo(arbol->izq, nombre, numero);


   }else
   arbol-> der = insertar_recursivo(arbol->der, nombre,numero);

return arbol;



}


P_NODO_ARBOL insertar(P_NODO_ARBOL arbol){

char *nombre;
int numero;
P_NODO_ARBOL p;

nombre=malloc(150*sizeof(char));

printf("Introduce nombre:\n");
scanf("%s",nombre);
fflush(stdin);
printf("Introduce el numero de tlf\n");
scanf("%d",&numero);
fflush(stdin);

if(arbol==NULL){

    p = (P_NODO_ARBOL)malloc(sizeof(P_NODO_ARBOL));
    p->nombre = malloc(sizeof(char));

    p->izq = NULL;
    p->der = NULL;
    strcpy(p->nombre, nombre);
    p->numero = numero;

    return p;

}

if(((strcmp(arbol->nombre,nombre))==0)){

    printf("El valor ya esta en el arbol");
    return arbol;

}


if((strcmp(arbol->nombre, nombre))>0){


   arbol->izq = insertar_recursivo(arbol->izq, nombre, numero);


   }else
   arbol-> der = insertar_recursivo( arbol->der, nombre, numero);

return arbol;
}
