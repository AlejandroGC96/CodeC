#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct viaje
{
    char *id;
    char *ciudad;
    char *hotel;
    char *noches;
    char *transporte;
    char *precioalo;
    char *preciodes;
};

struct nodo_viaje {
    struct viaje *vj;
    struct nodo_viaje *psig;
};

typedef struct nodo_viaje *Lista_viaje;


struct cliente
{
    char *dni;
    char *nombre;
    char *direccion;
    int contador_viajes;
    Lista_viaje v;
};

struct nodo_cliente {
    struct cliente *cl;
    struct nodo *psig;
};


typedef struct nodo_cliente *Lista_cliente;


#endif // ESTRUCTURAS_H
