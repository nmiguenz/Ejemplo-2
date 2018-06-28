#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "destinatarios.h"


static int isValidName(char* name);
static int isValidEmail(char* email);


EDestinatario* destinatario_new(void)
{
    EDestinatario* returnAux = (EDestinatario*) malloc(sizeof(EDestinatario));
    return returnAux;
}


EDestinatario* destinatario_newParametros(char* name, char* email)
{
    EDestinatario* this = destinatario_new();
    if( !destinatario_setName(this,name) &&
        !destinatario_setEmail(this,email))
    {
        return this;
    }
    destinatario_delete(this);
    return NULL;
}


int destinatario_delete(EDestinatario* this)
{
    if(this != NULL)
    {
        free(this);
        return 0;
    }
    return -1;
}


//---------------------------------------------------------------


int destinatario_setName(EDestinatario* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}


int destinatario_getName(EDestinatario* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}


int destinatario_setEmail(EDestinatario* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email,email);
    }
    return retorno;
}


int destinatario_getEmail(EDestinatario* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email,this->email);
    }
    return retorno;
}


//---------------------------------------------------------------


static int isValidName(char* name)
{
    return 1;
}


static int isValidEmail(char* email)
{
    return 1;
}


//---------------------------------------------------------------


int destinatario_print(EDestinatario* this)
{
    char name[51];
    char email[101];
    if(this != NULL)
    {
        destinatario_getName(this,name);
        destinatario_getEmail(this,email);
        fprintf(stdout,"\nNombre: %s - Email: %s",name,email);
        return 0;
    }
    return -1;
}


int comparoDest(void* el0, void* el1)
{
    char mail0[4096];
    char mail1[4096];

    EDestinatario* el0Dest = (EDestinatario*)el0;
    EDestinatario* el1Dest = (EDestinatario*)el1;

    if(mail0 != NULL && mail1 != NULL)
    {
        destinatario_getEmail(el0Dest, mail0);
        destinatario_getEmail(el1Dest, mail1);
        return strcmp(mail0, mail1);
    }
}


/*
int employee_compare(Employee* pEmployeeA,Employee* pEmployeeB)
{
    int idEmployeeA;
    int idEmployeeB;
    int retorno = 0;
    if(pEmployeeA!=NULL && pEmployeeB != NULL)
    {
        employee_getId(pEmployeeA,&idEmployeeA);
        employee_getId(pEmployeeB,&idEmployeeB);
        if(idEmployeeA > idEmployeeB)
        {
            retorno = 1;
        }
        else if(idEmployeeA < idEmployeeB)
        {
            retorno = -1;
        }

    }
    return retorno;

}
*/
