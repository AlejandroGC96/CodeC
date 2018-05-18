#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"

Nodo_clientes* CrearListaClientes()
{


    return NULL;



}

clientes *alta_cliente(clientes *cliente)
{


    char *nombre_fichero;

    nombre_fichero=malloc(250*sizeof(char));
    cliente=(clientes*)malloc(sizeof(clientes));
    printf("Vamos a dar de alta a un cliente.\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return cliente;
    }
    cliente->dni = malloc(150*sizeof(char));
    cliente->nombre = malloc(150*sizeof(char));
    cliente->apellidos = malloc(150*sizeof(char));
    cliente->direccion = malloc(150*sizeof(char));


    fgets(cliente->dni,150,fichero);
    cliente->dni[strlen(cliente->dni) - 1] = '\0';
    fgets(cliente->nombre,150,fichero);
    cliente->nombre[strlen(cliente->nombre) - 1] = '\0';
    fgets(cliente->apellidos,150,fichero);
    cliente->apellidos[strlen(cliente->apellidos) - 1] = '\0';
    fgets(cliente->direccion,150,fichero);
    fclose(fichero);




    printf("El cliente %s se a%cadio correctamente al sistema\n", cliente->nombre,-92);

    return cliente;

}

Nodo_clientes* Insertar_Lista(Nodo_clientes *Lista_clientes,clientes *cliente)
{


    Nodo_clientes *p1, *p2, *p_v;

    p1=Lista_clientes;


    if(Lista_clientes!=NULL)
    {

while((p1->siguiente != NULL) && (strcmp(cliente->dni,p1->clientes->dni)<=0)){

        p2=p1;
        p1=p1->siguiente;


}

}

p_v=(Nodo_clientes*)malloc(sizeof(clientes));

if(p_v!=NULL){

    p_v->clientes=cliente;
    //p_v->clientes->viajes=CrearListaLibros();
    if(Lista_clientes==NULL){

        p_v->siguiente=NULL;
        Lista_clientes=p_v;

    }
    else {

        if(strcmp(cliente->dni, p1->clientes->dni)<=0){

            if(p1==Lista_clientes){

                p_v->siguiente=p1;
                Lista_clientes=p_v;

            }else{
            p2->siguiente = p_v;
            p1->siguiente=p_v;

            }


        }



    }


}

return Lista_clientes;

}

