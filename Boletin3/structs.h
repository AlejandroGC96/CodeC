#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct pi { // Estructura para la pila
   char *ciudad;
   char *destino;
   struct pi *siguiente;
}tpila;

typedef struct co { // Estructura para la cola
   char *identificador;
   int prioridad;
   struct co *siguiente;
   struct co *anterior;
}tcola;

typedef struct ref_viaje{ // Estructura para los viajes
    char *clave;
    char *identificador;
    char *ciudad;
    char *destino;
    char *hotel;
    int noches;
    int precio;
    struct ref_viaje *siguiente;
    struct ref_viaje *anterior;
}tviaje;

typedef struct cliente { // Estructura para los clientes
    char *clave;
    char *ordclave;
    char *nombre;
    char *dni;
    struct ref_viaje *listaref;
    int contref;
    struct cliente *siguiente;
    struct cliente *anterior;
}tcliente;

#endif
