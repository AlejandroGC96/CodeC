#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "buscar.h"
#include "alta.h"
#include "clientes.h"

extern  lclientes *lista;
void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

}

void insertar_cliente()
{

    lclientes *nuevo, *actual;

    char *nombre_fichero;

    nombre_fichero=malloc(250*sizeof(char));
    printf("Vamos a dar de alta a un cliente.\n");
    printf("Introduce el nombre del fichero:");
    fflush(stdin);
    gets(nombre_fichero);
    FILE *fichero;
    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        return;
    }

    nuevo =(lclientes*)malloc(sizeof(lclientes));

    if(nuevo==NULL){

        printf("Error al reservar memoria\n");
        return ;

    }



    nuevo->dni = malloc(150*sizeof(char));
    nuevo->nombre = malloc(150*sizeof(char));
    nuevo->apellidos = malloc(150*sizeof(char));
    nuevo->direccion = malloc(150*sizeof(char));


    fgets(nuevo->dni,150,fichero);
    nuevo->dni[strlen(nuevo->dni) - 1] = '\0';
    fgets(nuevo->nombre,150,fichero);
    nuevo->nombre[strlen(nuevo->nombre) - 1] = '\0';
    fgets(nuevo->apellidos,150,fichero);
    nuevo->apellidos[strlen(nuevo->apellidos) - 1] = '\0';
    fgets(nuevo->direccion,150,fichero);
    fclose(fichero);

    actual =  lista;

    if(actual)while(actual->anterior)actual = actual->anterior;

        if(actual == NULL || strcmp(actual->dni, nuevo->dni)>0){

            nuevo->siguiente = actual;
            nuevo->anterior = NULL;
            if(actual)actual->anterior = nuevo;
            if(lista == NULL) lista = nuevo;


        }
        else{

            while (actual->siguiente && (strcmp(actual->siguiente->dni, nuevo->dni)<0 || strcmp(actual->siguiente->dni, nuevo->dni)==0))
            nuevo->siguiente = actual->siguiente;

            actual->siguiente=nuevo;
            nuevo->anterior=actual;
           if (nuevo->siguiente) nuevo->siguiente->anterior=nuevo;


        }


        nuevo->listaviajes = (lviajes*)malloc(sizeof(lviajes));
        nuevo->listaviajes = NULL;
        nuevo->contador_viajes=0;






    printf("El cliente %s se a%cadio correctamente al sistema\n", nuevo->nombre,-92);


}

/*

Nodo_clientes* alta_viajes(Lista_clientes L ,viajes *viaje){

    Lista_clientes l, i;

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



    }

    return L;




}
*/
