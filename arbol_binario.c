#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "arbol_binario.h"

/*GeneraNodo Para el arbol*/
NodoA* agregarNodoA(Cliente client,NodoA *father){
    NodoA *nod = (NodoA*)malloc(sizeof(NodoA));
    nod->cliente = client;
    nod->left = NULL;
    nod->right = NULL;
    nod->father = father;
    return nod;
}


/* INICIALIZACION DE UN ARBOL NodoA *arbol = NULL*/
void inicializarArbol(NodoA ** arbol){
    *arbol = NULL;
}
/*Incerta un nodo en el arbol*/
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

/*inicia el proceso recursivo  llamando a la funcion estatica incertarConPadre*/
void IncertarNodoA(NodoA **arbol, Cliente client){
    incertarConPadre(arbol, NULL, client);
}

/*si el elmento buscado existe en el arbol devuelve si no devuelve 0*/
int Existe(NodoA *arbol, Cliente client){
    if(arbol== NULL) return 0;

    else if(arbol->cliente.id == client.id) return 1;
    else if(arbol->cliente.id < client.id) return Existe(arbol->left, client);
    else return Existe(arbol->right, client);
}

/*Determina la existencia de un valor dentro de el arbol*/
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
/*Busca un nodo especifico para operar con el mismo*/
NodoA *ObtenerNodoA(NodoA *arbol, Cliente client){
    if(arbol ==  NULL) return NULL;
    else if(arbol->cliente.id == client.id) return arbol;
    else if(client.id < arbol->cliente.id) return ObtenerNodoA(arbol->left, client);
    else return ObtenerNodoA(arbol->right,client);
}
/*Recorrido in-order*/
void inOrder(NodoA *arbol){
    if(arbol == NULL) printf(" - ");
    else{
        printf("(");inOrder(arbol->left);
        mostrarCliente(arbol->cliente);
        inOrder(arbol->right);printf(")");
    }
}

/*Recorrido psot-order*/
void postOrder(NodoA *arbol){
    if(arbol == NULL) printf("-");
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

/*Reemplaza un nodo del arbol*/
static void ReplaceNA(NodoA *arbol,NodoA *newnod){
    if(arbol->father){
        /*Colocamos en el padre del nodo el nodo nuevo como hijo */
        if(arbol->cliente.id == arbol->father->cliente.id) arbol->father->left = newnod;
        else if(arbol->cliente.id == arbol->father->right->cliente.id) arbol->father->right = newnod;
    }
    if(newnod){
        /*Colocamos arbol->father como el padre de newnod*/
        newnod->father->right = arbol->father;
    }
}
/*Revisa que sea el valor minimo del sub arbol*/
static NodoA* Minimo(NodoA* arbol){
    if(arbol == NULL)
        return NULL;
    if(arbol->left) return Minimo(arbol->left);

    else return arbol;
}

/*Elimina el nodo y llama a ReplaceNA para reestructurar el arbol*/
static void EliminarNodoA(NodoA *target){
    if(target->left && target->right){
        /*Si tiene 2 hijos*/
        NodoA *minimo = Minimo(target->right);
        target->cliente = minimo->cliente;
        EliminarNodoA(minimo);
    }else if(target->left){
        /*Si tiene un hijo a la izquierda*/
        ReplaceNA(target,target->left);
        DestruirNodoA(target);
    }else if(target->right){
        /*Si tiene un hijo a la derecha*/
        ReplaceNA(target,target->left);
        DestruirNodoA(target);
    }else{
        /*Si no tiene ningun hijo(una hoja)*/
        ReplaceNA(target,NULL);
        DestruirNodoA(target);
    }
}

/*Ubica el nodo a eliminar y llama a la funcion EliminarNodoA*/
void Eliminar(NodoA *arbol, Cliente client){
    if(arbol == NULL) return;
    else if(client.id < arbol->cliente.id) Eliminar(arbol->left, client);
    else if(client.id >arbol->right->cliente.id) Eliminar(arbol->right,client);
    else EliminarNodoA(arbol);
}

/*Ejemplo de incercion No recursivo de un arbol binario*/
void incertarArbolNoRecursivo(NodoA **arbol, Cliente client){
    NodoA *aux =agregarNodoA(client,*arbol);
    if(*arbol == NULL) *arbol = aux;
    else{
        NodoA *nodprev, *nod;
        nod = *arbol;
        nodprev = NULL;

        while(nod){
            nodprev = nod;
            if(client.id<= nod->cliente.id) nod =nod->left;
            else nod = nod->right;
        }
        if(client.id<= nod->cliente.id) nodprev->left = aux;
        else nodprev->right = aux;
    }
}
