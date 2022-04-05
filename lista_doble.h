#ifndef LISTA_DOBLE_H_INCLUDED_
#define LISTA_DOBLE_H_INCLUDED_
void eliminar_nodo_doble(Cab *lista);
DobleNodo *obtener_nodo(Cab **lista, int idx);
int imprimir_lista(Cab *lista);
int obtener_indice(Cab *lista, int idx);
void *ordenar_lista(Cab *lista);
DobleNodo *nuevoDobleNodo(Cliente client);
Cab *iniciarCabecera();

#endif // LISTA_DOBLE_H_INCLUDED_
