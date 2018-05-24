#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct nodo_arbol
{
    char *nombre;
    int numero;
    struct nodo_arbol *izq;
    struct nodo_arbol *der;

}NODO_ARBOL, *P_NODO_ARBOL;


#endif // ARBOL_H_INCLUDED
