#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alta.h"
#include "clientes.h"
#include "buscar.h"
#include <time.h>
#define MAX_CLIENTES 19



void tiempo(char output[])//Calcula el tiempo para el id
{

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d_%m_%y",tlocal);

}
int alta_cliente(int contador_clientes)
{

    char nombre_fichero[150];
    char dni[13];

    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if(contador_clientes<20)
    {
        FILE *fichero;


        if ((fichero = fopen(nombre_fichero, "r")) == NULL)
        {
            fprintf(stderr, "No se puede abrir el fichero\n");
            exit (EXIT_FAILURE);
        }


        fgets(dni,13,fichero);
        dni[strlen(dni) - 1]= '\0';
        if(buscar_cliente(dni)!=-1 && clientes[buscar_cliente(dni)].usuario_en_uso==1)
        {

            printf("Ese cliente ya existe\n");
            return 0;
        }
        strcpy(clientes[contador_clientes].dni,dni);
        fgets(clientes[contador_clientes].nombre,20,fichero);
        clientes[contador_clientes].nombre[strlen(clientes[contador_clientes].nombre) - 1] = '\0';

        fgets(clientes[contador_clientes].apellidos,80,fichero);
        clientes[contador_clientes].apellidos[strlen(clientes[contador_clientes].apellidos) - 1] = '\0';

        fgets(clientes[contador_clientes].direccion,150,fichero);

        clientes[contador_clientes].contador_viajes=0;
        clientes[contador_clientes].usuario_en_uso=1;

        fclose(fichero);
        printf("El cliente se ha dado de alta con exito\n");
        return 1;
    }
    else

        printf("Error.Limite de clientes excedido.\n");
    return 0;
}

void alta_viaje()
{
    char nombre_fichero[150];
    FILE *fichero;
    char dni[128];
    char date[128];
    int i=0;

    printf("Escribre el nombre del fichero que quieres introducir(nombre.txt): \n");
    scanf("%s",nombre_fichero);
    fflush(stdin);

    if ((fichero = fopen(nombre_fichero, "r")) == NULL)
    {
        fprintf(stderr, "No se puede abrir el fichero\n");
        exit (EXIT_FAILURE);
    }
    else
        fgets(dni,13,fichero);
    dni[strlen(dni) - 1] = '\0';

    i=buscar_cliente(dni);


    if(clientes[i].contador_viajes<49)
    {
        if(i!=-1)
        {
            tiempo(date);//Empieza a concatenar cadenas para el id
            strcat(dni,"_");
            char str[3];
            sprintf(str, "%d", clientes[i].contador_viajes);
            strcat(dni,str);
            strcat(dni,"_");
            strcat(dni,date);
            strcat(dni,"\0");

            strcpy(clientes[i].viajes[clientes[i].contador_viajes].id, dni);
            fgets(clientes[i].viajes[clientes[i].contador_viajes].ciudad_destino,80,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].ciudad_destino[strlen(clientes[i].viajes[clientes[i].contador_viajes].ciudad_destino) - 1] = '\0';

            fgets(clientes[i].viajes[clientes[i].contador_viajes].hotel,50,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].hotel[strlen(clientes[i].viajes[clientes[i].contador_viajes].hotel) - 1] = '\0';

            fgets(clientes[i].viajes[clientes[i].contador_viajes].noches,3,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].noches[strlen(clientes[i].viajes[clientes[i].contador_viajes].noches) - 1] = '\0';

            fgets(clientes[i].viajes[clientes[i].contador_viajes].precio_alojamiento,20,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].precio_alojamiento[strlen(clientes[i].viajes[clientes[i].contador_viajes].precio_alojamiento) - 1] = '\0';

            fgets(clientes[i].viajes[clientes[i].contador_viajes].transporte,150,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].transporte[strlen(clientes[i].viajes[clientes[i].contador_viajes].transporte) - 1] = '\0';

            fgets(clientes[i].viajes[clientes[i].contador_viajes].precio_desplazamiento,20,fichero);
            clientes[i].viajes[clientes[i].contador_viajes].precio_desplazamiento[strlen(clientes[i].viajes[clientes[i].contador_viajes].precio_desplazamiento) - 1] = '\0';

            clientes[i].contador_viajes++;
            fclose(fichero);

            printf("Viaje creado con exito\n");
        }
        else
            printf("El cliente asociado no existe\n");
    }
    else
    {

        printf("Error.Limite de clientes excedido.\n");

        fclose(fichero);



    }
}


void imprimir(int contador_clientes)
{

    int i=0;
    int x=0;

    for(; i<MAX_CLIENTES; i++)
    {
        if(clientes[i].usuario_en_uso==1)//Filtra los usuarios eliminados de los que no
        {
            printf("#####Cliente %d#####\n",i+1);
            printf("%s\n",clientes[i].dni);
            printf("%s\n",clientes[i].nombre);
            printf("%s\n",clientes[i].apellidos);
            printf("%s\n",clientes[i].direccion);
            if(clientes[i].contador_viajes>0)
            {

                for(; x<clientes[i].contador_viajes; x++)
                {
                    printf("\t####Viaje %d####\n",x+1);
                    printf("\tID: %s\n",clientes[i].viajes[i].id);
                    printf("\tCiudad de destino: %s\n",clientes[i].viajes[i].ciudad_destino);
                    printf("\tHotel: %s\n",clientes[i].viajes[i].hotel);
                    printf("\tNoches: %s\n",clientes[i].viajes[i].noches);
                    printf("\tPrecio alejamiento: %s\n",clientes[i].viajes[i].precio_alojamiento);
                    printf("\tTransporte: %s\n",clientes[i].viajes[i].transporte);
                    printf("\tPrecio del desplazamiento: %s\n",clientes[i].viajes[i].precio_desplazamiento);
                }
            }
        }



    }



}

