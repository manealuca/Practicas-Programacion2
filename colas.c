#include <stdio.h>
#include<stdlib.h>
#include"colas.h"
#include "lib.h"

/*
Cliente encolarEstatico(ColaEst *cola, Cliente client){
    if(!estallenaest(*cola)){
        if((*cola).last == (MAX-1=));
            (*cola).last
        }
}
*//*
int estallenaest(ColaEst cola){
    return(((cola.first>cola.last)&&((cola.first-cola.last)==1))||((cola.fist<cola.last)&&(cola.last-cola-first) == MAX-1));
}
int vacia(){
    if(root == NULL)
        return 1
    else
        return 0
}


void incertar(Cliente client){
    Cola *nodo = (Cola*)malloc(sizeof)(Cola);
    nodo->cliente = client;
    nodo->next = NULL;
    if(vacia()){
        nodo->last = nodo;
    }else{
        nodo->last->next = nodo;
        last = nodo;
    }
}


Cliente extraer(Cola **cola){
    if(!vacia()){
        Cliente client = (*cola)->cliente;
        Cola nodo = *cola;
        if(*cola == (*cola)->last){
            *cola = NULL;
            last = NULL;
        }else
            *cola = (*cola)->next;
        free(nodo);
        return client;
    }else{
        printf("Cola vacia\n");
        return;
    }
}

void printCola(Cola **cola){
    Cola *aux = *cola;
    while(aux !=NULL){
        mostrarCliente(aux->cliente);
        aux = aux->next;
    }
}

void elimianrCola(Cola **cola){
    Cola *aux = *cola;
    Cola *ptr;
    while(aux !=NULL){
        ptr = aux;
        aux = aux->next;
        free(ptr;)
    }
}

*/

Nodo *agregarNodoCola(Cliente client){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->cliente = client;
    nodo->next = NULL;
    return nodo;
}

void DestruirNodoCola(Nodo *nodo){
    nodo->next = NULL;
    free(nodo);
}



Cola *CrearCola(){
    Cola *cola = (Cola*)malloc(sizeof(Cola));
    cola->first = cola->last = NULL;
    return cola;
}

void Encolar(Cola *cola, Cliente client){
    Nodo *nodo = agregarNodoCola(client);
    if(!cola->first){
        cola->first = nodo;
        cola->last = nodo;
    }else{
        cola->last->next = nodo;
        cola->last = nodo;
    }
}

Cliente Consultar(Cola *cola){
    if(cola->first)
        return cola->first->cliente;
    else
        return;
}


void DestruirCola(Cola *cola){
    while(cola->first){
        ElimianrHead(cola);
    }
    free(cola);
}

Cliente ElimianrHead(Cola *cola){
    if(cola->first){
        Cliente client = cola->first->cliente;
        Nodo *target = cola->first;
        cola->first = cola->first->next;
        DestruirNodoCola(target);
        if(!cola->first)
            cola->last = NULL;
        return client;
    }
    return;
}


