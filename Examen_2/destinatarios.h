#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H


struct
{
    int id;
    char name[51];
    char email[101];
}typedef EDestinatario;


EDestinatario* destinatario_new(void);
EDestinatario* destinatario_newParametros(char* name, char* email);
int destinatario_delete(EDestinatario* this);

int destinatario_setName(EDestinatario* this, char* name);
int destinatario_getName(EDestinatario* this, char* name);
int destinatario_setEmail(EDestinatario* this, char* email);
int destinatario_getEmail(EDestinatario* this, char* email);

int destinatario_print(EDestinatario* this);
int comparoDest(void* el0, void* el1);
/*int employee_compare(Employee* pEmployeeA,Employee* pEmployeeB);*/


#endif // _EMPLOYEE_H



