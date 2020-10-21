#include <stdio.h>
#include <stdlib.h>
#include"lib.h"
#include"listas.h"
#include"lista_doble.h"
int main()
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
    /*printf("%d",obtener_nodo(head,datoClave())->cliente.id);
    */
}

