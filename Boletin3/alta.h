#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED
#include "clientes.h"


Nodo* CrearLista();
Nodo* CrearCliente(clientes* cliente);
void InsertarPrincipio(Lista* lista, clientes* clientes);
void InsertarFinal(Lista* lista, clientes* cliente);
void InsertarDespues(int n, Lista* lista, clientes* clientes);



#endif // ALTA_H_INCLUDED
