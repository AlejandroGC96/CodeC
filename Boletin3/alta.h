#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "clientes.h"


Nodo_clientes* CrearListaClientes();
Nodo_viajes* CrearListaLibros();
clientes *alta_cliente(clientes *cliente);
Nodo_clientes* alta_libros(Nodo_clientes *Lista_clientes,viajes *viaje);
Nodo_clientes* Insertar_Lista(Nodo_clientes *Lista_clientes,clientes *cliente);


#endif // ALTA_H_INCLUDED
