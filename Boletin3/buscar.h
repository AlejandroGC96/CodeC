#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED
#include "clientes.h"
void mostrar(Nodo_clientes *Lista_clientes);
Nodo_clientes *buscar_cliente(Nodo_clientes* Lista_clientes, char *nombre);
#endif // BUSCAR_H_INCLUDED
