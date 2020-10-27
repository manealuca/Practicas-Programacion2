#ifndef PILAS_H_INCLUDED_
#define PILAS_H_INCLUDED_
void apilar(Pila *pila, Cliente client);
Cliente desapilar(Pila *pila);
Cliente Head(Pila *pila);
void destruirNodoPila(Nodo *nodo);
Pila *generarPila();
void destruirPila(Pila *pila);
int longPila();
int pilaVacia(Pila *pila);

#endif
