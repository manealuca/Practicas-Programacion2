#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"

Cab *iniciarCabecera(){
    Cab *head = (Cab*)malloc(sizeof(Cab));
    head->first = NULL;
    head->last = NULL;
}

DobleNodo *nuevoDobleNodo(Cliente client){
    DobleNodo *aux =(DobleNodo*)malloc(sizeof(DobleNodo));
    aux->cliente = client;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}


void *ordenar_lista(Cab *lista){
    if(lista){
        DobleNodo *pivot = NULL, *current = NULL;
        Cliente  client = lista->first->cliente;
        pivot = lista->first;
        while(pivot != lista->last){
            current = pivot->next;
            while(current != NULL){
                if(pivot->cliente.id >= current->cliente.id){
                    printf("realizando el cambio de variable\n");
                    client = pivot->cliente;
                    pivot->cliente = current->cliente;
                    current->cliente = client;
                }
                current = current->next;
            }
            pivot = pivot->next;
        }
    }
}


int obtener_indice(Cab *lista, int idx){
    if(lista){
        if(idx <= lista->elementos){
            int cont = 1;
            DobleNodo *aux = NULL;
            aux = lista->first;
            while(cont< idx){
                aux = aux->next;
                cont++;
            }
            return cont;
        }else{
            printf("Elemento fuera de rango\n");
            return 0;
        }
        }else{
        printf("lista vacia");
        return 0;
    }
}



imprimir_lista(Cab *lista){
    if(lista){
        DobleNodo *aux = NULL;
        aux = lista->first;
        while(aux !=NULL){
            mostrarCliente(aux->cliente);
            aux = aux->next;
        }
    }else{
        printf("Lista vacia");
    }
}


DobleNodo *obtener_nodo(Cab *lista, int idx){
    if(lista){
        if(idx<= lista->elementos){
            int cont = 1;
            DobleNodo* aux = lista->first;
            while(cont< idx){
                aux = aux->next;
                cont++;
            }
            return aux;
        }else{
            printf("Elemento fuera de rango");
            return NULL;
        }
    }else {
        printf("Lista vacia");
        return NULL;
    }
}


void eliminar_nodo_doble(Cab *lista){
    DobleNodo *actual = (DobleNodo*)malloc(sizeof(DobleNodo));
    DobleNodo *primero =lista->first;
    actual = lista->first;
    DobleNodo *anterior =(DobleNodo*)malloc(sizeof(DobleNodo));
    anterior =NULL;
    int id = 0, encontrado = 0;
    printf("ingrese id\n");scanf("%d",&id);fflush(stdin);

    if(primero != NULL){
        while(actual !=NULL &&encontrado != 1){
            if(actual->cliente.id == id){

                if(actual == lista->first){
                    lista->first = lista->first->next;
                    lista->first->prev = NULL;
                }else if(actual == lista->last){
                    anterior->next = NULL;
                    lista->last
                     = anterior;
                }else{
                    anterior->next = actual->next;
                    actual->next->prev = anterior;
                    printf("DobleNodo eliminado\n");
                    encontrado = 1;
                }
                anterior = actual;
                actual = actual->next;
            }
            if(encontrado == 0){
                printf("Elemento no encontrado\n");
            }else
                free(anterior);
        }
    }else
        printf("\n Lista vacia\n");
}




