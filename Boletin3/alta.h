#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "clientes.h"


Nodo_clientes* CrearListaClientes();
Nodo_viajes* CrearListaLibros();
void tiempo(char output[]);
clientes *alta_cliente(clientes *cliente);
Nodo_clientes* alta_viajes(Lista_clientes L,viajes *viaje);
Nodo_clientes* Insertar_Lista(struct Nodo_clientes *Lista_clientes,clientes *cliente);
Nodo_viajes* InsertarListaViaje(struct Nodo_viajes *v, struct Nodo_viajes *i, viajes *viaje);


#endif // ALTA_H_INCLUDED
