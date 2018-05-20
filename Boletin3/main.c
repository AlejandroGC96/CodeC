#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones_cliente.h"
#include "funciones_cliente_auxiliares.h"

int main()
{
    Lista_cliente L; //apuntando al primer nodo de la lista de cliente


    struct cliente *cl_temp; //cliente recien añadido mediante los datos cogidos del struct
    struct viaje *vj_temp; //viaje recien añadido mediante los datos cogidos del struct

    int opcion=0;

    L = l_cliente_crear();
    do{
        printf("\n\n**GESTION AGENCIA**\n\n");
        printf("1.- Dar de alta a los clientes\n");
        printf("2.- Dar de baja a los clientes\n");
        printf("3.- Dar de alta a un viaje\n");
        printf("4.- Dar de baja a los vijes\n");
        printf("5.- Listar los datos de la agencia\n");
        printf("6.- Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cl_temp = alta_cliente(cl_temp);
            L = l_cliente_insertar_ordenado(L,cl_temp);

            break;
        case 2:
            l_cliente_borrar(L,L);

            break;
        case 3:
            L = alta_viaje(L,vj_temp);
            break;
        case 4:
            l_viaje_borrar(L,L);
            break;
        case 5:
            l_cliente_mostrar(L);
            break;

        default :
            printf("ERROR\n");
            break;
        }
    }while(opcion != 6);

}
