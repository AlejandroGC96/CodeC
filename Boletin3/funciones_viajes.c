#include "estructuras.h"
#include "funciones_viajes_auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
struct nodo_viaje* l_viaje_crear(void)
{
   return NULL;
}

void l_viaje_mostrar (struct nodo_viaje *l)
{
    struct nodo_viaje *paux;    /*El último elemento de la lista es NULL.*/
    paux = l;
    while (paux != NULL)
    {
        mostrar_viaje(paux->vj);
        paux = paux->psig;
    }
}

struct nodo_viaje* l_viaje_insertar(struct nodo_viaje *l, struct nodo_viaje *pindice, struct viaje *vj)
{
    struct nodo_viaje *paux;

    paux = (struct nodo_viaje *) malloc(sizeof (struct nodo_viaje));

    if (paux != NULL) {
        /*INSERTAR EL viaje */
        paux->vj = vj;

        if (l == NULL) {
            paux->psig = NULL;
            l = paux;
        }
        else {
            paux->psig = pindice->psig;
            pindice->psig = paux;
        }
    }
    return(l);
}



struct nodo_viaje* l_viaje_primero(struct nodo_viaje *l)
{
    return (l);
}


struct nodo_viaje* l_viaje_ultimo(struct nodo_viaje *l)
{
    struct nodo_viaje *paux;    /*El último elemento de la lista es NULL.*/
    paux = l;
    while (paux->psig != NULL)
        paux = paux->psig;
    return (paux);
}


struct nodo_viaje* l_viaje_siguiente(struct nodo_viaje *l, struct nodo_viaje *pindice)
{
    return (pindice->psig);
}

struct nodo_viaje* l_viaje_anterior(struct nodo_viaje *l, struct nodo_viaje *pindice)
{
    struct nodo_viaje *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
}

int l_viaje_longitud(struct nodo_viaje *l)
{
    int contador;
    struct nodo_viaje *paux;
    paux = l;
    contador = 1;
    if (paux->psig == NULL)
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
}

struct nodo_viaje* l_viaje_localizar(struct nodo_viaje *l, const int posicion)
{
    struct nodo_viaje* paux;
    int c;
    paux = l;
    c = posicion;
    while ( (c > 1) && (paux->psig != NULL) ) {
        paux = paux->psig;
        c--;
    }
    if(c != 1 ) paux = NULL;
    return (paux);
}


struct viaje *l_viaje_elemento(struct nodo_viaje *l, struct nodo_viaje *pindice)
{
    return (pindice->vj);
}

void l_viaje_borrar(struct nodo_viaje *l, struct nodo_viaje *pindice)
{

    l_viaje_localizar(struct nodo_viaje *l, const int posicion);



}
int l_viaje_longitud(struct nodo_cliente *l)
{
    int contador;
    struct nodo_cliente *paux;
    paux = l;
    contador = 1;
    if (paux == NULL)
    while (paux->cl->v->psig != NULL) {

        contador++;
        paux->cl->v = paux->cl->v->psig;
    }
    return (contador);
}

void l_viaje_destruir (struct nodo_viaje *l)
{
    char *id, *dni;
    int i=0;
    struct nodo_viaje* paux;

    id=malloc(150*sizeof(char));
    dni=malloc(150*sizeof(char));

    printf("Introduce el dni del usuario que quieras eliminar un viaje\n");
    scanf("%s",&dni);
    l=Obtener(l,dni);
    i=l_viaje_longitud(l);
    l=l_viaje_localizar(l,i);
    free(l);






}

