#include<stdio.h>
#include<stdlib.h>
#include "lib.h"
#include "sublista.h"

/*Generamos un subnodo*/
Subnod *agregarSubNodo(Cliente client){
    Subnod *snod = (Subnod*)malloc(sizeof(Subnod));
    snod->next = NULL;
    snod->fecha = client.fecha;
    snod->id = client.id;
    snod->ventas = client.venta;
    return snod;
}
/*Agregamos subnodo ordenado*/
void cargarOrdenadoSublista(Subnod **lista,Cliente cliente){
    Subnod *snod = NULL;
    snod = agregarSubNodo(cliente);
    if(*lista){
        if((*lista)->id < snod->id){
            snod->next = *lista;
            *lista = snod;
        }else{
            Nodo *aux = *lista;
            while(aux->next && (aux->next->id > snod->id))
                aux = aux->next;

            if(aux->next && (aux->next->id == snod->id)){
                printf("\nEl elemento ya se encuentra en la lista\n");
            }
            else{
                if(aux->next && (aux->next->id >  snod->id))
                    snod->next = aux->next;
            }
            aux->next = snod;
        }
    }else
        *lista = snod;
}


/*llenar la sublista  completa desde el nodo de una lista doblemente enlazada*/
void cargarSublistaCompleta(Cab **lista,int id,Nodo **list){
    if(*lista){
        DobleNodo *aux = (*lista)->first;
        while(aux!=NULL){
            if(aux->cliente.id == id){
                cargarOrdenadoSublista(&(*list)->snod,aux->cliente);
            }
            aux = aux->next;
        }
    }else
        printf("Lista vacia no hay datos para cargar\n");
}

/*llenar la sublista  completa desde el nodo de una lista  simple*/
Cliente cargarSublistaArchivo(Nodo **lista,FILE *f){
    if(*lista && f){
        Cliente client;
        while(fscanf(f,"%d %f %s",&client.id, &client.venta, &client.apynom)== 3)
            if(client.id == (*lista)->cliente.id)
                cargarOrdenadoSublista(&((*lista)->snod),client);
            else
                return client;
    }else
        printf("Ocurrio un error al cargar los datos \n");
    return;
}

