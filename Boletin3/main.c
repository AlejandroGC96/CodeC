#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cliente.h"
#include "viaje.h"
#include "imprimir.h"

tcliente *lista=NULL;

int main()
{
    int condicion;
    do{
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
        }
    }while(condicion!=6);

    return (EXIT_SUCCESS);
}

