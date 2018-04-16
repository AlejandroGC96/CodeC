#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alta.h"
// A function to implement bubble sort
void swap(clientes *xp, clientes *yp)
{
    clientes temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(clientes *cliente, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if ((strcmp(cliente[j].apellidos, cliente[j+1].apellidos))>0)
              swap(&cliente[j], &cliente[j+1]);
}

/* Function to print an array */
void printArray(clientes *cliente, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", cliente[i]);
    printf("\n");
}

// Driver program to test above functions

int ordenar(clientes *cliente, int contador){

    //int arr[] = {64, 34, 25, 12, 22, 11, 90};
    //int n = sizeof(cliente)/sizeof(apellidos);
    bubbleSort(cliente, contador);
    //printf("Sorted array: \n");
    //printArray(cliente, contador);
    return 0;
}
