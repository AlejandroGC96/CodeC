#ifndef FUNCIONES_VIAJES_H
#define FUNCIONES_VIAJES_H

#include "estructuras.h"

struct nodo_viaje* l_libro_crear(void);
struct nodo_viaje* l_libro_insertar(struct nodo_viaje *l, struct nodo_viaje *pindice, struct viaje *n);
struct nodo_viaje* l_libro_inser_ppo(struct nodo_viaje *l, struct viaje *n);
struct nodo_viaje* l_libro_primero(struct nodo_viaje *l);
struct nodo_viaje* l_libro_ultimo(struct nodo_viaje *l);
struct nodo_viaje* l_libro_siguiente(struct nodo_viaje *l, struct nodo_viaje *pindice);
struct nodo_viaje* l_libro_anterior(struct nodo_viaje *l, struct nodo_viaje *pindice);
int l_viaje_longitud(struct nodo_viaje *l);
struct nodo_viaje* l_libro_localizar(struct nodo_viaje *l, const int posicion);
struct viaje *l_viaje_elemento(struct nodo_viaje *l, struct nodo_viaje *pindice);
void l_viaje_borrar(struct nodo_viaje *l, struct nodo_viaje *pindice);
void l_viaje_destruir (struct nodo_viaje *l);


#endif // FUNCIONES_VIAJE_H
