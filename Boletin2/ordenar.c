#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alta.h"

int ordenar(char *apellidos, clientes *cliente, int contador){

int i=0;
int j=0;
 for(i=0; i<contador; i++)
                    {
                        if(strcmp(cliente[i].apellidos,apellidos)>0)
                        {
                            for(j=contador; j>=i; j--)
                                cliente[j]=cliente[j-1];

                            return i;
                        }
                    }

return -1;


}
