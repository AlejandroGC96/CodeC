#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

typedef struct viajes
{

    char id[128];
    char ciudad_destino[20];
    char hotel[50];
    char noches[3];
    char transporte[10];
    char precio_alojamiento[20];
    char precio_desplazamiento[20];

} viaje;

#endif // VIAJES_H_INCLUDED
