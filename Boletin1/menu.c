#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "viajes.h"
#include "alta.h"
#include "menu.h"
#include "buscar.h"
#include "baja.h"
#include "guardar.h"
void menu()
{

    int contador_clientes=0;

    int opcion=0;

    do
    {
        printf("####Indice####\n");
        printf("1. Dar de alta a un usuario\n");
        printf("2. Dar de baja a un usuario\n");
        printf("3. Dar de alta a un nuevo viaje\n");
        printf("4. Eliminar un viaje\n");
        printf("5. Guardar estado del progama\n");
        printf("6. Cargar el estado del fichero\n");
        printf("7. Listar datos de la agencia\n");
        printf("8. Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {

        case 1:

            if(alta_cliente(contador_clientes)==1)
            {

                contador_clientes++;
            }
            system("pause");
            system("cls");
            break;

        case 2:
            if( baja_clientes()==0)
            {
                contador_clientes--;
                system("pause");
                system("cls");
                break;
            }
            else
                break;
        case 3:
            alta_viaje();
            system("pause");
            system("cls");
            break;
        case 4:
            baja_viajes();
            system("pause");
            system("cls");
            break;
        case 5:
            guardar(clientes);

            system("pause");
            system("cls");
            break;
        case 6:
            cargar(clientes);
            system("pause");
            system("cls");
            break;
        case 7:
            imprimir(contador_clientes);
            system("pause");
            system("cls");
            break;
        case 8:
            break;
        default:
            break;





        }

    }
    while(opcion!=8);

}
