#include<stdio.h>
#include<stdlib.h>
#include "lib.h"
#include "lista_circular_simple.h"
/*
void aregarNodoCircuar(NodoCircular **lista,Cliente client){
    NodoCircular *nodo = (NodoCircular*)malloc(sizeof(NodoCircular));
    nodo->cliente = client;
    Si esta vacia incertamos al inicio si no lo incertamos a continuacion

    if(*lista != NULL){
        nodo->next =(*lista)->next;
        (*lista)->next = nodo;
    }else
        *lista  = nodo;
}
*/

/*Elimina un nodo de la lista circular por busqueda*/
void eliminarCircularPorBusqueda(NodoCircular **lista, int id){
    NodoCircular *nodo = *lista;
    do{
        if((*lista)->next->cliente.id != id)
            *lista = (*lista)->next;
    }while((*lista)->next->cliente.id != id && *lista !=nodo);
    if((*lista)->next->cliente.id == id){
        if(*lista == (*lista)->next){
            *lista = NULL;
            free(*lista);
        }else{
            nodo = (*lista)->next;
            (*lista)->next = nodo->next;
            free(nodo);
        }
    }
}
/*Genera nodo para la lista circular*/
NodoCircular *agregarNodoCircular(Cliente client){
    NodoCircular *nodo =(NodoCircular*)malloc(sizeof(NodoCircular));
    nodo->cliente = client;
    nodo->next =NULL;
    return  nodo;
}

/*Carga ordenada lista circular*/
void CargarOrdenadoCircular(NodoCircular **lista,Cliente client){
    NodoCircular *nodo = agregarNodoCircular(client);
    if((*lista)){
        NodoCircular *aux = *lista;
        if((*lista)->cliente.id > nodo->cliente.id){
            while(aux->next != *lista)
                aux = aux->next;
            if(aux->next = *lista){
                nodo->next = *lista;
                aux->next = nodo;
            }else{
                nodo->next = aux->next;
                aux->next = nodo;
            }
        }

    }else{
        *lista = nodo;
        (*lista)->next = nodo;
    }
}

/*Elimina Toda la lista circular*/
void EliminarListaCircular(NodoCircular **lista){
    NodoCircular *nodo;
    while((*lista)->next != *lista){
        nodo = (*lista)->next;
        free(nodo);
    }
    free(*lista);
    *lista = NULL;
}

/*Muestra en pantalla la lista circular*/
void mostrarListaCirular(NodoCircular *lista){
    NodoCircular *nodo= lista;
    do{
        mostrarCliente(nodo->cliente);
        nodo = nodo->next;
    }while(nodo != lista);
}

/*Levanta los datos desde un archivo txt y los guarda en la lista*/
void cargarCircularTxt(NodoCircular **lista){
    FILE *f = fopen("clientes.txt","r");
    if(f){
        Cliente client;
        while(fscanf(f,"%d %f %d %d %d %s",&client.id,&client.venta,&client.fecha.dd,&client.fecha.mm,&client.fecha.yy,client.apynom) == 6){
            CargarOrdenadoCircular(lista,client);
        }
    }else
        printf("Ocurrio un problema al cargar los datos\n");
    fclose(f);
}

/*Guarda los datos de la lista en un fichero txt*/
void guardarDatosCircular(NodoCircular **lista){
    FILE *p = fopen("clientes.txt","w");
    NodoCircular *aux = *lista;
    if( *lista && p){
        do{
            fprintf(p,"%d %s %f %d %d %d",aux->cliente.id,aux->cliente.apynom,aux->cliente.venta,aux->cliente.fecha.dd,aux->cliente.fecha.mm,aux->cliente.fecha.yy);
            aux  = aux->next;
        }while( aux !=*lista);
    }else
        printf("Ocurrio un error al guardar los datos");
    fclose(p);
}


