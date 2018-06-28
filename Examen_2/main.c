#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "destinatarios.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{

    ArrayList* listaDestinatarios = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    EDestinatario* auxiliarDestinatario;
    int i;
    int index;
    int index2;
    char archDest[50];

    printf("ingrese nombre del archivo destinatario\n");
    scanf("%s", archDest);
    printf("%s",archDest);

    parserEmployee(archDest,listaDestinatarios);
    parserEmployee("black_list.csv",listaNegra);

    printf("\n%d\n",listaDestinatarios->reservedSize);
    printf("\n%d\n",listaDestinatarios->size);

    //elimino los repetidos
    for(i=0; i < al_len(listaDestinatarios);i++)
    {

        auxiliarDestinatario = al_get(listaDestinatarios,i);
        index = al_indexOfElement(listaDestinatarios, auxiliarDestinatario, comparoDest, 0);
        do
        {
            index2 = al_indexOfElement(listaDestinatarios, auxiliarDestinatario, comparoDest, index+1);
            if(index2 != -1)
                al_remove(listaDestinatarios, index);
        }while(index2 != -1);
    }

    //elimino los que estan en lista negra
    for(i=0; i < al_len(listaNegra);i++)
    {
        auxiliarDestinatario = al_get(listaNegra,i);

        index = al_indexOfElement(listaDestinatarios, auxiliarDestinatario, comparoDest, 0);

        al_remove(listaDestinatarios, index);
    }

    /*
    al_sort(listaDestinatarios,comparoDest,1);
    for(i=0; i < al_len(listaDestinatarios);i++)
    {
        auxiliarDestinatario = al_get(listaDestinatarios,i);
        destinatario_print(auxiliarDestinatario);
    }

    printf("\n%d\n",listaDestinatarios->reservedSize);
    printf("\n%d\n",listaDestinatarios->size);
    printf("\n------------------------------------------\n");

*/


    al_sort(listaDestinatarios,comparoDest,1);
    for(i=0; i < al_len(listaDestinatarios);i++)
    {
        auxiliarDestinatario = al_get(listaDestinatarios,i);
        destinatario_print(auxiliarDestinatario);
    }
/*
    al_deleteArrayList(listaNegra);
    destinatario_delete(auxiliarDestinatario);
    resizeDown(listaDestinatarios);
    printf("\n------------------------------------------\n");
    for(i=0; i < al_len(listaDestinatarios);i++)
    {
        auxiliarDestinatario = al_get(listaDestinatarios,i);
        destinatario_print(auxiliarDestinatario);
    }
*/
    printf("\n%d\n",listaDestinatarios->reservedSize);
    printf("\n%d\n",listaDestinatarios->size);

    printf("ariel");



    return 0;
}
