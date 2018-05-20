#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

typedef struct viajes{

    char *id;
    char *ciudad_destino;
    char *hotel;
    char *noches;
    char *transporte;
    char *precio_alojamiento;
    char *precio_desplazamiento;



}viajes;

typedef struct Nodo_viajes{

    viajes *viajes;
    struct Nodo_viajes *siguiente;

}Nodo_viajes;

typedef struct Nodo_viajes *Lista_viajes;

#endif // VIAJES_H_INCLUDED
