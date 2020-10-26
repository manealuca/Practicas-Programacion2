#ifndef LIB_H_INCLUDED_
#define LIB_H_INCLUDED_


typedef struct fecha{
    int dd;
    int mm;
    int yy;
}Fecha;

typedef struct snod{
    struct snod *next;
    int id;
    float ventas;
    Fecha fecha;
}Subnod;

typedef struct cliente{
    int id;
    float venta;
    char apynom[60];
    Fecha fecha;
}Cliente;

typedef struct nodoA{
    Cliente cliente;
    struct nodoA *left;
    struct nodoA *right;
    struct nodoA *father;
}NodoA;

typedef NodoA Arbol;

typedef struct nodo{
    int id;
    char apynom[60];
    struct nodo *next;
    Cliente cliente;
    Subnod *snod;
}Nodo;

typedef struct doblenodo{
    struct doblenodo *next;
    struct doblenodo *prev;
    Cliente cliente;
}DobleNodo;


typedef struct cab{
    DobleNodo *first;
    DobleNodo *last;
    int elementos;
}Cab;

typedef struct nodocircular{
    struct nodocircular *next;
    Cliente cliente;
}NodoCircular;
/*Auxiliares para operar la lista circualar*/
NodoCircular *circular2;

typedef struct pila{
    Nodo *head;
    int elementos;
}Pila;



int datoClave();
Cliente nuevoCliente();
Cliente cargarCliente();
int validarArchivo(FILE *p);
void incertarPrimero(Nodo **lista);
Cliente nuevoCliente();
void mostrarCliente(Cliente cliente);

#endif
