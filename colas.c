#include"colas.h"
int estallenaest(ColaEst cola){
    return(((cola.first>cola.last)&&((cola.first-cola.last)==1))||((cola.fist<cola.last)&&(cola.last-cola-first) == MAX-1));
}
/*
Cliente encolarEstatico(ColaEst *cola, Cliente client){
    if(!estallenaest(*cola)){
        if((*cola).last == (MAX-1=));
            (*cola).last
        }
}
*/
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
