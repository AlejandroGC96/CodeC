#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "alta.h"
#include "buscar.h"


void menu(){

Lista_clientes  L;
clientes *cliente;
viajes *viaje;

L=CrearListaClientes();

int opcion=0;

do{
printf("###Menu###\n");
printf("1.Dar de alta a los clientes\n");
printf("2.Dar de baja a los clientes\n");
printf("3.Dar de alta a los viajes\n");
printf("4.Dar de baja a los viajes\n");
printf("5.Listar los datos de la agencia\n");
printf("6.Salir\n");
scanf("%d",&opcion);
fflush(stdin);
switch(opcion){

case 1:
    cliente=alta_cliente(cliente);
    L =Insertar_Lista(L ,cliente);
    break;
case 2:
    break;
case 3:
    L =alta_viajes(L, viaje);
    break;
case 4:
    break;
case 5:
    mostrar(L);
    break;
default:
    break;
}

}while(opcion!=6);

}
