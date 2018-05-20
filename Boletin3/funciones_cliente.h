#ifndef FUNCIONES_CLIENTE_H
#define FUNCIONES_CLIENTE_H

#include "estructuras.h"

struct nodo_cliente* l_cliente_crear(void);
struct nodo_cliente* l_cliente_insertar_ordenado(struct nodo_cliente *l, struct cliente *n);
struct nodo_cliente* l_cliente_primero(struct nodo_cliente *l);
struct nodo_cliente* l_cliente_ultimo(struct nodo_cliente *l);
struct nodo_cliente* l_cliente_siguiente(struct nodo_cliente *l, struct nodo_cliente *pindice);
struct nodo_cliente* l_cliente_anterior(struct nodo_cliente *l, struct nodo_cliente *pindice);
int l_cliente_longitud(struct nodo_cliente *l);
struct nodo_cliente* l_cliente_localizar(struct nodo_cliente *l, const int posicion);
struct cliente *l_cliente_elemento(struct nodo_cliente *l, struct nodo_cliente *pindice);
void l_cliente_borrar(struct nodo_cliente *l, struct nodo_cliente *pindice);
void l_cliente_destruir (struct nodo_cliente *l);
struct nodo_cliente* l_cliente_localizar_viaje (struct nodo_cliente *l, char *);
int l_cliente_num_viajes (struct nodo_cliente *l);

#endif // FUNCIONES_CATALOGO_H
