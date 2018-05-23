#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct nodo_arbol
{
    char *nombre;
    int numero;                       /* Campo donde almacenaremos el valor */
    struct nodo_arbol *izq;    /* Puntero al hijo izquierdo */
    struct nodo_arbol *der;      /* Puntero al hijo derecho */
}NODO_ARBOL, *P_NODO_ARBOL;


#endif // ARBOL_H_INCLUDED
