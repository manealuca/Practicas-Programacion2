#ifndef LISTAS_H_INCLUDED_
#define LISTAS_H_INCLUDED_
void agregarNodo(Nodo**lista, Cliente cliente);
int listSize(Nodo *lista);
void cargarOrdenado(Nodo **lista,Cliente cliente);
Nodo *buscarNodo(Nodo *lista);
void eliminarInicio(Nodo **lista);
int eliminarBusqueda(Nodo **lista ,int id);
void imprimirLista(Nodo *lista);
int datoClave();
void cargarDatos(Nodo **lista);
void guardarDatosDatos(Nodo *lista);
#endif //LISTAS_H_INCLUED_
