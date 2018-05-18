#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "alta.h"


void menu(){

Lista lista;
clientes* clientes;
int opcion=0;

lista.cabeza=CrearLista();

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
    break;
case 2:
    break;
case 3:
    break;
case 4:
    break;
case 5:
    break;
default:
    break;
}

}while(opcion!=6);
}
