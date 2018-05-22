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
    struct viajes *siguiente;
    struct viajes *anterior;


}lviajes;


#endif // VIAJES_H_INCLUDED
