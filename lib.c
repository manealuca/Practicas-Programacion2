#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"

void agregarNodo(Nodo**lista, Cliente cliente){
    Nodo *aux = *lista;
    aux->snod = NULL;
    aux->next = NULL;
    strcpy(aux->apynom,cliente.apynom);

}
