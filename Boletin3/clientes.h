#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct cliente{

    char *dni;
    char *nombre;
    char *apellidos;
    char *direccion;
    clientes *anterior;
    clientes *posterior;

}clientes;s

#endif // CLIENTES_H_INCLUDED
