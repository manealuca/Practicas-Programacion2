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
int datoClave();
Cliente nuevoCliente();
Cliente cargarCliente();
int validarArchivo(FILE *p);
void incertarPrimero(Nodo **lista);
Cliente nuevoCliente();
void mostrarCliente(Cliente cliente);
#endif // LIB_H_INCLUDED
