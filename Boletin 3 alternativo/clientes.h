#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct cliente{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;
    int contador_viajes;
    struct viaje *lista_viajes;
    struct cliente *siguiente;
    struct cliente *anterior;

}lclientes;



#endif // CLIENTES_H_INCLUDED
