#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"
//genera nodo
void agregarNodo(Nodo**lista, Cliente cliente){
    *lista->snod = NULL;
    *lista->next = NULL;
    strcpy((*lista)->apynom,cliente.apynom);

}
//medir tamanio de la lista
void listSize(Nodo *lista){
    if(lista != NULL){
        int cont = 0;
        while(lista !=NULL){
            cont++;
            lista = lista->next;
        }
        printf("El tamanio de la lista es: %d\n",cont);
    }else
        printf("Lista vacia");
}




void incertarPrimero(Nodo **lista){
    Nodo *nod = (Nodo*)malloc(sizeof(Nodo*));
    agregarNodo(&nod,nuevoCliente());
    nod->next = *lista;
    *lista  = nod;
    (*lista)->next = nod->next;
}




