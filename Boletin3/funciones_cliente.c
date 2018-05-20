#include "estructuras.h"
#include "funciones_cliente_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo_cliente* l_cliente_crear(void)
{
   return NULL;
}

void l_cliente_mostrar (struct nodo_cliente *l)
{
    struct nodo_cliente *paux;    /*El último elemento de la lista es NULL.*/
    paux = l;
    while (paux != NULL) //si el primer nodo de la lista del cliente esta usado, pasa al siguiente nodo
    {
        mostrar_cliente(paux->cl);
        if (l_cliente_num_viajes(paux->cl) > 0) l_viaje_mostrar(paux->cl->v);
        paux = paux->psig;
    }
}



struct nodo_cliente* l_cliente_insertar_ordenado(struct nodo_cliente *l, struct cliente *cl)
{
    struct nodo_cliente *paux_1, *paux_2;
    struct nodo_cliente *paux_v;
    paux_1 = l;
    if (l != NULL)
    {
        while ((paux_1->psig != NULL) && (strcmp(cl->nombre, paux_1->cl->nombre) <= 0))
            {
                paux_2 = paux_1;
                paux_1 = paux_1->psig;
            }
    }

    paux_v = (struct nodo_cliente *) malloc(sizeof (struct nodo_cliente));

    if (paux_v != NULL) {

        paux_v->cl = cl;
        paux_v->cl->v = l_viaje_crear();
        paux_v->cl->contador_viajes = 0;

        if (l == NULL) {
            paux_v->psig = NULL;
            l = paux_v;
        }
        else {
                if (strcmp(cl->nombre,paux_1->cl->nombre) <=0)
                {
                    if (paux_1 == l)
                    {
                        paux_v->psig = paux_1;
                        l = paux_v;
                    }
                    else
                    {
                        paux_2->psig = paux_v;
                        paux_v->psig = paux_1;
                    }
                }
                else
                {
                    paux_v->psig = paux_1->psig;
                    paux_1->psig = paux_v;
                }
        }
    }
    return(l);
}


struct nodo_cliente* l_cliente_primero(struct nodo_cliente *l)
{
    return (l);
}


struct nodo_cliente* l_cliente_ultimo(struct nodo_cliente *l)
{
    struct nodo_cliente *paux;    /*El último elemento de la lista es NULL.*/
    paux = l;
    while (paux != NULL)
        paux = paux->psig;
    return (paux);
}


struct nodo_cliente* l_cliente_siguiente(struct nodo_cliente *l, struct nodo_cliente *pindice)
{ //salta al siguiente nodo de la lista
    return (pindice->psig);
}

struct nodo_cliente* l_cliente_anterior(struct nodo_cliente *l, struct nodo_cliente *pindice)
{
    struct nodo_cliente *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
}

int l_cliente_longitud(struct nodo_cliente *l)
{
    int contador;
    struct nodo_cliente *paux;
    paux = l;
    contador = 1;
    if (paux == NULL) system("PAUSE");
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
}

struct cliente* Obtener(Lista_cliente L, char *dni){

 if(L == NULL){

    return NULL;


 }
 else {


struct nodo_cliente *puntero = L;

while(puntero->psig != NULL)

if(strcmp(dni, puntero->cl->dni)==0){

    return puntero;

}

return L;

 }

}


struct nodo_cliente* l_cliente_localizar(struct nodo_cliente *l, const int posicion)
{

}

struct nodo_cliente* l_cliente_localizar_viaje (struct nodo_cliente *l, char *t_l)
{
    struct nodo_cliente* paux;
    paux = l;
    while ( (strcmp(paux->cl->dni,t_l) != 0) && (paux != NULL) ) {
        paux = paux->psig;
    }
    if (strcmp(paux->cl->dni,t_l) == 0) (paux->cl->contador_viajes)++;
    return (paux);
}


struct cliente *l_cliente_elemento(struct nodo_cliente *l, struct nodo_cliente *pindice)
{
    return (pindice->cl);
}

void l_cliente_borrar(struct nodo_cliente *l, struct nodo_cliente *pindice)
{
    struct nodo_cliente *eliminado;
    char *dni;
    dni = malloc(150*sizeof(char));
    printf("Introduce el DNI del cliente que quieres eliminar \n");
    scanf("%s",&dni);
    fflush(stdin);
    eliminado = Obtener(l, dni);
    EliminarElemento( eliminado, l);
}


int EliminarElemento(struct nodo_cliente *Elemento, struct nodo_cliente *l)
{
    struct nodo_cliente *Auxiliar;
    Auxiliar = l;
    while (Auxiliar != NULL)
    {
        if (Auxiliar == Elemento)
        {
            break;
        }
        Auxiliar = Auxiliar->psig;
    }
    if (Auxiliar == NULL)
    {
        return 0;
    }
    else
    {
        if (Elemento->psig == NULL)
        {
            Auxiliar->psig = NULL;
        }
        else
        {
            Auxiliar->psig = Elemento->psig;
        }

        free(Elemento);
        return 1;
    }

}
void l_cliente_destruir (struct nodo_cliente *l)
{
free(l);
}

int l_cliente_num_viajes (struct nodo_cliente *l)
{
    return (l->cl->contador_viajes);
}

