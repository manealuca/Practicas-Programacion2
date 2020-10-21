#ifndef LISTA_CIRCULAR_SIMPLE_H_INCLUDE_
#define LISTA_CIRCULAR_SIMPLE_H_INCLUDE_
void eliminarCircularPorBusqueda(NodoCircular **lista, int id);
NodoCircular *agregarNodoCircular(Cliente client);
void CargarOrdenadoCircular(NodoCircular **lista,Cliente client);
void EliminarListaCircular(NodoCircular **lista);
void mostrarListaCirular(NodoCircular *lista);
void cargarCircularTxt(NodoCircular **lista);
void guardarDatosCircular(NodoCircular **lista);

#endif
