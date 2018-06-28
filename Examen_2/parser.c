#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "destinatarios.h"


int parserEmployee(char* fileName, ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    char bName[4096];
    char bEmail[4096];
    int parts;
    EDestinatario* auxiliarDestinatario;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            parts = fscanf(pFile,"%[^,],%[^\n]\n",bName,bEmail);
            if(parts==2)
            {
                auxiliarDestinatario = destinatario_newParametros(bName,bEmail);
                al_add(pArrayListEmployee,auxiliarDestinatario);
            }
        }
    }
    fclose(pFile);
    return retorno;
}




