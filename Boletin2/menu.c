#include <stdio.h>
#include <stdlib.h>
#include "alta.h"
#include "cliente.h"
#include "mostrar.h"
#include "ordenar.h"
#include "baja.h"

/**
\file menu.c
\brief Archivo con el menú del programa
\author José Maria Mirete Fernandez
\author Alejandro García Cortado
\version 1.0
\date 04/2018
*/


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
        printf("5.Mostrar datos de la agencia.\n");
        printf("6.Salir.\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            cliente = alta_cliente(&contador_clientes, cliente);
            ordenar(cliente, contador_clientes);
            system("pause");
            system("cls");
            break;
        case 2:
            cliente = baja_clientes(&contador_clientes, cliente);
            system("pause");
            system("cls");

            break;
        case 3:
            cliente = alta_viaje(contador_clientes, cliente);
            system("pause");
            system("cls");

            break;
        case 4:
            cliente = baja_viajes(contador_clientes, cliente);
            system("pause");
            system("cls");

            break;
        case 5:
            mostrar(contador_clientes, cliente);
            system("pause");
            system("cls");
            break;
        default:
            break;





        }
    }
    while(opcion!=6);
}
