#include <stdio.h>
#include <stdlib.h>
#include "alta.h"
#include "cliente.h"
#include "mostrar.h"
#include "mostrar.h"


void menu()
{
    clientes *cliente;
    cliente=malloc(sizeof(clientes));
    int contador_clientes = 0;
    int opcion=0;
    do
    {
        printf("####Menu####\n");
        printf("1.Dar de alta un cliente.\n");
        printf("2.Dar de baja a un cliente\n");
        printf("3.Dar de alta un viaje\n");
        printf("4.Dar de baja a un viaje\n");
        printf("7.Mostrar datos de la agencia.\n");
        printf("8.Salir.\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            cliente = alta_cliente(&contador_clientes, cliente);
            ordenar(cliente, contador_clientes);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 7:
            mostrar(contador_clientes, cliente);
            break;
        default:
            break;





        }
    }
    while(opcion!=8);
}
