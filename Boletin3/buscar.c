#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"

extern lclientes *lista;

void mostrar()
{

    if (lista==NULL){

        printf("No hay nada en memoria\n");
        return;
    }

    lclientes *c;
    lviajes *v;
    c=lista;

    while(c->anterior)
        c=c->anterior;




    printf("#########Listado de clientes#########\n");

    while(c != NULL)
    {

        printf("-------------------------\n");
        printf(" DNI : %s\n",c->dni);
        printf(" Nombre : %s\n", c->nombre);
        printf(" Apellidos : %s\n", c->apellidos);
        printf(" Direccion : %s\n", c->direccion);
        printf("-------------------------\n");

        if(c->contador_viajes !=0)
        {

            if(v){
            while(v->anterior)
                v=v->anterior;

            while(v->siguiente != NULL)
            {
                printf("\t-------------------------\n");
                printf("\t ID : %s\n",v->id);
                printf("\t Ciudad : %s\n", v->ciudad_destino);
                printf("\t Hotel : %s\n", v->hotel);
                printf("\t Noches : %s\n", v->noches);
                printf("\t  Precio alojamiento: %s\n", v->precio_alojamiento);
                printf("\t  Tranporte: %s\n", v->transporte);
                printf("\t  Precio desplazamiento: %s\n", v->precio_desplazamiento);
                printf("\t-------------------------\n");

                v = v->siguiente;
            }
        }
        }
        c = c->siguiente;

    }


}
/*Nodo_clientes* buscar_cliente(Nodo_clientes* Lista_clientes, char *dni)//Return el valor de la posicion del cliente que estamos buscando
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
*/
