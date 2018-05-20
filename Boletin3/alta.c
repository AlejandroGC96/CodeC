#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "buscar.h"
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
void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

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
Nodo_clientes* alta_viajes(Nodo_clientes *Lista_clientes,viajes *viaje){

    Nodo_clientes *l;
    Nodo_viajes *i;
    l=Lista_clientes;

    char *nombre_fichero;
    char *dni;
    char *str;
    char *date;

    int j=0;

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

    l = buscar_cliente(l, dni);

    if(l==NULL)
    {
        fclose(fichero);
        printf("El cliente no existe.No se ha podido insertar el funcion\n");
        return l;

    }
    else
    {


       viaje = (viajes*)malloc((sizeof(viaje)));
       viaje->id = (char *)malloc(150*sizeof(char));
       viaje->hotel = (char *)malloc(150*sizeof(char));
       viaje->ciudad_destino = (char *)malloc(150*sizeof(char));
       viaje->noches = (char *)malloc(150*sizeof(char));
       viaje->precio_alojamiento = (char *)malloc(150*sizeof(char));
       viaje->precio_desplazamiento = (char *)malloc(150*sizeof(char));
       viaje->transporte = (char *)malloc(150*sizeof(char));


        tiempo(date);//Empieza a concatenar cadenas para el id
        strcat(dni,"_");
        sprintf(str, "%d", j);
        strcat(dni,str);
        strcat(dni,"_");
        strcat(dni,date);
        strcat(dni,"\0");

        strcpy(viaje->id, dni);
        fgets(viaje->ciudad_destino,150,fichero);
        viaje->ciudad_destino[strlen(viaje->ciudad_destino) - 1] = '\0';

        fgets(viaje->hotel,150,fichero);
        viaje->hotel[strlen(viaje->hotel) - 1] = '\0';

        fgets(viaje->noches,150,fichero);
        viaje->noches[strlen(viaje->noches) - 1] = '\0';

        fgets(viaje->precio_alojamiento,20,fichero);
        viaje->precio_alojamiento[strlen(viaje->precio_alojamiento) - 1] = '\0';

        fgets(viaje->transporte,150,fichero);
        viaje->transporte[strlen(viaje->transporte) - 1] = '\0';

        fgets(viaje->precio_desplazamiento,20,fichero);
        viaje->precio_desplazamiento[strlen(viaje->precio_desplazamiento) - 1] = '\0';

        fclose(fichero);

        i=l->clientes->viajes;

       l->clientes->viajes= InsertarListaViaje(l->clientes->viajes, i,viaje);



        printf("Viaje creado con exito\n");
        printf("El identificador del viaje es %s\n",dni);

        return l;

    }






}

Nodo_viajes* InsertarListaViaje(Nodo_viajes *v, Nodo_viajes *i, viajes *viaje){


Nodo_viajes *v2;

v2= (Nodo_viajes*)malloc(sizeof(Nodo_viajes));

if( v2 != NULL){


    v2->viajes = viaje;

    if(v==NULL){
        v2->siguiente=NULL;
        v=v2;

    }
    else{
        v2->siguiente = i->siguiente;
        i->siguiente=v;
    }


}

return v;


}

