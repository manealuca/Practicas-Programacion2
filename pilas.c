#include <stdio.h>
#include<stdlib.h>
#include "lib.h"
#include "pilas.h"


void apilar(Pila *pila, Cliente client){
    Nodo *nodo = agregarNodo(client);
    nodo->next = pila->head;
    pila->head = nodo;
    pila->elementos++;
}

Cliente desapilar(Pila *pila){
    if(pila->head){
        Cliente client = pila->head->cliente;
        Nodo *target = pila->head;
        pila->head = pila->head->next;
        destruirNodoPila(target);
        pila->elementos--;
        return client;
    }
    return;
}

Cliente Head(Pila *pila){
    if(pila->head == NULL)
        return;
    else
        return pila->head->cliente;
}

void destruirNodoPila(Nodo *nodo){
    nodo->next = NULL;
    free(nodo);
}

Pila *generarPila(){
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->head = NULL;
    pila->elementos = 0;
    return pila;
}

void destruirPila(Pila *pila){
    while(pila->head)
        desapilar(pila);
    free(pila);
}

int longPila(Pila *pila){
    return pila->elementos;
}

int pilaVacia(Pila *pila){
    return  pila->elementos == 0;
}
