#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "clientes.h"

Nodo* CrearCliente(clientes* cliente);
void InsertarPrincipio(Lista* lista, clientes* clientes);
void InsertarFinal(Lista* lista, clientes* cliente);
void InsertarDespues(int n, Lista* lista, clientes* clientes);
Nodo* alta_cliente(Lista* lista, clientes *cliente);



#endif // ALTA_H_INCLUDED
