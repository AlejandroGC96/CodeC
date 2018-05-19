#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"


void mostrar(Nodo_clientes *Lista_clientes)
{

    Nodo_clientes *p,*v;
    p=Lista_clientes;
    v=Lista_clientes;
    while(p != NULL)
    {

        printf("-------------------------\n");
        printf(" DNI : %s\n",p->clientes->dni);
        printf(" Nombre : %s\n", p->clientes->nombre);
        printf(" Apellidos : %s\n", p->clientes->apellidos);
        printf(" Direccion : %s\n", p->clientes->direccion);
        printf("-------------------------\n");

        if(p->clientes->viajes != NULL)
        {

            v=p;

            while(v->clientes->viajes->siguiente != NULL)
            {
                printf("\t-------------------------\n");
                printf("\t ID : %s\n",v->clientes->viajes->viajes->id);
                printf("\t Ciudad : %s\n", v->clientes->viajes->viajes->ciudad_destino);
                printf("\t Hotel : %s\n", v->clientes->viajes->viajes->hotel);
                printf("\t Noches : %s\n", v->clientes->viajes->viajes->noches);
                printf("\t  Precio alojamiento: %s\n", v->clientes->viajes->viajes->precio_alojamiento);
                printf("\t  Tranporte: %s\n", v->clientes->viajes->viajes->transporte);
                printf("\t  Precio desplazamiento: %s\n", v->clientes->viajes->viajes->precio_desplazamiento);
                printf("\t-------------------------\n");

                v = v->clientes->viajes->siguiente;
            }
        }
        p = p->siguiente;

    }


}
Nodo* buscar_cliente(Nodo_clientes* Lista_clientes, char *nombre)//Return el valor de la posicion del cliente que estamos buscando
{
    Nodo_clientes *p;
    p=Lista_clientes;
    while (p != NULL){


        if(strcmp(p->clientes->dni, dni)==0){

         return p;

        }
    p = p->siguiente;


    }
    return p;
}
