#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"

Nodo_clientes* CrearListaClientes()
{


    return NULL;



}

Nodo_viajes* CrearListaLibros()
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
    p_v->clientes->viajes=CrearListaLibros();
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
Nodo_clientes* alta_libros(Nodo_clientes *Lista_clientes,viajes *viaje){

    Lista_clientes l;

    char *nombre_fichero;
    char *dni;
    char *str;
    char *date;

    int i=0;

    nombre_fichero = malloc(150*sizeof(char));
    dni = malloc(150*sizeof(char));
    str = malloc(3*sizeof(char));
    date = malloc(150*sizeof(char));


    printf("Vamos a introducir un viaje a un cliente\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return l;
    }

    fgets(dni,13,fichero);
    dni[strlen(dni) - 1] = '\0';

    l = buscar_cliente(Nodo_clientes* Lista_clientes, char *nombre)

    if(l==NULL)
    {
        fclose(fichero);
        printf("El cliente no existe.No se ha podido insertar el funcion\n");
        return cliente;

    }
    else
    {
        if((cliente[i].contador_de_viajes > 0))
        {
            cliente[i].viajes = realloc(cliente[i].viajes,(cliente[i].contador_de_viajes+1)*sizeof(viaje));
        }
        if((cliente[i].contador_de_viajes == 0))
        {
            cliente[i].viajes = malloc(sizeof(viaje));
        }
        cliente[i].viajes[cliente[i].contador_de_viajes].id = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].noches = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].hotel = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento = malloc(150*sizeof(char));
        cliente[i].viajes[cliente[i].contador_de_viajes].transporte = malloc(150*sizeof(char));

        tiempo(date);//Empieza a concatenar cadenas para el id
        strcat(dni,"_");
        sprintf(str, "%d", cliente[i].contador_de_viajes);
        strcat(dni,str);
        strcat(dni,"_");
        strcat(dni,date);
        strcat(dni,"\0");

        strcpy(cliente[i].viajes[cliente[i].contador_de_viajes].id, dni);
        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].ciudad_destino) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].hotel,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].hotel[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].hotel) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].noches,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].noches[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].noches) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento,20,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].precio_alojamiento) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].transporte,150,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].transporte[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].transporte) - 1] = '\0';

        fgets(cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento,20,fichero);
        cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento[strlen(cliente[i].viajes[cliente[i].contador_de_viajes].precio_desplazamiento) - 1] = '\0';

        cliente[i].contador_de_viajes++;
        fclose(fichero);

        printf("Viaje creado con exito\n");
        printf("El identificador del viaje es %s\n",dni);

        return l;

    }






}

