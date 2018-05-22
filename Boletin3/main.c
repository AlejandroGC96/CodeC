#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include "estructuras.h"
#include "funciones_cliente.h"
#include "funciones_cliente_auxiliares.h"
#include "funciones_viajes.h"
#include "funciones_viajes_auxiliares.h"
=======
#include "structs.h"
#include "cliente.h"
#include "viaje.h"
#include "imprimir.h"

tcliente *lista=NULL;
>>>>>>> 76918aa32e32237eaa746aa94e69057a0ba4f4d3

int main()
{
    int condicion;
    do{
<<<<<<< HEAD
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
=======
        system("cls");
        printf("**********************************************\n");
        printf("\t\tMENU PRINCIPAL\n");
        printf("**********************************************\n");
        printf("\n1. Dar de alta nuevo cliente");
        printf("\n2. Dar de alta nuevo viaje");
        printf("\n3. Borrar Viaje");
        printf("\n4. Borrar cliente");
        printf("\n5. Listar clientes y viajes");
        printf("\n6. Salir");
        printf("\nEscoger opcion\n");
        fflush(stdin);
        scanf("%d", &condicion);

        switch (condicion){
            case 1:
                alta_cliente();
                system("pause");
                break;
            case 2:
                alta_viaje();
                system("pause");
                break;
            case 3:
                borraviaje();
                system("pause");
                break;
            case 4:
                borracliente();
                system("pause");
                break;
            case 5:
                imprimir();
                system("pause");
                break;

            default:
                break;
>>>>>>> 76918aa32e32237eaa746aa94e69057a0ba4f4d3
        }
    }while(condicion!=6);

    return (EXIT_SUCCESS);
}

