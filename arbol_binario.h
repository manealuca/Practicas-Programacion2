#ifndef ARBOL_BINARIO_H_INCLUDED_
#define ARBOL_BINARIO_H_INCLUDED_
/*
typedef struct nodoA{
    Cliente client;
    struct nodoa *left;
    struct nodo *right;
    struct nodo *father;
}NodoA;

typedef NodoA Arbol;
*/

void postOrder(NodoA *arbol);
void preOrden(NodoA *arbol);
void inOrder(NodoA *arbol);
void determinarExistencia(NodoA *arbol, Cliente client);
void incertarNodoA(NodoA **arbol, Cliente client);
NodoA *agregarNodoA(Cliente client, NodoA *father);
void Eliminar(NodoA *target, Cliente client);
void DestruirNodoA(NodoA *target);

#endif
