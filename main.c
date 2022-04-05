#include <stdio.h>
#include <stdlib.h>
#include"lib.h"
#include"listas.h"
#include"lista_doble.h"
#include"lista_circular_simple.h"
#include"sublista.h"
#include "colas.h"
#include "arbol_binario.h"

void main()
{
    iniciarArchivo("clientes.txt");
    Nodo *lista = NULL;
    cargarDatos(&lista);
    imprimirLista(&lista);
    system("pause");system("cls");
    /*Implementacion lista doble*/
    Cab *head = iniciarCabecera();
    cargarDatos2(&head);
    imprimirListaDoble(head);
    system("pause");system("cls");
    DobleNodo *aux = obtener_nodo(&head,2012);
    mostrarCliente(aux->cliente);
    system("pause");system("cls");
    NodoA *tree = NULL;
    IncertarNodoA(&tree,aux->cliente);
    preOrden(tree);

}

