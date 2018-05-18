#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct cliente{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;

}clientes;

typedef struct Nodo{

    clientes *clientes;
    struct Nodo* siguiente;

}Nodo;

typedef struct Lista{

    Nodo* cabeza;
    int longitud;

}Lista;
#endif // CLIENTES_H_INCLUDED
