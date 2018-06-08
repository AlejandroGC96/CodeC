#include <stdio.h>
#include <stdlib.h>
#include "insertar.h"
#include "arbol.h"
#include "buscar.h"
#include "grafos.h"

void menu()
{

    int opcion = 0;
    int nNodos = 0;

    P_NODO_ARBOL arbol = NULL;

    P_NODO n = NULL;
    P_NODO aux_origen=NULL, aux_destino=NULL;
    P_NODO FINAL = NULL;
    do
    {
        printf("###Menu###\n");
        printf("1. Insertar un nuevo contacto\n");
        printf("2. Buscar un contacto\n");
        printf("3. Cargar carreteras\n");
        printf("4. Calcular camino mas corto\n");
        printf("5. Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {

        case 1:
            arbol = insertar(arbol);
            break;
        case 2:
            printf("Telefono : %d\n",buscar(arbol)->numero);
            break;
        case 3:
            n = cargar(n, aux_origen, aux_destino);
            break;
        case 4:
            listarNodos(n, &nNodos);
            listarArcos(n);
            mas_corto(n, FINAL);

            break;


    }
    }
    while(opcion!=5);

}
