#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "clientes.h"


Nodo_clientes* CrearListaClientes();
Nodo_viajes* CrearListaLibros();
void tiempo(char output[]);
clientes *alta_cliente(clientes *cliente);
Nodo_clientes* alta_viajes(Nodo_clientes *Lista_clientes,viajes *viaje);
Nodo_clientes* Insertar_Lista(Nodo_clientes *Lista_clientes,clientes *cliente);
Nodo_viajes* InsertarListaViaje(Nodo_viajes *v, Nodo_viajes *i, viajes *viaje);


#endif // ALTA_H_INCLUDED
