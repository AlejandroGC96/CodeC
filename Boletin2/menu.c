#include <stdio.h>
#include <stdlib.h>
#include "alta.h"
#include "cliente.h"
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
        printf("1.Dar de alta a los clientes.\n");
        printf("7.Mostrar datos de la agencia.\n");
        printf("8.Salir.\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            alta_cliente(&contador_clientes, cliente);
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
