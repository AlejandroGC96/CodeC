#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "alta.h"
#include "buscar.h"


void menu(){


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
    insertar_cliente();
    break;
case 2:
    break;
case 3:

    break;
case 4:
    break;
case 5:
    mostrar();
    break;
default:
    break;
}

}while(opcion!=6);

}
