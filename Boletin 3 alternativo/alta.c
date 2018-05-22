#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "clientes.h"
#include"viajes.h"
extern lclientes *lista;


void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

}
int buscar_cliente(char *dni)//Return el valor de la posicion del cliente que estamos buscando
{
    int i=0;
    int comparacion=0;
    while(lista->siguiente != NULL || i==0)
    {
        comparacion=strcmp(dni,lista->dni);
        if( comparacion == 0)
        {
            return i;
        }

    }
    return -1;
}


void alta_cliente()
{


    lclientes  *nuevo, *actual;
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
    nuevo=(lclientes*)malloc(sizeof(lclientes));

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




    actual = lista;

    if (actual)
        while (actual->anterior)
            actual = actual->anterior;

    if (actual==NULL || strcmp(actual->dni, nuevo->dni) > 0)
    {
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        if (actual)
            actual->anterior = nuevo; //Si existe actual es que no es el �ltimo
        if(lista==NULL)
            lista = nuevo;
    }
    else
    {
        while(actual->siguiente && (strcmp(actual->siguiente->dni, nuevo->dni) < 0 || strcmp(actual->siguiente->dni, nuevo->dni) == 0)) //Recorremos la lista hasta el lugar donde queremos insertar
            actual = actual->siguiente;

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;

        if (nuevo->siguiente)
            nuevo->siguiente->anterior = nuevo; //Si existe nuevo-> es que no es el �ltimo
    }
    printf("El cliente ha sido dado de alta con exito\n");
    nuevo->lista_viajes=(lviajes*)malloc(sizeof(lviajes));
    nuevo->lista_viajes = NULL;
    nuevo->contador_viajes=0;
    free(nombre_fichero);
}



void alta_viajes()
{

    lviajes *nuevo, *actual;

    char *nombre_fichero;
    char *dni, *dni2;
    char *str;
    char *date;

    int j=0;

    nombre_fichero = malloc(150*sizeof(char));
    dni = malloc(150*sizeof(char));
    dni2 = malloc(150*sizeof(char));

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
        return ;
    }

    fgets(dni,13,fichero);
    dni[strlen(dni) - 1] = '\0';
    strcpy(dni2, dni);
    if(buscar_cliente(dni)==-1){
            printf("No se encontro el cliente\n");
            return;

    }

    if(lista==NULL)
    {
        fclose(fichero);
        printf("No existen clientes. :)\n");
        return;

    }
    else
    {


        nuevo = (lviajes*)malloc((sizeof(lviajes)));
        nuevo->id = (char *)malloc(150*sizeof(char));
        nuevo->hotel = (char *)malloc(150*sizeof(char));
        nuevo->ciudad_destino = (char *)malloc(150*sizeof(char));
        nuevo->noches = (char *)malloc(150*sizeof(char));
        nuevo->precio_alojamiento = (char *)malloc(150*sizeof(char));
        nuevo->precio_desplazamiento = (char *)malloc(150*sizeof(char));
        nuevo->transporte = (char *)malloc(150*sizeof(char));


        tiempo(date);//Empieza a concatenar cadenas para el id
        strcat(dni,"_");
        sprintf(str, "%d", j);
        strcat(dni,str);
        strcat(dni,"_");
        strcat(dni,date);
        strcat(dni,"\0");

        strcpy(nuevo->id, dni);
        fgets(nuevo->ciudad_destino,150,fichero);
        nuevo->ciudad_destino[strlen(nuevo->ciudad_destino) - 1] = '\0';

        fgets(nuevo->hotel,150,fichero);
        nuevo->hotel[strlen(nuevo->hotel) - 1] = '\0';

        fgets(nuevo->noches,150,fichero);
        nuevo->noches[strlen(nuevo->noches) - 1] = '\0';

        fgets(nuevo->precio_alojamiento,20,fichero);
        nuevo->precio_alojamiento[strlen(nuevo->precio_alojamiento) - 1] = '\0';

        fgets(nuevo->transporte,150,fichero);
        nuevo->transporte[strlen(nuevo->transporte) - 1] = '\0';

        fgets(nuevo->precio_desplazamiento,20,fichero);
        nuevo->precio_desplazamiento[strlen(nuevo->precio_desplazamiento) - 1] = '\0';

        fclose(fichero);

        lclientes *auxiliar;
        auxiliar = lista;//igualamos el puntero auxiliar a la lista

        while (auxiliar->anterior)
            auxiliar = auxiliar->anterior;//Se posiciona al principio de la lista

        while(auxiliar) //Recorre la lista de los clientes en busca de uno que tenga la misma clave que el usuario ha introducido
        {
            if (strcmp(auxiliar->dni, dni2) == 0)
            {
                actual = auxiliar->lista_viajes;//Igualamos puntero actual con el puntero de lista de viajes del cliente
                auxiliar->contador_viajes++;

                if (actual)
                    while (actual->anterior)
                        actual = actual->anterior;//Se posiciona la principio de la lista de viajes

                if (actual==NULL || strcmp(actual->id, nuevo->id) > 0) //Si la lista de viajes esta vacia o el elemento es menor al de la lista se inserta
                {
                    nuevo->siguiente = actual;
                    nuevo->anterior = NULL;
                    if (actual)
                        actual->anterior = nuevo;//Si existe actual, es que no es el ultimo
                    if(auxiliar->lista_viajes == NULL)
                        auxiliar->lista_viajes = nuevo;//Si la lista de viajes esta vacia apuntamos la lista al nuevo
                }
                else
                {
                    while(actual->siguiente && (strcmp(actual->siguiente->id, nuevo->id) < 0 || strcmp(actual->siguiente->id, nuevo->id) == 0))
                        actual = actual->siguiente;

                    nuevo->siguiente = actual->siguiente;
                    actual->siguiente = nuevo;
                    nuevo->anterior = actual;
                    if (nuevo->siguiente)
                        nuevo->siguiente->anterior = nuevo;
                }

                return;
            }
            auxiliar = auxiliar->siguiente;
        }
        auxiliar = auxiliar->siguiente;

        printf("Viaje creado con exito\n");
        printf("El identificador del viaje es %s\n",dni);



    }

}
