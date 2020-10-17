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
    Fechaa *fecha;
}Cliente;

typedef struct nodo{
    int id;
    char apynom[60];
    struct nodo *next;
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
}Cab;


#endif // LIB_H_INCLUDED
