#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED

typedef struct arco
{
    int distancia;
    struct arco *sgte;
    struct nodo *apunta;

} ARCO, *P_ARCO;

typedef struct nodo
{
    char *nombre_ciudad;
    struct nodo *sgte;
    struct arco *apunta;

} NODO, *P_NODO;


P_NODO buscar_grafo(P_NODO n, char *nombre_ciudad);
P_NODO nuevo(P_NODO n, char *nombre_ciudad);
void listarNodos(P_NODO n);
void arco(P_NODO origen, P_NODO destino, int distancia);
P_NODO cargar(P_NODO n, P_NODO aux_origen, P_NODO aux_destino);


#endif // GRAFOS_H_INCLUDED
