#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

P_NODO_ARBOL buscar_recursivo(P_NODO_ARBOL arbol, char* nombre){



  if (arbol == NULL)    /*Arbol vacÌo por tanto devuelve NULL*/
        return (NULL);

    if (arbol->nombre == nombre)    /* Hemos encontrado el valor */
        return (arbol);
    else if (arbol->nombre > nombre)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(buscar_recursivo(arbol->izq, nombre));
    else    /* "i" es mayor que el valor actual */
        return(buscar_recursivo(arbol->der, nombre));





}




P_NODO_ARBOL buscar(P_NODO_ARBOL arbol){

char *nombre;

nombre=malloc(150*sizeof(char));

printf("Introduce nombre:\n");
scanf("%s",nombre);
fflush(stdin);


  if (arbol == NULL)    /* Arbol vacÌo por tanto devuelve NULL */
        return (NULL);

    if (strcmp(arbol->nombre, nombre)==0)    /* Hemos encontrado el valor */
        return (arbol);
    else if (strcmp(arbol->nombre, nombre)>0)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(buscar_recursivo(arbol->izq, nombre));
    else    /* "i" es mayor que el valor actual */
        return(buscar_recursivo(arbol->der, nombre));



}




