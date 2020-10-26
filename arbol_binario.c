#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "arbol_binario.h"


NodoA* agregarNodoA(Cliente client,NodoA *father){
    NodoA *nod = (NodoA*)malloc(sizeof(NodoA));
    nod->cliente = client;
    nod->left = NULL;
    nod->right = NULL;
    nod->father = father;
    return nod;
}




/* INICIALIZACION DE UN ARBOL NodoA *arbol = NULL*/

static void incertarConPadre(NodoA **arbol,NodoA *father ,Cliente client)
{
    if(*arbol){
        Cliente clientRoot;
        clientRoot = (*arbol)->cliente;
        if(client.id < clientRoot.id)
            incertarConPadre(&(*arbol)->left, *arbol,client);
        else
            incertarConPadre(&(*arbol)->left, *arbol,client);
     }else
        *arbol = agregarNodoA(client, father);
}

/*IncertarNodoA solo inicia el proceso recursivo  llamando a la funcion interna a incertarConPadre*/
void IncertarNodoA(NodoA **arbol, Cliente client){
    incertarConPadre(arbol, NULL, client);
}

int Existe(NodoA *arbol, Cliente client){
    /*si existe en el arbol devuelve si no devuelve 0*/
    if(arbol== NULL) return 0;

    else if(arbol->cliente.id == client.id)
        return 1;
    else if(arbol->cliente.id < client.id)
        return Existe(arbol->left, client);
    else return Existe(arbol->right, client);
}

void DeterminarExistencia(NodoA *arbol,Cliente client){
    if(Existe(arbol,client)) printf("El nodo buscado existe en el arbol\n");
    else printf("El nodo buscado no existe en el arbol\n");
}

/*Recorrido pre-orden*/

void preOrden(NodoA *arbol){
    if(arbol == NULL) printf("-");
    else{
        printf("(");mostrarCliente(arbol->cliente);
        preOrden(arbol->left);
        preOrden(arbol->right);printf(")");
    }
}

NodoA *ObtenerNodoA(NodoA *arbol, Cliente client){
    if(arbol ==  NULL) return NULL;
    else if(arbol->cliente.id == client.id)
        return arbol;
    else if(client.id < arbol->cliente.id)
        return ObtenerNodoA(arbol->left, client);
    else
        return ObtenerNodoA(arbol->right,client);
}

void inOrder(NodoA *arbol){
    if(arbol == NULL)
        printf(" - ");
    else{
        printf("(");inOrder(arbol->left);
        mostrarCliente(arbol->cliente);
        inOrder(arbol->right);printf(")");
    }
}

void postOrder(NodoA *arbol){
    if(arbol == NULL)
        printf("-");
    else{
        printf("(");postOrder(arbol->left);
        mostrarCliente(arbol->cliente);
        postOrder(arbol->right);printf(")");
    }
}


/*Funciones de eliminacion*/
void DestruirNodoA(NodoA *nodo){
    nodo->left = nodo->right = NULL;
    free(nodo);
}

static void Reemplazar(NodoA *arbol,NodoA *newnod){
    if(arbol->father){
        /*Colocamos en el padre de arbol el nodo nuevo como hijo */
        if(arbol->cliente.id == arbol->father->cliente.id)
            arbol->father->left = newnod;
        else if(arbol->cliente.id == arbol->father->right->cliente.id)
            arbol->father->right = newnod;
    }
    if(newnod){
        /*Colocamos arbol->father como el padre de newnod*/
        newnod->father->right = arbol->father;
    }
}

static NodoA* Minimo(NodoA* arbol){
    if(arbol == NULL)
        return NULL;
    if(arbol->left)
        return Minimo(arbol->left);

    else
        return arbol;
}



static void EliminarNodoA(NodoA *target){
    if(target->left && target->right){
        /*Si tiene 2 hijos*/
        NodoA *minimo = Minimo(target->right);
        target->cliente = minimo->cliente;
        EliminarNodoA(minimo);
    }else if(target->left){
        /*Si tiene un hijo a la izquierda*/
        Reemplazar(target,target->left);
        DestruirNodoA(target);
    }else if(target->right){
        /*Si tiene un hijo a la derecha*/
        Reemplazar(target,target->left);
        DestruirNodoA(target);
    }else{
        /*Si no tiene ningun hijo(una hoja)*/
        Reemplazar(target,NULL);
        DestruirNodoA(target);
    }
}

void Eliminar(NodoA *arbol, Cliente client){
    if(arbol == NULL) return;
    else if(client.id < arbol->cliente.id) Eliminar(arbol->left, client);
    else if(client.id >arbol->right->cliente.id) Eliminar(arbol->right,client);
    else EliminarNodoA(arbol);
}
